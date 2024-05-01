#include "gtest/gtest.h"
#include "JsonObject.h"
#include "CppJson.h"

using namespace json;

class TestJsonObject_FieldAcess : public testing::Test
{
public:
    TestJsonObject_FieldAcess()
    {

    }

protected:
    static JsonObject testObject;

    static void SetUpTestCase()
    {
        testObject.add("String", "String");
        testObject.add("Int", 5);
        testObject.add("Dob", 1.15);
        testObject.add("Bool", false);
    }
};

JsonObject TestJsonObject_FieldAcess::testObject;

TEST_F(TestJsonObject_FieldAcess, Check_String)
{
    ASSERT_TRUE(testObject.get("String") == "String") << "Value must be string, string equals";
}

TEST_F(TestJsonObject_FieldAcess, Check_Integer)
{
    ASSERT_TRUE(testObject.get("Int") == 5) << "Value must be Int, Int equals";
}

TEST_F(TestJsonObject_FieldAcess, Check_Boolean)
{
    ASSERT_TRUE(testObject.get("Bool") == false) << "Value must be Boolean, Boolean equals";
}

