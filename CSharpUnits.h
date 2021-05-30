#ifndef CSHARPUNITS_H
#define CSHARPUNITS_H
#include "Units.h"

class CSharpClass : public ClassUnit
{
public:
    explicit CSharpClass(const std::string& name, Flags modifier = ClassUnit::NONE);
    ~CSharpClass();
    std::string compile(unsigned int level = 0) const;
};

class CSharpMethod : public MethodUnit
{
public:
    explicit CSharpMethod(const std::string& name, const std::string& returnType, Flags flags);
    ~CSharpMethod();
    std::string compile(unsigned int level = 0) const;
};

class CSharpPrint : public PrintOperatorUnit
{
public:
    explicit CSharpPrint(const std::string& text);
    ~CSharpPrint();
    std::string compile(unsigned int level = 0) const;
};
#endif // CSHARPUNITS_H
