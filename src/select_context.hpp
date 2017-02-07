#ifndef SELECT_CONTEXT_HPP
#define SELECT_CONTEXT_HPP

#include <string>

class SelectContext
{
public:
    void getOrInsertColumnId(const std::string& table_name,
                             const std::string& column_name,
                             size_t& out_column_id);

    void addColumnAlias(size_t column_id,
                        const std::string& alias);

};





#endif