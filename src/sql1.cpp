#include "database_context.hpp"
#include "driver.hpp"
#include "sql_executor.hpp"

#include "dataserver/system/database.h"

#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

/*
SELECT TOP (100) t1.f1, t2.f2
FROM Table1 t1
JOIN Table2 t2 ON t1.id = t2.v AND t2.x = 3
WHERE t1.z > 3 AND (t2.y < 15 OR t2.w is NULL)
ORDER BY t1.f1;

1) FROM: only 1 table
2) JOIN: INNER, by int columns only
3)
4) not using indexes ???
5) IS NULL, IS NOT NULL in WHERE
*/

const char* db_file_path = "sdlSQL.mdf";


int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "en_US.utf8");

    sdl::db::database db(db_file_path);
    if (!db.is_open()) {
        cerr << "Failed to open database: " << db_file_path << endl;
        exit(1);
    }

    cout << "\nDatabase successfully opened: " << db_file_path << "\n\n";

    DatabaseContext db_context(db);
    db_context.init();
    db_context.dump_schema();
    cout << endl;

    SqlExecutor exec(db_context);
    Driver driver(exec);

    int arg_pos = 1;
    for (; arg_pos < argc; ++arg_pos) {
        if (argv[arg_pos][0] != '-')
            break;

        switch(argv[arg_pos][1]) {
        case 'p':
            driver.trace_parsing = true;
            break;
        case 's':
            driver.trace_scanning = true;
            break;
        default:
            cerr << "Wrong command line option: " << argv[arg_pos] << endl;
            exit(1);
        }
    }

    // read from stdin
    if (driver.parse(arg_pos < argc ? string(argv[arg_pos]) : string()) != 0) {
        exit(1);
    }

    if (exec.execute() != 0) {
        exit(1);
    }

    return 0;
}
