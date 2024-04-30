#pragma once

/// @file JsonBase.h
/// @brief Файл с базовым определением Json-объекта
/// @version 0.1.0

#include "cppjson_export.h"
#include <string>

/// @brief Пространство имен библиотеки для работы с Json форматом
namespace json {

    /// @brief Перечисление типов Json-объектов
    /// @details Перечисление позволяет использовать switch
    /// @todo Подумать над выносом в отдельный файл
    enum class JsonType
    {
        Object,     ///< Json объект
        Array       ///< Json перечисление
    };

    /**
     * @brief Основной класс для Json-объектов
     * @version 0.1.0
     * @details Этот класс предоставляет базовый интерфейс для как
     * минимум определения типа объекта для дальнейшего
     * преобразования и работы
    */
    class CPPJSON_EXPORT JsonBase
    {
    public:
        JsonBase() = default;
        virtual ~JsonBase() = default;

    private:

    public:
        /// @brief Метод определения типа объекта
        /// @return Тип объекта
        virtual JsonType Type() const noexcept = 0;

        /// @brief Метод для конвертации в строку
        /// @return Строка с Json
        virtual std::string toString() const noexcept = 0;

        /// @brief Метод определения размера
        /// @return Размер
        virtual int count() const noexcept = 0;

    };

}

