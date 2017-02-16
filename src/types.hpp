#ifndef SDLSQL_TYPES_HPP
#define SDLSQL_TYPES_HPP

#include "dataserver/system/database.h"

#include <boost/variant.hpp>

#include <cstdint>
#include <string>


namespace sdl { namespace sql {

template <typename... T>
using variant = boost::variant<T...>;

using Value = variant<int32_t, std::string>;

Value make_value(
        sdl::db::datatable::record_type const& record,
        size_t col_idx);

}}

#endif