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

    using ParserCommandContainer = std::deque<ParserCommand>;

public:
    explicit SqlExecutor(const DatabaseContext& db_ctx)
        : db_ctx_(db_ctx)
    {}

    int execute(ParserCommandContainer const& cmd);

private:

    enum : uint32_t {
        F_ORDER_BY_DESC = 0x00000001,
        F_HAS_ALIAS = 0x80000000,
    };

    struct Identifier
    {
        std::string t_name; // table or table alias
        std::string c_name; // column or column alias

        // where_expr_tree: idx of entry in ref_table
        size_t idx = static_cast<size_t>(-1);

        uint32_t flags = 0;
    };
    friend std::ostream& operator<<(std::ostream& os,
                                    const SqlExecutor::Identifier& r);

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

        sdl::sql::variant<sdl::sql::Value, Identifier> value;

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

        std::vector<Identifier> select_columns;
        std::map<std::string, size_t> select_column_as;

        // [0] : FROM
        // [1] : JOIN 0
        // ...
        // [N] : JOIN N-1
        std::vector<Identifier> from_tables;
        std::map<std::string, size_t> from_table_as;

        std::vector<ExpressionNodePtr> join_expr_tree;

        // table idx in db -> table pos in join
        std::unordered_map<size_t, size_t> table_idx_to_join_pos;

        ExpressionNodePtr where_expr_tree;

        std::vector<Identifier> order_by_list;

        std::deque<ColumnRef> ref_table;

        void dump() const;
    };

    SelectContext ctx_;

    using record_access = sdl::db::datatable::record_access;
    using record_iterator = record_access::iterator;

    std::deque<std::vector<record_iterator>> eres_;

    void execute2();
    bool execute_join(std::vector<record_iterator> const& row);
    bool execute_where(std::vector<record_iterator> const& row);
    void execute_order_by();

    void dump_result();

    /*
     * Only start iterator is really needed, end is for safety check only.
     */
    ExpressionNodePtr build_expr_tree(
            const ParserCommandContainer::const_iterator start,
            const ParserCommandContainer::const_iterator end,
            ParserCommandContainer::const_iterator& out);

    int init_select_context(const ParserCommandContainer& cmd);
    int init_select_context1(const ParserCommandContainer& cmd);

    int init_select_context_from(
            const ParserCommandContainer::const_iterator start,
            const ParserCommandContainer::const_iterator end);
    int init_select_context_from_add_table(
            const ParserCommandContainer::const_iterator start,
            ParserCommandContainer::const_iterator& next_part);
    int init_select_context_from_add_join(
            const ParserCommandContainer::const_iterator start,
            const ParserCommandContainer::const_iterator end,
            ParserCommandContainer::const_iterator& next_part);

    int init_select_context_where(
            const ParserCommandContainer::const_iterator start,
            ParserCommandContainer::const_iterator& next_part);
    int init_select_context_order_by(
            const ParserCommandContainer::const_iterator start,
            ParserCommandContainer::const_iterator& next_part);

    int check_select_context();
    int check_select_context_from_join();
    int check_select_context_select();
    int check_select_context_where();
    int check_select_context_order_by();

    /*
     * expr_idx: expression idx in ctx.join_expr_tree
     */
    int check_join_expr(
            size_t expr_idx,
            ExpressionNode* node,
            sdl::sql::ValueType& expr_type);

    int check_where_expr(
            ExpressionNode* node,
            sdl::sql::ValueType& expr_type);

    int execute_expr(
            std::vector<record_iterator> const& row,
            ExpressionNode* node,
            sdl::sql::Value& value);
};

std::ostream& operator<<(
        std::ostream& os,
        const SqlExecutor::Identifier& r);


#endif