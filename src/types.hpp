#ifndef SDLSQL_TYPES_HPP
#define SDLSQL_TYPES_HPP

#include <boost/variant.hpp>

#include <cstdint>
#include <string>


namespace sdl { namespace sql {

template <typename... T>
using variant = boost::variant<T...>;

using Value = variant<int32_t, std::string>;

}
}

#endif