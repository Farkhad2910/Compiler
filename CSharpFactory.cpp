#include "CSharpFactory.h"

CSharpFactory::CSharpFactory()
{}
CSharpFactory::~CSharpFactory()
{}

std::shared_ptr<ClassUnit> CSharpFactory::ClassUnit_(std::string name, unsigned int modifier)
{
    return std::make_shared<CSharpClass>(name, modifier);
}

std::shared_ptr<MethodUnit> CSharpFactory::MethodUnit_(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared<CSharpMethod>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CSharpFactory::PrintOperatorUnit_(std::string text)
{
    return std::make_shared<CSharpPrint>(text);
}
