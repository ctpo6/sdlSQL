#ifndef SDLSQL_TYPES_HPP
#define SDLSQL_TYPES_HPP

#include "dataserver/system/database.h"

#include <boost/variant.hpp>

#include <cstdint>
#include <ostream>
#include <string>


namespace sdl { namespace sql {

template <typename... T>
using variant = boost::variant<T...>;

struct null_t
{
    inline bool operator==(const null_t&) const { return true; }
    inline bool operator<(const null_t&) const { return false; }
};

inline std::ostream& operator<<(std::ostream& os, const null_t)
{
    return os;
}


using Value = variant<null_t, bool, int32_t, std::string>;

enum class ValueType : int
{
    // the order must be the same as in Value declaration
    NULL_T = 0,
    BOOL,
    INT32_T,
    STRING,
    UNKNOWN = -1
};

Value make_value(
        sdl::db::datatable::record_type const& record,
        size_t col_idx);

ValueType db_scalartype_to_value_type(sdl::db::scalartype::type st);

}}

#endif