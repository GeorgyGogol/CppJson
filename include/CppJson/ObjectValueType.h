#pragma once

/// @file ObjectValueType.h
/// @brief Файл с описанием типа, хранимого в Json

#include "cppjson_export.h"
#include <string>

namespace json {

    class JsonBase;
    class JsonObject;
    class JsonArray;

    /// @brief Перечисление допустимых типов
    /// @version 0.1.0
    enum class ValueTypes
    {
        None = -1,    ///< Not valid
        Null,         ///< Null значение
        Int,          ///< Целочисленное
        Double,       ///< Значение с плавающей точкой
        String,       ///< Строки
        Boolean,      ///< Логическое
        JsonObject,   ///< Json объект
        JsonArray     ///< Json массив
    };

    /**
     * @brief Класс хранимого значения
     * @version 0.1.0
     * @details Класс выступает хранилищем значения
    */
    class CPPJSON_EXPORT ObjectValueType
    {
    public:
        ObjectValueType();
        ~ObjectValueType();

        ObjectValueType(const ObjectValueType&) noexcept;
        ObjectValueType(ObjectValueType&&) noexcept;
        ObjectValueType& operator=(const ObjectValueType&) noexcept;
        bool operator==(const ObjectValueType&) const noexcept;
        bool operator!=(const ObjectValueType&) const noexcept;

        ObjectValueType(int) noexcept;
        ObjectValueType& operator=(int) noexcept;
        bool operator==(int) const noexcept;
        bool operator!=(int) const noexcept;

        ObjectValueType(double) noexcept;
        ObjectValueType& operator=(double) noexcept;
        bool operator==(double) const noexcept;
        bool operator!=(double) const noexcept;

        ObjectValueType(const char[]) noexcept;
        //ObjectValueType& operator=(const char[]) noexcept;
        bool operator==(const char[]) const noexcept;
        bool operator!=(const char[]) const noexcept;        

        ObjectValueType(const std::string&) noexcept;
        //ObjectValueType& operator=(const std::string&) noexcept;
        bool operator==(const std::string&) const noexcept;
        bool operator!=(const std::string&) const noexcept;

        ObjectValueType(bool) noexcept;
        ObjectValueType& operator=(bool) noexcept;
        bool operator==(bool) const noexcept;
        bool operator!=(bool) const noexcept;

        ObjectValueType(JsonBase*) noexcept;

        ObjectValueType(const JsonObject&) noexcept;
        //ObjectValueType& operator=(const JsonObject&) noexcept;
        //bool operator==(const JsonObject&) const noexcept;
        //bool operator!=(const JsonObject&) const noexcept;

        ObjectValueType(const JsonArray&) noexcept;
        //ObjectValueType& operator=(const JsonArray&) noexcept;
        //bool operator==(const JsonArray&) const noexcept;
        //bool operator!=(const JsonArray&) const noexcept;

    private:
        ValueTypes CurrentType = ValueTypes::None;
        double NumberData = 0;
        std::string StrData;
        JsonBase* pJson = nullptr;

        void CopyJsonBase(JsonBase*) noexcept;

    public:
        /// @name Методы определения хранимого значения
        /// @{
        ValueTypes getType() const noexcept;
        bool isValide() const noexcept;
        bool isNull() const noexcept;
        bool isNumber() const noexcept;
        bool isString() const noexcept;
        bool isBool() const noexcept;
        bool isJsonObject() const noexcept;
        bool isJsonArray() const noexcept;
        bool isJson() const noexcept;
        /// @}

        /// @name Методы получения хранимого значения
        /// @{
        int getInt() const;
        double getDouble() const;
        std::string getStr() const;
        bool getBool() const;
        JsonObject& getJsonObject() const;
        JsonArray& getJsonArray() const;
        /// @}

        /// @brief Метод установки значения Null
        void setNull() noexcept;

    };

}

