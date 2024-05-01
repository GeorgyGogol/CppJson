#include "gtest/gtest.h"
#include "ObjectValueType.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "ValideMethods.h"
#include <string>

using namespace json;

class TestObjectValueType_ValuesWithJsonObject : public testing::Test
{
protected:
    t_utils::ValideMethods ValideMethodsCheck;
};

TEST_F(TestObjectValueType_ValuesWithJsonObject, BaseCreatingWithJsonObject)
{
    JsonObject o;
    o.add("Test");

    ObjectValueType ot(o);

    ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonObjectConditions());
}

TEST_F(TestObjectValueType_ValuesWithJsonObject, CreateAndDeleteWithJsonObject)
{
    ObjectValueType ot;

    {
        JsonObject o;
        o.add("Test");

        ot = ObjectValueType(o);

    }

    ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonObjectConditions());

    JsonObject res = ot.getJsonObject();
    ASSERT_EQ(1, res.count());
}

TEST_F(TestObjectValueType_ValuesWithJsonObject, BaseCreatingWithJsonArray)
{
    JsonArray o;
    o.add("Test");

    ObjectValueType ot(o);

    ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonArrayConditions());
}

TEST_F(TestObjectValueType_ValuesWithJsonObject, CreateAndDeleteWithJsonArray)
{
    ObjectValueType ot;

    {
        JsonArray o;
        o.add("Test");

        ot = ObjectValueType(o);

    }

    ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonArrayConditions());

    JsonArray res = ot.getJsonArray();
    ASSERT_EQ(1, res.count());
}

