#include "Compiler.h"

Compiler::Compiler(const std::shared_ptr<IFactory>& comp):
    ptr(comp) {}

void Compiler::setCompiler(const std::shared_ptr<IFactory>& comp)
{
    ptr = comp;
}

std::shared_ptr<IFactory> Compiler::getCompiler()
{
    return ptr;
}

std::string Compiler::compilate()
{
    auto unit = ptr->ClassUnit_("MyClass", ClassUnit::PUBLIC | ClassUnit::ABSTRACT);

    auto func1 = ptr->MethodUnit_( "testFunc1", "void", 0 );
        unit->add(func1, ClassUnit::PUBLIC );

    auto func2 = ptr->MethodUnit_( "testFunc2", "void",MethodUnit::ABSTRACT | MethodUnit::INTERNAL );
        unit->add(func2, ClassUnit::PRIVATE);

    auto func3 = ptr->MethodUnit_( "testFunc3", "void",MethodUnit::VIRTUAL | MethodUnit::CONST );
        unit->add(func3, ClassUnit::PUBLIC);

    auto func4 = ptr->MethodUnit_( "testFunc4", "void",MethodUnit::STATIC );
        unit->add(func4, ClassUnit::PROTECTED);

    auto print = ptr -> PrintOperatorUnit_( R"(Hello,world!\n)" );
        func4->add(print);


    return unit->compile();
}


