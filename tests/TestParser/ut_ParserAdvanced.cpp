#include "gtest/gtest.h"
#include "JsonBase.h"
#include "JsonFuncs.h"
#include "JsonObject.h"
#include "JsonArray.h"

TEST(TestParser_ParserAdvanced, DISABLED_ParsObjectWithSubObject)
{
    std::string toParse = "{\"Name\":\"PersonsName\",\"Count\":2,\"Vals\":{\"Jhon\":\"male\",\"Eva\":\"woman\"}}";
    json::JsonBase* result = json::parseString(toParse);

    ASSERT_TRUE(json::JsonType::Object == result->Type()) << "Parsed object must be JSON object";
    ASSERT_EQ(3, result->count()) << "Some property was lost, count not equal total input properties";

    json::JsonObject* o = static_cast<json::JsonObject*>(result);

    ASSERT_TRUE(o->get("Name") == "PersonsName") << "In Test property Name must be PersonsName";
    ASSERT_TRUE(o->get("Count") == 2) << "In Test property Count must be 2";
    ASSERT_TRUE(o->isExists("Vals")) << "In Test property Vals exists";
    ASSERT_TRUE(json::ValueTypes::JsonObject == o->get("Vals").getType()) << "Parsed sub object must be JSON object";

    json::JsonObject sub = o->get("Vals").getJsonObject();

    ASSERT_TRUE(json::JsonType::Object == sub.Type()) << "Parsed sub object must be JSON object";
    ASSERT_EQ(2, sub.count()) << "Some property in sub object was lost, count not equal total input properties";

    ASSERT_TRUE(sub.get("Jhon") == "male") << "In Test sub property Jhon must be male";
    ASSERT_TRUE(sub.get("Eva") == "woman") << "In Test sub property Eva must be woman";

    delete result;
}

