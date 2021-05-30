#include "JavaFactory.h"

JavaFactory::JavaFactory() {}
JavaFactory::~JavaFactory() {}

std::shared_ptr<ClassUnit> JavaFactory::ClassUnit_(std::string name, unsigned int modifier)
{
    return std::make_shared<JavaClass>(name, modifier);
}

std::shared_ptr<MethodUnit> JavaFactory::MethodUnit_(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared<JavaMethod>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> JavaFactory::PrintOperatorUnit_(std::string text)
{
    return std::make_shared<JavaPrint>(text);
}
