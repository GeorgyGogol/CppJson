#include "gtest/gtest.h"
#include "CppJson.h"

#include <string>

using namespace json;

TEST(TestParser_ParserSimple_Object, ParsEmptyString)
{
    std::string toParse = "";

    ASSERT_THROW([=]() { json::parseString(toParse); }, std::runtime_error);
}

TEST(TestParser_ParserSimple_Object, ParsEmpty)
{
    std::string toParse = "{}";

    json::JsonBase* ob = json::parseString(toParse);

    ASSERT_TRUE(ob->Type() == JsonType::Object) << "Object must be JsonObject";
    ASSERT_EQ(0, ob->count()) << "Object must be empty";

    delete ob;
}

TEST(TestParser_ParserSimple_Object, OnlyOneFieldText) {
    std::string toParse = "{\"One\":\"1\"}";

    JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonObject* o = static_cast<JsonObject*>(result);

    ASSERT_TRUE(o->isExists("One")) << "Input string has property One, witch been lost :(";
    ASSERT_TRUE(o->get("One") == "1") << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Object, OnlyOneFieldInt) {
    std::string toParse = "{\"One\":1}";

    JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonObject* o = static_cast<JsonObject*>(result);

    ASSERT_TRUE(o->isExists("One")) << "Input string has property One, witch been lost :(";
    ASSERT_TRUE(o->get("One").isNumber()) << "In this case property is number";
    ASSERT_TRUE(o->get("One") == 1) << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Object, OnlyOneFieldDouble) {
    std::string toParse = "{\"One\":1.050000}";

    JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonObject* o = static_cast<JsonObject*>(result);

    ASSERT_TRUE(o->isExists("One")) << "Input string has property One, witch been lost :(";
    ASSERT_TRUE(o->get("One").isNumber()) << "In this case property is number";
    ASSERT_TRUE(o->get("One") == 1.05) << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Object, Fields_OnlyText)
{
    const int nProps = 4;
    std::string props[4]{ "One", "Two", "Tree", "Four" };
    std::string vals[4]{ "10", "SomeString", "45.550000", "null" };
            
    std::string toParse = "{\"Four\":\"null\",\"One\":\"10\",\"Tree\":\"45.550000\",\"Two\":\"SomeString\"}";
    JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(nProps, result->count()) << "Some property was lost, count not equal total input properties";

    JsonObject* o = static_cast<JsonObject*>(result);

    for (int i = 0; i < nProps; ++i) {
        ASSERT_TRUE(o->isExists(props[i])) << "Some property is lost :(";
        ASSERT_EQ(vals[i], o->get(props[i]).getStr()) << "Property value lost";
    }

    delete result;
}

TEST(TestParser_ParserSimple_Object, Fields_Multi)
{
    std::string toParse = "{\"Name\":\"PersonsName\",\"Count\":2,\"IsValide\":true,\"Empty\":null}";
    JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(4, result->count()) << "Some property was lost, count not equal total input properties";

    JsonObject* o = static_cast<JsonObject*>(result);

    // TODO: optimize

    ASSERT_FALSE(o->isExists("One")) << "Input string hasnt property One";

    ASSERT_TRUE(o->isExists("Name")) << "Input string has property Name, witch been lost :(";
    ASSERT_TRUE(o->get("Name").isString()) << "In this case property Name is string";
    ASSERT_TRUE(o->get("Name") == "PersonsName") << "Property value lost";

    ASSERT_TRUE(o->isExists("Count")) << "Input string has property Count, witch been lost :(";
    ASSERT_TRUE(o->get("Count").isNumber()) << "In this case property Count is number";
    ASSERT_TRUE(o->get("Count") == 2) << "Property value lost";

    ASSERT_TRUE(o->isExists("IsValide")) << "Input string has property IsValide, witch been lost :(";
    ASSERT_TRUE(o->get("IsValide").isBool()) << "In this case property IsValide is boolean";
    ASSERT_TRUE(o->get("IsValide") == true) << "Property value lost";

    ASSERT_TRUE(o->isExists("Empty")) << "Input string has property Empty, witch been lost :(";
    ASSERT_TRUE(o->get("Empty").isNull()) << "In this case property Empty is Null";

    delete result;
}


TEST(TestParser_ParserSimple_Array, ParsEmptyString)
{
    std::string toParse = "";

    // Ожидается эксепшн, все верно, поч падает???
    ASSERT_THROW([=]() { json::parseString(toParse); }, std::runtime_error);
}

TEST(TestParser_ParserSimple_Array, ParsEmpty)
{
    std::string toParse = "[]";

    json::JsonBase* ob = json::parseString(toParse);

    ASSERT_TRUE(ob->Type() == JsonType::Array) << "Object must be JsonArray";
    ASSERT_EQ(0, ob->count()) << "Arary must be empty";

    delete ob;
}

TEST(TestParser_ParserSimple_Array, OnlyOneText)
{
    std::string toParse = "[\"One\"]";

    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Array == result->Type()) << "Parsed object must be JSON array";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonArray* o = static_cast<JsonArray*>(result);

    ASSERT_TRUE(o->get(0) == "One") << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Array, OnlyOneInt)
{
    std::string toParse = "[1]";

    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Array == result->Type()) << "Parsed object must be JSON array";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonArray* o = static_cast<JsonArray*>(result);

    ASSERT_TRUE(o->get(0) == 1) << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Array, OnlyOneDouble)
{
    std::string toParse = "[1.05]";

    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Array == result->Type()) << "Parsed object must be JSON array";
    ASSERT_EQ(1, result->count()) << "Some property was lost, count not equal total input properties";

    JsonArray* o = static_cast<JsonArray*>(result);

    ASSERT_TRUE(o->get(0) == 1.05) << "Property value lost";

    delete result;
}

TEST(TestParser_ParserSimple_Array, Fields_TextOnly)
{
    std::string toParse = "[\"0\",\"1\",\"2\",\"3\"]";

    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Array == result->Type()) << "Parsed object must be JSON array";
    ASSERT_EQ(4, result->count()) << "Some property was lost, count not equal total input properties";

    JsonArray* o = static_cast<JsonArray*>(result);

    for (int i = 0; i < 3; ++i) {
        ASSERT_TRUE(o->get(i).getStr() == std::to_string(i)) << "Property value lost";
    }

    delete result;
}

TEST(TestParser_ParserSimple_Array, Fields_Multi)
{
    std::string toParse = "[\"0\",\"1\",\"2\",\"3\",4,5,6,7.0,8.0,9.0,null,true]";

    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(JsonType::Array == result->Type()) << "Parsed object must be JSON array";
    ASSERT_EQ(12, result->count()) << "Some property was lost, count not equal total input properties";

    JsonArray* o = static_cast<JsonArray*>(result);

    int i = 4;
    for (i; i < 4 + 3; ++i) {
        ASSERT_TRUE(o->get(i) == i) << "Property value lost";
    }

    for (i; i < 4 + 3 + 3; ++i) {
        ASSERT_TRUE(o->get(i) == double(i)) << "Property value lost";
    }

    ASSERT_TRUE(o->get(i).isNull()) << "Must be null";
    ++i;

    ASSERT_TRUE(o->get(i).getBool()) << "Must be true";

    delete result;
}

