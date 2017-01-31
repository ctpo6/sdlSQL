#include "driver.hpp"

#include <iostream>
#include <string>


using namespace std;


int main (int argc, char *argv[])
{
    int res = 0;

    Driver driver;

    if (argc == 1) {
        // read from stdin
        if(!driver.parse(""))
            cout << driver.result << endl;
        else
            res = 1;
    }
    else {
        for (int i = 1; i < argc; ++i) {
            if (argv[i] == string("-p"))
                driver.trace_parsing = true;
            else if (argv[i] == string("-s"))
                driver.trace_scanning = true;
            else if(!driver.parse(argv[i]))
                cout << driver.result << endl;
            else
                res = 1;
        }
    }

    return res;
}
