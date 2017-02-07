#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <deque>
#include <string>

class SqlExecutor
{
public:
    enum EmitOp
    {
        EMOP_AS,
        EMOP_ASC,
        EMOP_COMPARISON,
        EMOP_DESC,
        EMOP_FIELD,
        EMOP_FROM,
        EMOP_JOIN,
        EMOP_NAME,
        EMOP_NUMBER,
        EMOP_OPERATOR,
        EMOP_ORDER_BY,
        EMOP_STRING,
        EMOP_TABLE,
        EMOP_TOP,
        EMOP_SELECT,
        EMOP_SELECT_ALL,
        EMOP_WHERE,
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

        // column or table reference: name2_.name1_
        // alias: name1_
        std::string name1_;
        std::string name2_;
    };

    static EmitRecord make_emit_record(EmitOp op);
    static EmitRecord make_emit_record(EmitOp op, int param);
    static EmitRecord make_emit_record(EmitOp op, const std::string& param);
    static EmitRecord make_emit_record(EmitOp op,
                                       const std::string& name1,
                                       const std::string& name2);

    int walk();

    std::deque<EmitRecord> emit_;
};

#endif