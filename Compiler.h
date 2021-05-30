#ifndef COMPILER_H
#define COMPILER_H
#include "AbsFactory.h"

class Compiler
{
private:
    std::shared_ptr<IFactory> ptr;
public:
    explicit Compiler(const std::shared_ptr<IFactory>& comp);
    ~Compiler() {};
    void setCompiler(const std::shared_ptr<IFactory>& comp);
    std::shared_ptr<IFactory> getCompiler();
    std::string compilate();
};

#endif // COMPILER_H

