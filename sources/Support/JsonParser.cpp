#include "JsonParser.h"

#include <future>
#include <regex>

#include "JsonBase.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "ObjectValueType.h"

sup::Parser::Parser()
{
    // FuncMap
    FuncMap['{'] = &Parser::parseObject;
    FuncMap['['] = &Parser::parseArray;

    // ObjectsMap
    ObjectsMap['{'] = &Parser::getJsonObject;
    ObjectsMap['['] = &Parser::getJsonArray;
    ObjectsMap['\"'] = &Parser::getString;
    ObjectsMap['n'] = &Parser::getNull;
    ObjectsMap['t'] = &Parser::getTrue;
    ObjectsMap['f'] = &Parser::getFalse;

    isCanParse = false;
}

bool sup::Parser::checkString(const std::string &str) noexcept
{
    if (str[0] != '{' && str[0] != '[') return false;

    std::regex openWords("[{[]", std::regex_constants::ECMAScript);
    std::regex closeWords("[}\\]]", std::regex_constants::ECMAScript);

    int openCount = std::distance(std::sregex_iterator(str.begin(), str.end(), openWords), std::sregex_iterator());
    int closeCount = std::distance(std::sregex_iterator(str.begin(), str.end(), closeWords), std::sregex_iterator());

    return openCount == closeCount;
}

int sup::Parser::seekEndOfSub(const char *src, size_t size, const char open, const char close)
{
    int Level = 0;
    const char* end = src;

    for (end; end != 0; ++end) {
        if (*end == open) ++Level;
        else if (*end == close) --Level;

        if (Level <= 0) break;
    }

    return end - src + 1;
}

json::JsonBase* sup::Parser::parseObject(const char **inputStr, size_t& sizeStr)
{
    json::JsonObject* out = new json::JsonObject;
    if (**inputStr == '}') return out;

    while (isCanParse /*sizeStr + 1 > 0*/) // ???
    {
        std::string propName = getPropertyName(inputStr, sizeStr);
        json::ObjectValueType value = getPropertyValue(inputStr, sizeStr);

        out->add(propName, value);
        //if (*inputStr == 0) break;
    }

    return out;
}

json::JsonBase* sup::Parser::parseArray(const char **inputStr, size_t& sizeStr)
{
    json::JsonArray* out = new json::JsonArray;
    if (**inputStr == ']') return out;

    while (isCanParse  /**inputStr != 0 */ /*sizeStr + 1 > 0*/) // ???
    {
        out->add(getPropertyValue(inputStr, sizeStr));
        //if (*inputStr == 0) break;
    }

    return out;
}

std::string sup::Parser::getPropertyName(const char **str, size_t &sizeStr)
{
    int nextSymbol = seekSymbolPos(*str, sizeStr, ':');
    std::string propName = std::string(*str + 1, *str + nextSymbol - 1);
    moveCharPointer(str, sizeStr, nextSymbol);

    return propName;
}

json::ObjectValueType sup::Parser::getPropertyValue(const char **str, size_t &sizeStr)
{
    json::ObjectValueType value;
    ParsObjectFunction getFunction;
    
    getFunction = ObjectsMap[**str];
    if (getFunction == nullptr) getFunction = &Parser::getNumeric;

    value = (this->*getFunction)(str, sizeStr);

    return value;
}

void sup::Parser::moveCharPointer(const char **str, size_t &sizeStr, int value)
{
    isCanParse = int(sizeStr) - value - 1 > 0;

    *str += value + 1;
    sizeStr -= value + 1;
}

json::ObjectValueType sup::Parser::getJsonObject(const char **str, size_t &sizeStr)
{
    json::ObjectValueType out;
    int nextSymbol = seekEndOfSubObject(*str, sizeStr);

    (*str) += 1;
    sizeStr -= 2;
    json::JsonBase* sub = parseObject(str, sizeStr);
    out = *static_cast<json::JsonObject*>(sub);
    moveCharPointer(str, sizeStr, nextSymbol);

    return out;
}

json::ObjectValueType sup::Parser::getJsonArray(const char **str, size_t &sizeStr)
{
    json::ObjectValueType out;
    int nextSymbol = seekEndOfSubArray(*str, sizeStr);

    (*str) += 1;
    sizeStr -= 2;
    json::JsonBase* sub = parseArray(str, sizeStr);
    out = *static_cast<json::JsonArray*>(sub);
    moveCharPointer(str, sizeStr, nextSymbol);

    return out;
}

json::ObjectValueType sup::Parser::getString(const char **str, size_t &sizeStr)
{
    int nextSymbol = seekSymbolPos(*str, sizeStr, ',');

    json::ObjectValueType out = std::string((*str) + 1, (*str) + nextSymbol - 1);
    moveCharPointer(str, sizeStr, nextSymbol);

    return out;
}

json::ObjectValueType sup::Parser::getNull(const char **str, size_t &sizeStr)
{
    moveCharPointer(str, sizeStr, 4);
    json::ObjectValueType out;
    out.setNull();
    return out;
}

json::ObjectValueType sup::Parser::getTrue(const char **str, size_t &sizeStr)
{
    moveCharPointer(str, sizeStr, 4);
    return json::ObjectValueType(true);
}

json::ObjectValueType sup::Parser::getFalse(const char **str, size_t &sizeStr)
{
    moveCharPointer(str, sizeStr, 5);
    return json::ObjectValueType(false);
}

json::ObjectValueType sup::Parser::getNumeric(const char **str, size_t &sizeStr)
{
    int nextSymbol = seekSymbolPos(*str, sizeStr, ',');
    std::string someValue = std::string(*str, (*str) + nextSymbol);

    //std::regex digit("(\\d+)");
    std::regex digit("^\\d+\\.?\\d*$", std::regex_constants::ECMAScript);
    std::sregex_iterator r_it(someValue.begin(), someValue.end(), digit);
    
    json::ObjectValueType value;
    if (std::distance(r_it, std::sregex_iterator()) == 1)
    {
        if (someValue.find(".") != std::string::npos) {
            value = std::atof(someValue.c_str());
        }
        else {
            value = std::atoi(someValue.c_str());
        }
    }

    moveCharPointer(str, sizeStr, nextSymbol);

    return value;
}

json::JsonBase* sup::Parser::pars(const std::string &str)
{
    if (!checkString(str)) 
        throw std::future_error(std::future_errc());

    json::JsonBase* out = nullptr;
    isCanParse = true;

    ParsFunction function = FuncMap.at(str[0]);
    if (!function) throw std::future_error(std::future_errc());

    const char* charString = str.c_str() + 1;
    size_t size = str.size() - 2;
    //charString[size] = 0;
    out = (this->*function)(&charString, size);

    return out;
}

