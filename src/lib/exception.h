
#pragma once
#include <exception>
#include <string>
 
namespace JP{
 
class EXCEPTION : public std::exception
{

    private:
        std::string _what;

    public:
        EXCEPTION();
        EXCEPTION(std::string);
        const char* what();
        virtual ~EXCEPTION() throw() {}
};
 
 
EXCEPTION::EXCEPTION()
{
    _what = "";
}
 
EXCEPTION::EXCEPTION(std::string what)
{
    _what = what;
}
 
 
const char* EXCEPTION::what()
{
    return _what.c_str();
}
 
 
}