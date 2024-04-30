#pragma once

/// @file JsonObject.h
/// @brief Файл с объектом Json

#include "cppjson_export.h"
#include "JsonBase.h"
#include "ObjectValueType.h"
#include <map>
#include <string>

namespace json {

    /**
     * @brief Класс объекта Json
     * @version 0.1.0
     * @details Класс является представлением объекта Json и
     * предоставляет интерфейс доступа к его элементам
    */
    class CPPJSON_EXPORT JsonObject
        : public JsonBase
    {
    public:
        JsonObject() = default;
        ~JsonObject() = default;
        
        JsonObject(const JsonObject& src) noexcept;
        JsonObject& operator=(const JsonObject& src) noexcept;
        JsonObject& operator=(JsonObject&& from) noexcept;

    private:
        /// @brief Определение типа хранилища объекта
        typedef std::map<std::string, ObjectValueType> JsonPropStorage;

        /// @brief Хранилище элементов массива
        JsonPropStorage JsonProperties;

    public:
        /// @brief Метод добавления свойства
        /// @param [in] propertyName Название свойства
        /// @param [in] value Значение свойства
        void add(const std::string& propertyName, ObjectValueType value) noexcept;

        /// @brief Метод добавления Null-свойства
        /// @param [in] propertyName Название свойства
        void add(const std::string& propertyName) noexcept;

        /// @brief Метод установки свойства
        /// @note Если свойства не было, оно будет создано
        /// @param [in] propertyName Название свойства
        /// @param [in] value Значение свойства
        void set(const std::string& propertyName, ObjectValueType value) noexcept;


        /// @brief Метод получения свойства
        /// @param [in] propertyName Название свойства
        /// @return Копия хранимого значения
        ObjectValueType get(const std::string& propertyName) const noexcept;

        /// @brief Метод получения свойства
        /// @param [in] propertyName Название свойства
        /// @return Ссылка на значение хранимого значения
        ObjectValueType& getRef(const std::string& propertyName);

        /// @brief Метод проверки существования свойства
        /// @param [in] propertyName Название свойства
        /// @return True, если свойство есть
        bool isExists(const std::string& propertyName) const noexcept;

#pragma region JsonBase
        /// @name JsonBase
        /// @{
        JsonType Type() const noexcept override;
        std::string toString() const noexcept override;
        int count() const noexcept override;
        /// @}
#pragma endregion
        
    };

}

