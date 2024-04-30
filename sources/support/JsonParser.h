#pragma once

/// @file JsonParser.h
/// @brief Файл с классом для парсинга строки

#include <string>
#include <map>

#include "ObjectValueType.h"

namespace json {
    class JsonBase;
}

namespace sup {

    /**
     * @brief Класс парсера строк
     * @version 0.1.0
     * @details Вспомогательный класс для парсинга строки
    */
    class Parser
    {
    public:
        Parser();
        ~Parser() = default;

    public:
        typedef json::JsonBase* (Parser::* ParsFunction)(const char**, size_t&);
        typedef std::map<const char, ParsFunction> ParsFunctionsMap;

        typedef json::ObjectValueType (Parser::* ParsObjectFunction)(const char**, size_t&);
        typedef std::map<const char, ParsObjectFunction> ParsObjectMap;

    private:
        bool checkString(const std::string &str) noexcept;
        int seekEndOfSub(const char* src, size_t size, const char open, const char close);
        inline int seekEndOfSubObject(const char* src, size_t size) {
            return seekEndOfSub(src, size, '{', '}');
        }
        inline int seekEndOfSubArray(const char* src, size_t size) {
            return seekEndOfSub(src, size, '[', ']');
        }

        inline int seekSymbolPos(const char* inputStr, size_t sizeStr, const char symbol)
        {
            return std::find(inputStr, inputStr + sizeStr, symbol) - inputStr;
        }

        ParsFunctionsMap FuncMap;
        json::JsonBase* parseObject(const char** inputStr, size_t& sizeStr);
        json::JsonBase* parseArray(const char** inputStr, size_t& sizeStr);

        std::string getPropertyName(const char** str, size_t& sizeStr);
        json::ObjectValueType getPropertyValue(const char** str, size_t& sizeStr);
        void moveCharPointer(const char** str, size_t& sizeStr, int value);

        ParsObjectMap ObjectsMap;
        json::ObjectValueType getJsonObject(const char** str, size_t& sizeStr);
        json::ObjectValueType getJsonArray(const char** str, size_t& sizeStr);
        json::ObjectValueType getString(const char** str, size_t& sizeStr);
        json::ObjectValueType getNull(const char** str, size_t& sizeStr);
        json::ObjectValueType getTrue(const char** str, size_t& sizeStr);
        json::ObjectValueType getFalse(const char** str, size_t& sizeStr);
        json::ObjectValueType getNumeric(const char** str, size_t& sizeStr);

        bool isCanParse;

    public:
        json::JsonBase* pars(const std::string& str);

    };

}

