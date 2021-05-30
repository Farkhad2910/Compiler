#include "CPlusFactory.h"


CPlusFactory::CPlusFactory()
{}

CPlusFactory::~CPlusFactory()
{}

std::shared_ptr<ClassUnit> CPlusFactory::ClassUnit_(const std::string name, unsigned int modifier)
{
    return std::make_shared<CPlusClass>(name, ClassUnit::NONE);
}

std::shared_ptr<MethodUnit> CPlusFactory::MethodUnit_(const std::string name, const std::string returnType, unsigned int Flags)
{
    return std::make_shared<CPlusMethod>(name, returnType, Flags);
}

std::shared_ptr<PrintOperatorUnit>CPlusFactory::PrintOperatorUnit_(const std::string text)
{
    return std::make_shared<CPlusPrint>(text);
}
