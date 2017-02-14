#ifndef SQL_EXECUTOR_HPP
#define SQL_EXECUTOR_HPP

#include "database_context.hpp"
#include "sql_executor_types.hpp"

#include <boost/variant.hpp>

#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <string>


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

    struct SymbolReference
    {
        std::string t_name; // table or table alias
        std::string c_name; // column or column alias

        size_t idx = static_cast<size_t>(-1);

        uint32_t flags = 0;
    };
    friend std::ostream& operator<<(std::ostream& os,
                                    const SqlExecutor::SymbolReference& r);

    struct ExpressionNode
    {
        // operation or type
        union
        {
            ExprOperator op;
            ExprOperandType type;
        } ot;

        boost::variant<int, std::string, SymbolReference> value;

        std::unique_ptr<ExpressionNode> left;
        std::unique_ptr<ExpressionNode> right;
    };

    using ExpressionNodePtr = std::unique_ptr<ExpressionNode>;

    static void dump_expr_tree(const ExpressionNode& node);

    struct SelectContext
    {
        int n_top;
        int n_select;

        // if empty -> SELECT *
        std::vector<SymbolReference> select_columns;
        std::map<std::string, size_t> select_column_as;

        std::vector<SymbolReference> from_tables;
        std::map<std::string, size_t> from_table_as;

        ExpressionNodePtr where_expr_tree;

        std::vector<SymbolReference> order_by_list;

        void dump() const;
    };

    SelectContext ctx_;


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
    int init_select_context2(
            const DatabaseContext& db_ctx,
            SelectContext& ctx);

    int init_select_context_from(
            const EmitRecordContainer::const_iterator start,
            const EmitRecordContainer::const_iterator end,
            SelectContext& ctx);
    int init_select_context_where(
            const EmitRecordContainer::const_iterator start,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);
    int init_select_context_order_by(
            const EmitRecordContainer::const_iterator start,
            EmitRecordContainer::const_iterator& next_part,
            SelectContext& ctx);

    int execute_one();
};

std::ostream& operator<<(
        std::ostream& os,
        const SqlExecutor::SymbolReference& r);


#endif