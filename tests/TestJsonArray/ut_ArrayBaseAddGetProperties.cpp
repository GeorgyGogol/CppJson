#include "gtest/gtest.h"
#include "JsonArray.h"

using namespace json;

TEST(TestJsonArray_BaseAddGetProperties, DISABLED_integerProperty)
{
    JsonArray o;
    int testValue = 10;

    o.add(testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    int res = o.get(0).getInt();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";

    // todo 1: Определиться, нужно ли здесь исключение или нет
    ASSERT_THROW([&o]() { o.get(1); }, std::out_of_range);
}

TEST(TestJsonArray_BaseAddGetProperties, doubleProperty)
{
    JsonArray o;
    double testValue = 10;

    o.add(testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    double res = o.get(0).getDouble();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";
}

TEST(TestJsonArray_BaseAddGetProperties, stringProperty)
{
    JsonArray o;
    std::string testValue = "SomeString";

    o.add(testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    std::string res = o.get(0).getStr();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";
}

TEST(TestJsonArray_BaseAddGetProperties, nullProperty)
{
    JsonArray o;
    ObjectValueType nullObject;
    nullObject.setNull();

    o.add(nullObject);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";
    ASSERT_TRUE(o.get(0).isNull()) << "Expected return value null";
}

