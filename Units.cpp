#include "Units.h"

void Unit::add(const std::shared_ptr< Unit >&, Flags)
{
    throw std::runtime_error("Not supported");
}

std::string Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = "    ";
    std::string result;

    for (unsigned int i = 0; i < level; ++i)
    {
        result += DEFAULT_SHIFT;
    }
    return result;
}

ClassUnit::ClassUnit(const std::string& name, Flags modifier) :
    m_name( name ),
    m_modifier(modifier)
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

void ClassUnit::add(const std::shared_ptr< Unit > & unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }

    m_fields[accessModifier].push_back(unit);
}

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };

MethodUnit::MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    m_name( name ), m_returnType( returnType ), m_flags( flags ) {}


void MethodUnit::add(const std::shared_ptr< Unit > & unit, Flags)
{
    m_body.push_back(unit);
}

PrintOperatorUnit::PrintOperatorUnit(const std::string & Text) :
    m_text(Text) {}

