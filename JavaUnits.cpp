#include "JavaUnits.h"

JavaClass::JavaClass(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

JavaClass::~JavaClass()
{}

std::string JavaClass::compile(unsigned int level) const
{
    std::string result = generateShift(level);


    if (m_modifier & PRIVATE)
        result += "private ";
    else if (m_modifier & PROTECTED)
        result += "protected ";
    else
        result += "public ";

    if (m_modifier & FINAL)
        result += "final ";

    else if (m_modifier & ABSTRACT)
        result += "abstract ";

    result += "class " + m_name + " ";

    result += " {\n";

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

JavaMethod::JavaMethod(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

JavaMethod::~JavaMethod() {}

std::string JavaMethod::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "static ";

    else if (m_flags & FINAL)
        result += "final ";

    else if (m_flags & ABSTRACT)
        result += "abstract ";

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

JavaPrint::JavaPrint(const std::string& text) :
    PrintOperatorUnit(text) {}

JavaPrint::~JavaPrint() {}

std::string JavaPrint::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
