#include "gtest/gtest.h"
#include "JsonObject.h"

using namespace json;

TEST(TestJsonObject_BaseAddGetProperties, integerProperty)
{
    JsonObject o;
    int testValue = 10;

    o.add("Test1", testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";
            
    int res = o.get("Test1").getInt();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";
}

TEST(TestJsonObject_BaseAddGetProperties, integerProperty_raw)
{
    JsonObject o;

    o.add("Test1", 10);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";
            
    int res = o.get("Test1").getInt();
    ASSERT_EQ(10, res) << "Return value don't equal input value";
}

TEST(TestJsonObject_BaseAddGetProperties, doubleProperty)
{
    JsonObject o;
    double testValue = 10;

    o.add("Test1", testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    double res = o.get("Test1").getDouble();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";
}

TEST(TestJsonObject_BaseAddGetProperties, stringProperty)
{
    JsonObject o;
    std::string testValue = "SomeString";

    o.add("Test1", testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    std::string res = o.get("Test1").getStr();
    ASSERT_EQ(testValue, res) << "Return value don't equal input value";
}

TEST(TestJsonObject_BaseAddGetProperties, nullProperty)
{
    JsonObject o;
    ObjectValueType n;
    n.setNull();

    o.add("Test1", n);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    ASSERT_TRUE(o.get("Test1").isNull()) << "Return value don't equal input value";
}

TEST(TestJsonObject_BaseAddGetProperties, DISABLED_nullProperty_pureAdding)
{
    // todo 2: Тест корректен, нужно сделать корректную валидацию строки
    JsonObject o;

    o.add("Test");
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    std::string res = o.get("Test").getStr();
    ASSERT_EQ("null", res.c_str()) << "Return value don't equal input value";
    ASSERT_TRUE(o.get("Test").isNull()) << "Input value must change internal state to null";
}

TEST(TestJsonObject_BaseAddGetProperties, isExistProperty)
{
    JsonObject o;
    std::string testValue = "SomeString";

    o.add(testValue, testValue);
    ASSERT_EQ(1, o.count()) << "There are must be only one added property";

    ASSERT_TRUE(o.isExists(testValue));
    ASSERT_FALSE(o.isExists("SomeAnotherProperty"));
}

