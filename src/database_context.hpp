#ifndef DATABASE_CONTEXT_HPP
#define DATABASE_CONTEXT_HPP

#include "dataserver/system/database.h"

#include <map>
#include <set>
#include <string>

class DatabaseContext
{
    sdl::db::database& db_;

    using ColumnSet = std::set<std::string>;
    using TableMap = std::map<std::string, ColumnSet>;

    TableMap schema_;

public:
    DatabaseContext(sdl::db::database& db);

    void init();

    void dump_schema();
};



#endif