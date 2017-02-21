#ifndef DATABASE_CONTEXT_HPP
#define DATABASE_CONTEXT_HPP

#include "types.hpp"

#include "dataserver/system/database.h"

#include <map>
#include <set>
#include <string>
#include <vector>


class DatabaseContext
{
    sdl::db::database& db_;

    struct ColumnInfo
    {
        size_t idx;
        sdl::sql::ValueType type;
    };
    using ColumnMap = std::map<std::string, ColumnInfo>;

    struct TableInfo
    {
        size_t idx;
        ColumnMap columns;
    };
    using TableMap = std::map<std::string, TableInfo>;

    TableMap schema_;

    using DatatableIterator = decltype(db_._datatables.begin());
    std::vector<DatatableIterator> datatables_;

public:
    DatabaseContext(sdl::db::database& db);

    void init();

    void dump_schema();

    bool has_table(const std::string& table_name) const noexcept;

    bool has_table_column(
            const std::string& table_name,
            const std::string& column_name) const noexcept;

    /*
     * Throws:
     * std::invalid_argument    Database doesn't have table with table_name.
     */
    const sdl::db::datatable& get_table(
            const std::string& table_name) const;

    size_t get_table_idx(const std::string& table_name) const;

    const sdl::db::datatable& get_table(size_t table_idx) const;


    /*
     * Throws:
     * std::invalid_argument    Database doesn't have table with table_name.
     */
    std::vector<std::string> get_table_column_names(
            const std::string& table_name) const;

    /*
     * Throws:
     * std::invalid_argument    Database doesn't have specified column.
     */
    size_t get_column_position(
            const std::string& table_name,
            const std::string& column_name) const;

    /*
     * Return:
     * ValueType::UNKNOWN if data type is not supported
     */
    sdl::sql::ValueType get_column_value_type(
            const std::string& table_name,
            const std::string& column_name) const;
};



#endif