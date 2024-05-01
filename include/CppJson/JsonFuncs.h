#pragma once

/// @file JsonFuncs.h
/// @brief Файл с функциональной частью библиотеки
/// @version 0.1.0
/// @details В этом файле находятся функции, доступные для внешнего
/// использования, например: функция парсинга

#include "cppjson_export.h"
#include <string>

namespace json
{
    class JsonBase;

    /// @brief Метод парсинга строки
    /// @version 0.1.0
    /// @param Строка, которую нужно распарсерить
    /// @return Json-объект
    /// @todo 6: Ошибка парсинга
    CPPJSON_EXPORT JsonBase* parseString(const std::string&);

}

