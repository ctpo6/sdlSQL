#include "database_context.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;


DatabaseContext::DatabaseContext(shared_ptr<sdl::db::database> db)
    : pdb_(db)
{
    init();
}


void DatabaseContext::init()
{
    datatables_.reserve(pdb_->_datatables.end() - pdb_->_datatables.begin());

    size_t table_idx = 0;
    for (auto table_it = pdb_->_datatables.begin();
         table_it != pdb_->_datatables.end();
         ++table_it)
    {
        datatables_.push_back(table_it);

        TableInfo t;
        t.idx = table_idx++;

        // table_it points to shared_ptr
        const sdl::db::datatable& table = *table_it->get();

        size_t col_idx = 0;
        for (auto const& col : table.ut()) {
            ColumnInfo c;
            c.idx = col_idx++;
            c.type = sdl::sql::db_scalartype_to_value_type(col.type);

            auto r = t.columns.insert(make_pair(col.name, c));
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
    return get_table(get_table_idx(table_name));
}


size_t DatabaseContext::get_table_idx(
        const std::string& table_name) const
{
    auto it = schema_.find(table_name);
    if (it == schema_.end())
        throw std::invalid_argument("table not found");
    return it->second.idx;
}


const sdl::db::datatable& DatabaseContext::get_table(
        size_t table_idx) const
{
    assert(table_idx < datatables_.size());
    // *datatables_[i]: shared_ptr
    return *(datatables_[table_idx]->get());
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


size_t DatabaseContext::get_column_idx(
        const std::string& table_name,
        const std::string& column_name) const
{
    try {
        return schema_.at(table_name).columns.at(column_name).idx;
    }
    catch (const std::out_of_range&) {
        throw std::invalid_argument("table or column not found");
    }
}


sdl::sql::ValueType DatabaseContext::get_column_value_type(
        const std::string& table_name,
        const std::string& column_name) const
{
    try {
        return schema_.at(table_name).columns.at(column_name).type;
    }
    catch (const std::out_of_range&) {
        throw std::invalid_argument("table or column not found");
    }
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


void DatabaseContext::dump_schema() const noexcept
{
    cout << pdb_->dbi_dbname() << endl;
    for (auto const& table : schema_) {
        cout << "Table: " << table.first << endl;
        for (auto const& col : table.second.columns) {
            cout << "  " << col.first << endl;
        }
    }
}
