# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed!!!")
endif()

cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(sdlsql)


################################################################################
# Project build options
################################################################################

################################################################################
# Libraries
################################################################################
#find_package(Threads)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

################################################################################
# Build type
################################################################################
if(NOT CMAKE_BUILD_TYPE)
    #set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message("")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message("")

################################################################################
# Compiler flags and definitions
################################################################################

set(MY_C_WARNING_FLAGS "-Wall -Wextra -Wredundant-decls -Wformat -Werror=format-security -Wno-parentheses -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable")
set(MY_CXX_WARNING_FLAGS "-Wall -Wextra -Wredundant-decls -Woverloaded-virtual -Wnon-virtual-dtor -Wformat -Werror=format-security -Wno-parentheses -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable")

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -D_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -D_DEBUG")

set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -ggdb -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -ggdb -DNDEBUG")

set(CMAKE_C_FLAGS "${MY_C_WARNING_FLAGS} ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++14 ${MY_CXX_WARNING_FLAGS} ${CMAKE_CXX_FLAGS}")

################################################################################
# Targets
################################################################################

set(SCANNER_C_SRC src/sql.l)
set(PARSER_C_SRC src/sql.y)

set(SCANNER_SRC src/sql.ll)
set(PARSER_SRC src/sql.yy)

BISON_TARGET(SQL_C_PARSER ${PARSER_C_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.tab.c
    COMPILE_FLAGS --debug)
FLEX_TARGET(SQL_C_SCANNER ${SCANNER_C_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.lex.c
    COMPILE_FLAGS "--debug --header-file=${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.lex.h" )
ADD_FLEX_BISON_DEPENDENCY(SQL_C_SCANNER SQL_C_PARSER)

BISON_TARGET(SQL_PARSER ${PARSER_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.tab.cpp
    COMPILE_FLAGS --debug)
FLEX_TARGET(SQL_SCANNER ${SCANNER_SRC} ${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.lex.cpp
    COMPILE_FLAGS "--debug --header-file=${CMAKE_CURRENT_SOURCE_DIR}/out.bison/sql.lex.hpp" )
ADD_FLEX_BISON_DEPENDENCY(SQL_SCANNER SQL_PARSER)

include_directories(
    src
    out.bison
    )

set(SQL1_C_SRC
    src/exec.c
    src/sql-parser.h
    )

set(SQL1_SRC
    src/driver.cpp
    src/driver1.cpp
    src/sql1.cpp
    )

set(BISON_GENERATED_FILES
    out.bison/sql.lex.c
    out.bison/sql.lex.h
    out.bison/sql.tab.c
    out.bison/sql.tab.h

    out.bison/sql.lex.cpp
    out.bison/sql.lex.hpp
    out.bison/sql.tab.cpp
    out.bison/sql.tab.hpp
    )

add_custom_target(display_other_files
    SOURCES ${SCANNER_SRC} ${PARSER_SRC} ${SCANNER_C_SRC} ${PARSER_C_SRC})
add_custom_target(display_bison_generated_files
    SOURCES ${BISON_GENERATED_FILES})

add_executable(sql1c ${SQL1_C_SRC} ${BISON_SQL_C_PARSER_OUTPUTS} ${FLEX_SQL_C_SCANNER_OUTPUTS})

add_executable(sql1 ${SQL1_SRC} ${BISON_SQL_PARSER_OUTPUTS} ${FLEX_SQL_SCANNER_OUTPUTS})
