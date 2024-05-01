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
    static JsonObject o;

    static void SetUpTestCase()
    {
        o.add("String", "String");
        o.add("Int", 5);
        o.add("Dob", 1.15);
        o.add("Bool", false);
    }
};

TEST_F(TestJsonObject_FieldAcess, Check_String)
{
    ASSERT_TRUE(o.get("String") == "String", L"Value must be string, string equals");
}

TEST_F(TestJsonObject_FieldAcess, Check_Integer)
{
    ASSERT_TRUE(o.get("Int") == 5, L"Value must be Int, Int equals");
}

TEST_F(TestJsonObject_FieldAcess, Check_Boolean)
{
    ASSERT_TRUE(o.get("Bool") == false, L"Value must be Boolean, Boolean equals");
}

