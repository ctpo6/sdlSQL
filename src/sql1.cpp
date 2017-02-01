#include "driver.hpp"

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


int main (int argc, char *argv[])
{
    int res = 0;

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
            res = 1;
        }

        if (res)
            break;
    }

    if (res) {
        cerr << "Wrong command line option: " << argv[arg_pos] << endl;
        return 1;
    }

    if (arg_pos == argc) {
        // read from stdin
        if(!driver.parse(""))
            cout << driver.result << endl;
        else
            res = 1;
    }
    else {
        for (; arg_pos < argc; ++arg_pos) {
            if(!driver.parse(argv[arg_pos]))
                cout << driver.result << endl;
            else
                res = 1;
        }
    }

    return res;
}
