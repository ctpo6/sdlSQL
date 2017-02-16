#include "types.hpp"

#include <cassert>
#include <cstdint>


using namespace std;


namespace sdl { namespace sql {

Value make_value(
        sdl::db::datatable::record_type const& record,
        size_t col_idx)
{
    using scalartype = sdl::db::scalartype;

    Value value;

    auto const& col = record.usercol(col_idx);
    if (col.is_fixed()) {
        switch (col.type) {
        case scalartype::t_int:
            value = static_cast<int32_t>(
                        *record.cast_fixed_col<scalartype::t_int>(col_idx));
            break;
        case scalartype::t_char:
        case scalartype::t_nchar:
            value = record.type_col_utf8(col_idx);
            break;
        default:
            assert(false && "column type is not supported");
        }
    }
    else {
        switch (col.type) {
        case scalartype::t_text:
        case scalartype::t_varchar:
        case scalartype::t_ntext:
        case scalartype::t_nvarchar:
            value = record.type_col_utf8(col_idx);
            break;
        default:
            assert(false && "column type is not supported");
        }
    }

    return value;
}

}}
