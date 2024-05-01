#include "gtest/gtest.h"
#include "ObjectValueType.h"
#include <string>
#include <stdexcept>

using namespace json;

TEST(TestObjectValueType_AdvancedGetMethods, IntegerValue)
{
    int testValue = 5;
    ObjectValueType o = testValue;

    ASSERT_EQ(o.getInt(), testValue);
    ASSERT_EQ(o.getDouble(), double(testValue));
    ASSERT_EQ(o.getStr(), std::to_string(testValue));
}

TEST(TestObjectValueType_AdvancedGetMethods, DoubleValue)
{
    double testValue = 5.15;
    ObjectValueType o = testValue;

    ASSERT_EQ(o.getInt(), int(testValue));
    ASSERT_EQ(o.getDouble(), testValue);
    ASSERT_EQ(o.getStr(), std::to_string(testValue));
}

TEST(TestObjectValueType_AdvancedGetMethods, StringValue_Integer)
{
    int testNumber = 4;
    std::string testStrnig = std::to_string(testNumber);
    ObjectValueType o = testStrnig;

    ASSERT_EQ(o.getInt(), testNumber);
    ASSERT_EQ(o.getDouble(), double(testNumber));
    ASSERT_EQ(o.getStr(), testStrnig);
}

TEST(TestObjectValueType_AdvancedGetMethods, StringValue_Double)
{
    double testNumber = 4.5;
    std::string testStrnig = std::to_string(testNumber);
    ObjectValueType o = testStrnig;

    ASSERT_EQ(o.getInt(), int(testNumber));
    ASSERT_EQ(o.getDouble(), testNumber);
    ASSERT_EQ(o.getStr(), testStrnig);
}

TEST(TestObjectValueType_AdvancedGetMethods, DISABLED_StringValue_String)
{
    std::string testStrnig = "SomeText";
    ObjectValueType o = testStrnig;

    // todo 3: Отвалилась проверка на сброс ошибки. В метод не проваливается
    ASSERT_THROW([&o]() {o.getInt(); }, std::invalid_argument);
    ASSERT_THROW([&o]() {o.getDouble(); }, std::invalid_argument);
    ASSERT_EQ(o.getStr(), testStrnig);
}

TEST(TestObjectValueType_AdvancedGetMethods, DISABLED_NullObject)
{
    ObjectValueType o;
    o.setNull();

    // todo 3: Отвалилась проверка на сброс ошибки. В метод не проваливается
    ASSERT_THROW([=]() {o.getInt(); }, std::runtime_error);
    ASSERT_THROW([=]() {o.getDouble(); }, std::runtime_error);
    ASSERT_EQ(o.getStr(), std::string("null"));
}

TEST(TestObjectValueType_AdvancedGetMethods, DISABLED_UnvalideObject)
{
    ObjectValueType o;

    // todo 3: Отвалилась проверка на сброс ошибки. В метод не проваливается
    ASSERT_THROW([=]() {o.getInt(); }, std::runtime_error);
    ASSERT_THROW([=]() {o.getDouble(); }, std::runtime_error);
    ASSERT_THROW([=]() {o.getStr(); }, std::runtime_error);
}

TEST(TestObjectValueType_AdvancedGetMethods, BoolObject)
{
    bool testBool = true;
    ObjectValueType o = testBool;

    ASSERT_TRUE(o.isBool());
    ASSERT_EQ(testBool, o.getBool());
}

