#ifndef JAVAUNITS_H
#define JAVAUNITS_H
#include "Units.h"

class JavaClass : public ClassUnit
{
public:
    explicit JavaClass(const std::string& name, Flags modifier = ClassUnit::NONE);
    ~JavaClass();
    std::string compile(unsigned int level = 0) const;
};

class JavaMethod : public MethodUnit
{
public:
    explicit JavaMethod(const std::string& name, const std::string& returnType, Flags flags);
    ~JavaMethod();
    std::string compile(unsigned int level = 0) const;
};

class JavaPrint : public PrintOperatorUnit
{
public:
    explicit JavaPrint(const std::string& text);
    ~JavaPrint();
    std::string compile(unsigned int level = 0) const;
};

#endif // JAVAUNITS_H
