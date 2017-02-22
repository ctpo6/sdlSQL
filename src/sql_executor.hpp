#ifndef SQL_EXECUTOR_HPP
#define SQL_EXECUTOR_HPP

#include "database_context.hpp"
#include "sql_executor_types.hpp"
#include "types.hpp"

#include "dataserver/system/database.h"

#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>


class SqlExecutor
{
    const DatabaseContext& db_ctx_;
public:
    enum class EmitOp
    {
        AS,
        ASC,
        COMPARISON,
        DESC,
        FIELD,
        FROM,
        JOIN,
        NAME,
        NUMBER,
        OPERATOR,
        ORDER_BY,
        STRING,
        TABLE,
        TOP,
        SELECT,
        SELECT_ALL,
        WHERE,
    };

public:
    explicit SqlExecutor(const DatabaseContext& db_ctx)
        : db_ctx_(db_ctx)
    {}

    void emit(EmitOp op);
    void emit(EmitOp op, int param);
    void emit(EmitOp op, const std::string& param);
    void emit(EmitOp op, const std::string& name1, const std::string& name2);

    int execute();

private:
    enum : uint32_t {
        F_ORDER_BY_DESC = 0x00000001,
        F_HAS_ALIAS = 0x80000000,
    };

    struct EmitRecord
    {
        EmitOp op_;

        int int_;               // for int values
        std::string string_;    // for string values

        // column or table reference: name1_.name2_
        // alias: name2_
        std::string name1_;
        std::string name2_;
    };

    using EmitRecordContainer = std::deque<EmitRecord>;

    EmitRecordContainer emit_;

    static EmitRecord make_emit_record(EmitOp op);
    static EmitRecord make_emit_record(EmitOp op, int param);
    static EmitRecord make_emit_record(EmitOp op, const std::string& param);
    static EmitRecord make_emit_record(EmitOp op,
                                       const std::string& name1,
                                       const std::string& name2);

    // TODO: better name is Identifier
    struct SymbolReference
    {
        std::string t_name; // table or table alias
        std::string c_name; // column or column alias

        // where_expr_tree: idx of entry in ref_table
        size_t idx = static_cast<size_t>(-1);

        uint32_t flags = 0;
    };
    friend std::ostream& operator<<(std::ostream& os,
                                    const SqlExecutor::SymbolReference& r);

    struct ExpressionNode
    {
        // operation or type
        // if node is a leaf, then op is used; otherwise type
        // leaf node has left,right == nullptr; effectively only right must
        // be checked
        union
        {
            ExprOperator op;
            ExprOperandType type;
        } ot;

        sdl::sql::variant<sdl::sql::Value, SymbolReference> value;

        std::unique_ptr<ExpressionNode> left;
        std::unique_ptr<ExpressionNode> right;
    };

    using ExpressionNodePtr = std::unique_ptr<ExpressionNode>;

    static void dump_expr_tree(const ExpressionNode* node);

    struct ColumnRef
    {
        size_t t_idx;   // table
        size_t c_idx;   // column
    };

    struct SelectContext
    {
        int n_top;
        int n_select;

        // if empty -> SELECT *
        std::vector<SymbolReference> select_columns;
        std::map<std::string, size_t> select_column_as;

        // [0] : FROM
        // [1] : JOIN 0
        // ...
        // [N] : JOIN N-1
        std::vector<SymbolReference> from_tables;
        std::map<std::string, size_t> from_table_as;

        std::vector<ExpressionNodePtr> join_expr_tree;

        std::unordered_map<size_t, size_t> table_idx_to_join_pos;

        ExpressionNodePtr where_expr_tree;

        std::vector<SymbolReference> order_by_list;

        std::deque<ColumnRef> ref_table;

        void dump() const;
    };

    SelectContext ctx_;

    using record_access = sdl::db::datatable::record_access;
    using record_iterator = record_access::iterator;

#if 0
    struct ExecutionResult
    {
        std::deque<record_iterator> records;
    };
    ExecutionResult res_;
#endif

    std::deque<std::vector<record_iterator>> eres_;

#if 0
    std::vector<record_iterator> begin_record_it_;
    std::vector<record_iterator> end_record_it_;
    std::vector<record_iterator> cur_record_it_;
#endif

    void execute2();
    bool execute_where(std::vector<record_iterator> const& row);

    void execute_order_by();
    void dump_result();

    /*
     * Only start iterator is really needed, end is for safety check only.
     */
    ExpressionNodePtr build_expr_tree(
            const EmitRecordContainer::const_iterator start,
            const EmitRecordContainer::const_iterator end,
            EmitRecordContainer::const_iterator& out);

    int init_select_context(
            const EmitRecordContainer& em,
            SelectContext& ctx);
    int init_select_context1(
            const EmitRecordContainer& em,
            SelectContext& ctx);

    int init_select_context_from(
            const EmitRecordContainer::const_iterator start,
            const EmitRecordContainer::const_iterator end,
            SelectContext& ctx);
    int init_select_context_from_add_table(
            const EmitRecordContainer::const_iterator start,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);
    int init_select_context_from_add_join(
            const EmitRecordContainer::const_iterator start,
            const EmitRecordContainer::const_iterator end,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);

    int init_select_context_where(
            const EmitRecordContainer::const_iterator start,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);
    int init_select_context_order_by(
            const EmitRecordContainer::const_iterator start,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);

    int check_select_context(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);
    int check_select_context_from_join(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);
    int check_select_context_select(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);
    int check_select_context_where(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);
    int check_select_context_order_by(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);

    /*
     * expr_idx: expression idx in ctx.join_expr_tree
     */
    int check_join_expr(
            const DatabaseContext& db_ctx,
            SelectContext& ctx,
            size_t expr_idx,
            ExpressionNode* node,
            sdl::sql::ValueType& expr_type);

    int check_where_expr(
            const DatabaseContext& db_ctx,
            SelectContext& ctx,
            ExpressionNode* node,
            sdl::sql::ValueType& expr_type);

    int execute_expr(
            std::vector<record_iterator> const& row,
            ExpressionNode* node,
            sdl::sql::Value& value);
};

std::ostream& operator<<(
        std::ostream& os,
        const SqlExecutor::SymbolReference& r);


#endif