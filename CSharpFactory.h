#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H
#include "AbsFactory.h"
#include "CSharpUnits.h"

class CSharpFactory : public IFactory
{
public:
    explicit CSharpFactory();
    ~CSharpFactory();

    std::shared_ptr<ClassUnit> ClassUnit_(const std::string name, unsigned int modifier = ClassUnit::NONE);

    std::shared_ptr<MethodUnit> MethodUnit_(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::NONE);

    std::shared_ptr<PrintOperatorUnit> PrintOperatorUnit_(const std::string text);
};
#endif // CSHARPFACTORY_H
