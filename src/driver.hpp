#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "sql_executor_types.hpp"

#include "sql.tab.hpp"

#include <deque>
#include <string>
#include <utility>


// Tell Flex the lexer's prototype ...
#define YY_DECL \
    yy::SqlParser::symbol_type yylex(Driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;


// Conducting the whole scanning and parsing of Calc++.
class Driver
{
    using ParserCommandContainer = std::deque<ParserCommand>;

    ParserCommandContainer emit_;

    inline void emit(ParserOpCode op)
    {
        emit_.emplace_back(op);
    }

    inline void emit(ParserOpCode op, int param)
    {
        emit_.emplace_back(op, param);
    }

    inline void emit(ParserOpCode op, std::string param)
    {
        emit_.emplace_back(op, std::move(param));
    }

    inline void emit(ParserOpCode op,
                     std::string name1,
                     std::string name2)
    {
        emit_.emplace_back(op, std::move(name1), std::move(name2));
    }

public:

    int result;

    // The name of the file being parsed.
    // Used later to pass the file name to the location tracker.
    std::string file;

    bool trace_scanning = false;
    bool trace_parsing = false;

public:

    ParserCommandContainer const& get_parser_commands() const { return emit_; }

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // Run the parser on file F.
    // Return 0 on success.
    int parse(const std::string& f);

    void sqlp_alias(const std::string& alias);
    void sqlp_expr_cmp(ExprOperator comp);
    void sqlp_expr_op(ExprOperator op);
    void sqlp_field(const std::string& tbl_name, const std::string& col_name);
    void sqlp_float(double val);
    void sqlp_from_table_reference();
    void sqlp_join();
    void sqlp_name(const std::string& name);
    void sqlp_number(int val);
    void sqlp_order_by(int desc);
    void sqlp_order_by_list(int n_list);
    void sqlp_select(int n_expr);
    void sqlp_select_all();
    void sqlp_stmt();
    void sqlp_string(const std::string& str);
    void sqlp_table(const std::string& db_name, const std::string& tbl_name);
    void sqlp_top(int num);
    void sqlp_where();

    // Error handling.
    void error(const yy::location& l, const std::string& m);
    void error(const std::string& m);
};

#endif