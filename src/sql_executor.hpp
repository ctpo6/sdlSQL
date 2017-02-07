#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <deque>
#include <string>

class SqlExecutor
{
public:
    enum class EmitOp
    {
        AS,
        ASC,
        COMPARISON,
        DESC,
        FIELD,
        FROM,
        JOIN,
        NAME,
        NUMBER,
        OPERATOR,
        ORDER_BY,
        STRING,
        TABLE,
        TOP,
        SELECT,
        SELECT_ALL,
        WHERE,
    };

    void emit(EmitOp op);
    void emit(EmitOp op, int param);
    void emit(EmitOp op, const std::string& param);
    void emit(EmitOp op, const std::string& name1, const std::string& name2);

    int execute();

private:
    struct EmitRecord
    {
        EmitOp op_;

        int int_;               // for int values
        std::string string_;    // for string values

        // column or table reference: name1_.name2_
        // alias: name2_
        std::string name1_;
        std::string name2_;
    };

    using EmitRecordContainer = std::deque<EmitRecord>;

    static EmitRecord make_emit_record(EmitOp op);
    static EmitRecord make_emit_record(EmitOp op, int param);
    static EmitRecord make_emit_record(EmitOp op, const std::string& param);
    static EmitRecord make_emit_record(EmitOp op,
                                       const std::string& name1,
                                       const std::string& name2);


    int walk();
    int walk_order_by(const EmitRecordContainer::iterator start,
                      EmitRecordContainer::iterator& next_part);
    int walk_where();

    EmitRecordContainer emit_;
};

#endif