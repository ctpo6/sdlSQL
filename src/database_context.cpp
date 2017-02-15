#include "database_context.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
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
        const std::string& table_name) const noexcept
{
    return schema_.find(table_name) != schema_.end();
}


const sdl::db::datatable& DatabaseContext::get_table(
        const std::string& table_name) const
{
    if (!has_table(table_name))
        throw std::invalid_argument("table not found");
    for (auto const& ptable: db_._datatables) {
        if (ptable->name() == table_name) {
            return *ptable;
        }
    }
    assert(false && "table not found");
    throw std::invalid_argument("table not found");
}


std::vector<std::string> DatabaseContext::get_table_column_names(
        const std::string& table_name) const
{
    const sdl::db::datatable& table = get_table(table_name);
    vector<string> result;
    result.reserve(table.ut().size());
    for (auto const& col: table.ut()) {
        result.push_back(col.name);
    }
    return result;
}


size_t DatabaseContext::get_column_position(
        const std::string& table_name,
        const std::string& column_name) const
{
    size_t pos;
    try {
        pos = schema_.at(table_name).columns.at(column_name);
    }
    catch (const std::out_of_range&) {
        throw std::invalid_argument("table or column not found");
    }
    return pos;
}


bool DatabaseContext::has_table_column(
        const std::string& table_name,
        const std::string& column_name) const noexcept
{
    auto it = schema_.find(table_name);
    if (it == schema_.end())
        return false;
    return it->second.columns.find(column_name) != it->second.columns.end();
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
