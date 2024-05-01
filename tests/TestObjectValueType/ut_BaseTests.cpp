#include "gtest/gtest.h"
#include "ObjectValueType.h"
#include "ValideMethods.h"
#include <string>

using namespace json;

class TestObjectValueType_BaseTests : public testing::Test
{
protected:
    t_utils::ValideMethods ValideMethodsCheck;

};

TEST_F(TestObjectValueType_BaseTests, DefaultCretateDelete)
{
    ObjectValueType t;
    ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNotValideConditions());
}

TEST_F(TestObjectValueType_BaseTests, IntInitMethod)
{
    int someValue = 5;
    ObjectValueType t = someValue;
    ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNumberConditions());
    ASSERT_EQ(t.getInt(), someValue);
}

TEST_F(TestObjectValueType_BaseTests, DoubleInitMethod)
{
    double someValue = 13.52;
    ObjectValueType t = someValue;
    ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNumberConditions());
    ASSERT_EQ(t.getDouble(), someValue);
}

TEST_F(TestObjectValueType_BaseTests, StrInitMethod)
{
    std::string someString = "SomeString";
    ObjectValueType stringObject = someString;
    ValideMethodsCheck.CheckConditionMethods(stringObject, ValideMethodsCheck.getStringConditions());
    ASSERT_EQ(stringObject.getStr(), someString);
}

TEST_F(TestObjectValueType_BaseTests, CharInitMethod)
{
    ObjectValueType charObject = "char";
    ValideMethodsCheck.CheckConditionMethods(charObject, ValideMethodsCheck.getStringConditions());
    ASSERT_EQ(charObject.getStr(), std::string("char"));

    /// @todo Корректное сравнение char*
    //ASSERT_TRUE(charObject.getStr().c_str() == "char");
}

TEST_F(TestObjectValueType_BaseTests, AssignObject)
{
    int checkValue = 5;
    std::string checkString = "SomeString";

    ObjectValueType t1, t2;

    t1 = checkValue;
    t2 = t1;
    ASSERT_EQ(t2.getInt(), checkValue);

    t2 = checkString;
    t1 = t2;
    ASSERT_EQ(t1.getStr(), checkString);
}

TEST_F(TestObjectValueType_BaseTests, DISABLED_NullObject)
{
    ObjectValueType t;
    t.setNull();
    ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNullConditions());
}

TEST_F(TestObjectValueType_BaseTests, BooleanInit)
{
    ObjectValueType t(true);
    ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getBoolArrayConditions());
    ASSERT_TRUE(t.getBool());
}

