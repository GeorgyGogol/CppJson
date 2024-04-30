#include <CppUnitTest.h>
#include "JsonBase.h"
#include "JsonFuncs.h"
#include "JsonObject.h"
#include "JsonArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestParser
{
    
    TEST_CLASS(ParserAdvanced)
    {
    public:
        TEST_METHOD(ParsObjectWithSubObject)
        {
            std::string toParse = "{\"Name\":\"PersonsName\",\"Count\":2,\"Vals\":{\"Jhon\":\"male\",\"Eva\":\"woman\"}}";
            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(json::JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(3, result->count(), L"Some property was lost, count not equal total input properties");

            json::JsonObject* o = static_cast<json::JsonObject*>(result);

            Assert::IsTrue(o->get("Name") == "PersonsName", L"In Test property Name must be PersonsName");
            Assert::IsTrue(o->get("Count") == 2, L"In Test property Count must be 2");
            Assert::IsTrue(o->isExists("Vals"), L"In Test property Vals exists");
            Assert::IsTrue(json::ValueTypes::JsonObject == o->get("Vals").getType(), L"Parsed sub object must be JSON object");

            json::JsonObject sub = o->get("Vals").getJsonObject();
            
            Assert::IsTrue(json::JsonType::Object == sub.Type(), L"Parsed sub object must be JSON object");
            Assert::AreEqual(2, sub.count(), L"Some property in sub object was lost, count not equal total input properties");

            Assert::IsTrue(sub.get("Jhon") == "male", L"In Test sub property Jhon must be male");
            Assert::IsTrue(sub.get("Eva") == "woman", L"In Test sub property Eva must be woman");

            delete result;
        }

    };

}

