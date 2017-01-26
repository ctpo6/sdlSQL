# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed!!!")
endif()

cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(calc++)


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

set(SCANNER_SRC src/sql.l)
set(PARSER_SRC src/sql.y)

BISON_TARGET(SQL_PARSER ${PARSER_SRC} ${CMAKE_CURRENT_BINARY_DIR}/sql_parser.c
    COMPILE_FLAGS --debug)
FLEX_TARGET(SQL_SCANNER ${SCANNER_SRC}  ${CMAKE_CURRENT_BINARY_DIR}/sql.lex.c
    COMPILE_FLAGS "--debug --header-file=${CMAKE_CURRENT_BINARY_DIR}/sql.lex.h" )
ADD_FLEX_BISON_DEPENDENCY(SQL_SCANNER SQL_PARSER)


include_directories(
    src
    ${CMAKE_CURRENT_BINARY_DIR}
    )

set(SQL1_SRC
    src/exec.c
    src/sql-parser.h
    )

# display these files in QtCreator
add_custom_target(other_project_files SOURCES ${SQL_SCANNER_SRC} ${SQL_PARSER_SRC})

add_executable(sql1 ${SQL1_SRC} ${BISON_SQL_PARSER_OUTPUTS} ${FLEX_SQL_SCANNER_OUTPUTS})

