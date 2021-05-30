#ifndef CPLUSUNITS_H
#define CPLUSUNITS_H
#include "Units.h"

class CPlusClass : public ClassUnit
{
public:
    explicit CPlusClass(const std::string& name, Flags modifier = ClassUnit::NONE);
    ~CPlusClass();
    std::string compile(unsigned int level = 0) const;
};

class CPlusMethod : public MethodUnit
{
public:
    explicit CPlusMethod(const std::string& name, const std::string& returnType, Flags flags);
    ~CPlusMethod();
    std::string compile(unsigned int level = 0) const;
};

class CPlusPrint : public PrintOperatorUnit
{
public:
    explicit CPlusPrint(const std::string& text);
    ~CPlusPrint();
    std::string compile(unsigned int level = 0) const;
};

#endif // CPLUSUNITS_H
