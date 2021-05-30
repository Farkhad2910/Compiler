#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags );
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual std::string generateShift( unsigned int level ) const;
};

class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        NONE,
        FINAL,
        ABSTRACT,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string& name, Flags modifier = AccessModifier::NONE);
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_name;
    Flags m_modifier;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        NONE = 0,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        INTERNAL = 1 << 5,
    };
public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add( const std::shared_ptr< Unit >& unit, Flags = Modifier::NONE);
    std::string compile( unsigned int level = 0 ) const = 0;
protected:
     std::string m_name;
     std::string m_returnType;
     Flags m_flags;
     std::vector< std::shared_ptr< Unit > > m_body;
};

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const std::string& text );
    std::string compile( unsigned int level = 0 ) const = 0;
protected:
    std::string m_text;
};


#endif // UNIT_H
