#ifndef CPLUSFACTORY_H
#define CPLUSFACTORY_H
#include "AbsFactory.h"
#include "CPlusUnits.h"

class CPlusFactory : public IFactory
{
public:
    explicit CPlusFactory();
    ~CPlusFactory();

    std::shared_ptr<ClassUnit>ClassUnit_(const std::string name, unsigned int modifier = ClassUnit::NONE);

    std::shared_ptr<MethodUnit>MethodUnit_(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::NONE);

    std::shared_ptr<PrintOperatorUnit>PrintOperatorUnit_(const std::string text);
};

#endif // CPLUSFACTORY_H
