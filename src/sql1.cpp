#include "database_context.hpp"
#include "driver.hpp"
#include "sql_executor.hpp"

#include "dataserver/system/database.h"

#include <clocale>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

const char* db_file_path = "sdlSQL.mdf";

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "en_US.utf8");

    auto db = make_shared<sdl::db::database>(db_file_path);
    if (!db->is_open()) {
        cerr << "Failed to open database: " << db_file_path << endl;
        exit(1);
    }
    cout << "\nDatabase successfully opened: " << db_file_path << "\n\n";

    DatabaseContext db_context(db);
//    db_context.dump_schema();
//    cout << endl;

    SqlExecutor exec(db_context);
    Driver driver;

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

    if (exec.execute(driver.get_parser_commands()) != 0) {
        exit(1);
    }

    return 0;
}
