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
    size_t table_idx = 0;
    for (auto table_it = db_._datatables.begin();
         table_it != db_._datatables.end();
         ++table_it)
    {
        TableInfo t;
        t.idx = table_idx++;

        // table_it points to shared_ptr
        const sdl::db::datatable& table = *table_it->get();

        size_t col_idx = 0;
        for (auto const& col : table.ut()) {
            auto r = t.columns.insert(make_pair(col.name, col_idx++));
            assert(r.second && "no duplications of column names allowed");
        }

        auto r = schema_.insert(
                    make_pair(table.name(), std::move(t)));
        assert(r.second && "no duplications of table names allowed");
    }
}


bool DatabaseContext::has_table(
        const std::string& table_name) const
{
    return schema_.find(table_name) != schema_.end();
}


void DatabaseContext::dump_schema()
{
    cout << db_.dbi_dbname() << endl;
    for (auto const& table : schema_) {
        cout << "Table: " << table.first << endl;
        for (auto const& col : table.second.columns) {
            cout << "  " << col.first << endl;
        }
    }
}
