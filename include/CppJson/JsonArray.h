#pragma once

/// @file JsonArray.h
/// @brief Файл с описанием Json массива

#include "cppjson_export.h"
#include "JsonBase.h"
#include "ObjectValueType.h"
#include <vector>
#include <string>

namespace json {

    /**
     * @brief Класс Josn массива
     * @version 0.1.0
     * @details Класс является представлением Json массива и
     * предоставляет интерфейс доступа к его элементам
    */
    class CPPJSON_EXPORT JsonArray
        : public JsonBase
    {
    public:
        JsonArray() = default;
        ~JsonArray() = default;

        JsonArray(const JsonArray& src) noexcept;
        JsonArray& operator=(const JsonArray& src) noexcept;
        JsonArray& operator=(JsonArray&& from) noexcept;

    private:
        /// @brief Определение типа хранилища объекта
        typedef std::vector<ObjectValueType> JsonArrayStorage;

        /// @brief Хранилище элементов массива
        JsonArrayStorage Storage;

        //ObjectValueType operator[](int pos) const;

    protected:

    public:
        /// @brief Метод добавления элемента массива
        /// @param [in] value Добавляемый (новый) элемент массива
        void add(ObjectValueType value) noexcept;

        /// @brief Метод установки элемента массива
        /// @param [in] pos Позиция, на которую элемент будет поставлен
        /// @param [in] value Значение, которое будет хранится на этой позиции
        void set(int pos, ObjectValueType value);


        /// @brief Метод получения элемента массива
        /// @param [in] pos Позиция элемента в массиве, который нужно получить
        /// @return Копия элемента массива
        /// @todo Ошибка, если обращение не на элемент
        ObjectValueType get(int pos) const;

        /// @brief Метод получения ссылки на элемент массива
        /// @param [in] pos Позиция элемента в массиве, который нужно получить
        /// @return Ссылка на элемент массива
        /// @todo Ошибка, если обращение не на элемент
        ObjectValueType& getRef(int pos);

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

