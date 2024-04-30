#include "JsonFuncs.h"
#include "JsonParser.h"

json::JsonBase* json::parseString(const std::string& inputStr)
{
    sup::Parser object;
    return object.pars(inputStr);
}

