#ifndef DATABASE_CONTEXT_HPP
#define DATABASE_CONTEXT_HPP

#include "dataserver/system/database.h"

#include <map>
#include <set>
#include <string>
#include <vector>

class DatabaseContext
{
    sdl::db::database& db_;

    // map: name -> order idx
    using ColumnMap = std::map<std::string, size_t>;

    struct TableInfo
    {
        size_t idx;
        ColumnMap columns;
    };

    using TableMap = std::map<std::string, TableInfo>;

    TableMap schema_;

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

    /*
     * Throws:
     * std::invalid_argument    Database doesn't have table with table_name.
     */
    std::vector<std::string> get_table_column_names(
            const std::string& table_name) const;

};



#endif