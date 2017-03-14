# sdlSQL
SQL interpreter. Implemented only SELECT with inner JOINs, WHERE, ORDER BY, TOP, table and column 'AS' aliases.
The purpose was to see what it costs in terms of amount of C++ code to implement such functionality.
Utilizes **Bison**/**Flex** for frontend and **dataserver** library (https://github.com/Totopolis/dataserver) for data access in MDF file. The request processing engine itself was developed in C++ from scratch. Requires C++14 capable compiler.
