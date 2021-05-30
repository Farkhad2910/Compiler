#include "CPlusFactory.h"
#include "CSharpFactory.h"
#include "JavaFactory.h"
#include "Compiler.h"

using std::cout;

int main()
{
    cout << "CPlus:" << std::endl;
    Compiler CPlus(std::make_shared<CPlusFactory>());
    cout << CPlus.compilate() << std::endl;

    cout << "CSharp generator:" << std::endl;
    cout << std::endl;
    Compiler CSharp(std::make_shared<CSharpFactory>());
    cout << CSharp.compilate() << std::endl;

    cout << "Java generator:" << std::endl;
    cout << std::endl;
    Compiler Java(std::make_shared<JavaFactory>());
    cout << Java.compilate() << std::endl;

    return 0;
}


