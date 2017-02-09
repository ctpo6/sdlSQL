#include "database_context.hpp"

#include <iostream>
#include <utility>

using namespace std;

DatabaseContext::DatabaseContext(sdl::db::database& db)
    : db_(db)
{
}


void DatabaseContext::init()
{
    for (auto const& table : db_._datatables) {
        auto res = schema_.insert(make_pair(table->name(), ColumnSet()));
        assert(res.second && "no duplications of table names allowed");

        auto it = res.first;
        for (auto const& col : table->ut()) {
            auto res = it->second.insert(col.name);
            assert(res.second && "no duplications of column names allowed");
        }
    }
}


void DatabaseContext::dump_schema()
{
    cout << db_.dbi_dbname() << endl;
    for (auto const& table : schema_) {
        cout << "Table: " << table.first << endl;
        for (auto const& col_name : table.second) {
            cout << "  " << col_name << endl;
        }
    }
}
