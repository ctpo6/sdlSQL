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
# Libraries
################################################################################
#find_package(Threads)

add_subdirectory(external/dataserver)

include_directories(
    ${PROJECT_SOURCE_DIR}/external/dataserver
    )
link_directories(
    ${PROJECT_SOURCE_DIR}/external/dataserver/lib
    )

add_definitions(-DSDL_OS_UNIX)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_definitions(-DSDL_DEBUG=1)
else()
    add_definitions(-DSDL_DEBUG=0)
endif()

################################################################################
# Targets
################################################################################

set(SCANNER_SRC src/sql.ll)
set(PARSER_SRC src/sql.yy)

BISON_TARGET(SQL_PARSER ${PARSER_SRC} ${CMAKE_CURRENT_BINARY_DIR}/sql.tab.cpp
    COMPILE_FLAGS --debug)
FLEX_TARGET(SQL_SCANNER ${SCANNER_SRC} ${CMAKE_CURRENT_BINARY_DIR}/sql.lex.cpp
    COMPILE_FLAGS "--debug --header-file=${CMAKE_CURRENT_BINARY_DIR}/sql.lex.hpp" )
ADD_FLEX_BISON_DEPENDENCY(SQL_SCANNER SQL_PARSER)

include_directories(
    src
    ${CMAKE_CURRENT_BINARY_DIR}
    )

set(SQL1_SRC
    src/database_context.cpp
    src/driver.cpp
    src/driver1.cpp
    src/sql1.cpp
    src/sql_executor.cpp
    src/sql_executor0.cpp
    src/types.cpp
    )

add_custom_target(display_other_files
    SOURCES ${SCANNER_SRC} ${PARSER_SRC})

add_executable(sql1 ${SQL1_SRC} ${BISON_SQL_PARSER_OUTPUTS} ${FLEX_SQL_SCANNER_OUTPUTS})
target_link_libraries(sql1 dataserver)
