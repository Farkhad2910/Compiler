#include "CSharpUnits.h"

CSharpClass::CSharpClass(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

CSharpClass::~CSharpClass()
{}

std::string CSharpClass::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_modifier & PROTECTED_INTERNAL)
        result += "protected internal ";

    else if (m_modifier & PRIVATE_PROTECTED)
        result += "private protected ";
    else
        result += "public ";

    result += "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CSharpMethod::CSharpMethod(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags)
{}

CSharpMethod::~CSharpMethod()
{}

std::string CSharpMethod::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "static ";

    else if (m_flags & VIRTUAL)
        result += "virtual ";

    else
        result += "internal ";

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

CSharpPrint::CSharpPrint(const std::string& text) :
    PrintOperatorUnit(text)
{}

CSharpPrint::~CSharpPrint()
{}

std::string CSharpPrint::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}
