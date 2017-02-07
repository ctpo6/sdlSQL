#include "driver.hpp"
#include "sql_executor.hpp"

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


int main(int argc, char *argv[])
{
    SqlExecutor exec;
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
