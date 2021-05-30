#ifndef ABSFACTORY_H
#define ABSFACTORY_H
#include "Units.h"

class IFactory
{
public:

    virtual std::shared_ptr<ClassUnit>ClassUnit_(const std::string name, unsigned int modifier = ClassUnit::NONE) = 0;

    virtual std::shared_ptr<MethodUnit>MethodUnit_(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::NONE) = 0;

    virtual  std::shared_ptr<PrintOperatorUnit>PrintOperatorUnit_(const std::string text) = 0;

    virtual ~IFactory() {};
};

#endif // ABSFACTORY_H
