#include "driver.hpp"

#include "sql.tab.hpp"

#include <iostream>
#include <string>


using namespace std;


int Driver::parse(const std::string &f)
{
    file = f;
    scan_begin();
    yy::SqlParser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    return res;
}


void Driver::error(const yy::location& l, const string& m)
{
    cerr << l << ": " << m << endl;
}


void Driver::error(const string& m)
{
    cerr << m << endl;
}
