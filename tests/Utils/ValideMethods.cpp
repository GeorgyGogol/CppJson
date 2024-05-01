#include "ValideMethods.h"
#include "gtest/gtest.h"

t_utils::ValideMethods::ValideMethods()
    : NotValideConditions(new bool[nConditions] { false, false, false, false, false, false, false })
    , NullConditions(new bool[nConditions] { true, true, false, false, false, false, false })
    , NumberConditions(new bool[nConditions] { true, false, true, false, false, false, false })
    , StringConditions(new bool[nConditions] { true, false, false, true, false, false, false })
    , JsonObjectConditions(new bool[nConditions] { true, false, false, false, true, false, false })
    , JsonArrayConditions(new bool[nConditions] { true, false, false, false, false, true, false })
    , BooleanConditions(new bool[nConditions] { true, false, false, false, false, false, true })
    , Methods(new ValideMethodPtr [nConditions])
{
    Methods.get()[0] = &json::ObjectValueType::isValide;
    Methods.get()[1] = &json::ObjectValueType::isNull;
    Methods.get()[2] = &json::ObjectValueType::isNumber;
    Methods.get()[3] = &json::ObjectValueType::isString;
    Methods.get()[4] = &json::ObjectValueType::isJsonObject;
    Methods.get()[5] = &json::ObjectValueType::isJsonArray;
    Methods.get()[6] = &json::ObjectValueType::isBool;
}

void t_utils::ValideMethods::CheckConditionMethods(const json::ObjectValueType& o, bool* conditions)
{
    for (int i = 0; i < nConditions; ++i) {
        ASSERT_EQ(conditions[i], (o.*(Methods.get()[i]))() );
    }
}

