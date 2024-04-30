#pragma once

#include <memory>
#include <string>
#include "ObjectValueType.h"

namespace TestObjectValueType {

    class ValideMethods {
    private:
        const int nConditions = 7;
        std::unique_ptr<bool> NotValideConditions;
        std::unique_ptr<bool> NullConditions;
        std::unique_ptr<bool> NumberConditions;
        std::unique_ptr<bool> StringConditions;
        std::unique_ptr<bool> JsonObjectConditions;
        std::unique_ptr<bool> JsonArrayConditions;
        std::unique_ptr<bool> BooleanConditions;

        typedef bool (json::ObjectValueType::* ValideMethodPtr)() const;
        std::unique_ptr<ValideMethodPtr> Methods;

    public:
        ValideMethods();

        bool* getNotValideConditions() const { return NotValideConditions.get(); }
        bool* getNullConditions() const { return NullConditions.get(); }
        bool* getNumberConditions() const { return NumberConditions.get(); }
        bool* getStringConditions() const { return StringConditions.get(); }
        bool* getJsonObjectConditions() const { return JsonObjectConditions.get(); }
        bool* getJsonArrayConditions() const { return JsonArrayConditions.get(); }
        bool* getBoolArrayConditions() const { return BooleanConditions.get(); }

        void CheckConditionMethods(const json::ObjectValueType& o, bool* conditions);

    };

}

