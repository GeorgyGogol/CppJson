#include <CppUnitTest.h>
//#include "Json.h"
#include "CppJson.h"

#include <string>
#include <future>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace sup::pars;
using namespace json;

namespace TestParser
{
    
    TEST_CLASS(ParserSimple_Object)
    {
    public:

        BEGIN_TEST_METHOD_ATTRIBUTE(ParsEmptyString)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(ParsEmptyString)
        {
            std::string toParse = "";

            // Ожидается эксепшн, все верно, поч падает???
            Assert::ExpectException<std::future_error(std::error_code())>([=]() { json::parseString(toParse); });
        }

        TEST_METHOD(ParsEmpty)
        {
            std::string toParse = "{}";

            json::JsonBase* ob = json::parseString(toParse);

            Assert::IsTrue(ob->Type() == JsonType::Object, L"Object must be JsonObject");
            Assert::AreEqual(0, ob->count(), L"Object must be empty");

            delete ob;
        }

        TEST_METHOD(OnlyOneFieldText) {
            std::string toParse = "{\"One\":\"1\"}";

            JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonObject* o = static_cast<JsonObject*>(result);

            Assert::IsTrue(o->isExists("One"), L"Input string has property One, witch been lost :(");
            Assert::IsTrue(o->get("One") == "1", L"Property value lost");

            delete result;
        }

        TEST_METHOD(OnlyOneFieldInt) {
            std::string toParse = "{\"One\":1}";

            JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonObject* o = static_cast<JsonObject*>(result);

            Assert::IsTrue(o->isExists("One"), L"Input string has property One, witch been lost :(");
            Assert::IsTrue(o->get("One").isNumber(), L"In this case property is number");
            Assert::IsTrue(o->get("One") == 1, L"Property value lost");

            delete result;
        }

        TEST_METHOD(OnlyOneFieldDouble) {
            std::string toParse = "{\"One\":1.050000}";

            JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonObject* o = static_cast<JsonObject*>(result);

            Assert::IsTrue(o->isExists("One"), L"Input string has property One, witch been lost :(");
            Assert::IsTrue(o->get("One").isNumber(), L"In this case property is number");
            Assert::IsTrue(o->get("One") == 1.05, L"Property value lost");

            delete result;
        }

        TEST_METHOD(Fields_OnlyText)
        {
            const int nProps = 4;
            std::string props[4]{ "One", "Two", "Tree", "Four" };
            std::string vals[4]{ "10", "SomeString", "45.550000", "null" };
            
            std::string toParse = "{\"Four\":\"null\",\"One\":\"10\",\"Tree\":\"45.550000\",\"Two\":\"SomeString\"}";
            JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(nProps, result->count(), L"Some property was lost, count not equal total input properties");

            JsonObject* o = static_cast<JsonObject*>(result);

            for (int i = 0; i < nProps; ++i) {
                Assert::IsTrue(o->isExists(props[i]), L"Some property is lost :(");
                Assert::AreEqual(vals[i], o->get(props[i]).getStr(), L"Property value lost");
            }

            delete result;
        }

        TEST_METHOD(Fields_Multi)
        {
            std::string toParse = "{\"Name\":\"PersonsName\",\"Count\":2,\"IsValide\":true,\"Empty\":null}";
            JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Object == result->Type(), L"Parsed object must be JSON object");
            Assert::AreEqual(4, result->count(), L"Some property was lost, count not equal total input properties");

            JsonObject* o = static_cast<JsonObject*>(result);

            // TODO: optimize

            Assert::IsFalse(o->isExists("One"), L"Input string hasnt property One");

            Assert::IsTrue(o->isExists("Name"), L"Input string has property Name, witch been lost :(");
            Assert::IsTrue(o->get("Name").isString(), L"In this case property Name is string");
            Assert::IsTrue(o->get("Name") == "PersonsName", L"Property value lost");

            Assert::IsTrue(o->isExists("Count"), L"Input string has property Count, witch been lost :(");
            Assert::IsTrue(o->get("Count").isNumber(), L"In this case property Count is number");
            Assert::IsTrue(o->get("Count") == 2, L"Property value lost");

            Assert::IsTrue(o->isExists("IsValide"), L"Input string has property IsValide, witch been lost :(");
            Assert::IsTrue(o->get("IsValide").isBool(), L"In this case property IsValide is boolean");
            Assert::IsTrue(o->get("IsValide") == true, L"Property value lost");

            Assert::IsTrue(o->isExists("Empty"), L"Input string has property Empty, witch been lost :(");
            Assert::IsTrue(o->get("Empty").isNull(), L"In this case property Empty is Null");

            delete result;
        }

    };

    TEST_CLASS(ParserSimple_Array)
    {
    public:
        BEGIN_TEST_METHOD_ATTRIBUTE(ParsEmptyString)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(ParsEmptyString)
        {
            std::string toParse = "";

            // Ожидается эксепшн, все верно, поч падает???
            Assert::ExpectException<std::future_error(std::error_code())>([=]() { json::parseString(toParse); });
        }

        TEST_METHOD(ParsEmpty)
        {
            std::string toParse = "[]";

            json::JsonBase* ob = json::parseString(toParse);

            Assert::IsTrue(ob->Type() == JsonType::Array, L"Object must be JsonArray");
            Assert::AreEqual(0, ob->count(), L"Arary must be empty");

            delete ob;
        }

        TEST_METHOD(OnlyOneText)
        {
            std::string toParse = "[\"One\"]";

            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Array == result->Type(), L"Parsed object must be JSON array");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonArray* o = static_cast<JsonArray*>(result);

            Assert::IsTrue(o->get(0) == "One", L"Property value lost");

            delete result;
        }

        TEST_METHOD(OnlyOneInt)
        {
            std::string toParse = "[1]";

            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Array == result->Type(), L"Parsed object must be JSON array");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonArray* o = static_cast<JsonArray*>(result);

            Assert::IsTrue(o->get(0) == 1, L"Property value lost");

            delete result;
        }

        TEST_METHOD(OnlyOneDouble)
        {
            std::string toParse = "[1.05]";

            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Array == result->Type(), L"Parsed object must be JSON array");
            Assert::AreEqual(1, result->count(), L"Some property was lost, count not equal total input properties");

            JsonArray* o = static_cast<JsonArray*>(result);

            Assert::IsTrue(o->get(0) == 1.05, L"Property value lost");

            delete result;
        }

        TEST_METHOD(Fields_TextOnly)
        {
            std::string toParse = "[\"0\",\"1\",\"2\",\"3\"]";

            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Array == result->Type(), L"Parsed object must be JSON array");
            Assert::AreEqual(4, result->count(), L"Some property was lost, count not equal total input properties");

            JsonArray* o = static_cast<JsonArray*>(result);

            for (int i = 0; i < 3; ++i) {
                Assert::IsTrue(o->get(i).getStr() == std::to_string(i), L"Property value lost");
            }

            delete result;
        }

        TEST_METHOD(Fields_Multi)
        {
            std::string toParse = "[\"0\",\"1\",\"2\",\"3\",4,5,6,7.0,8.0,9.0,null,true]";

            json::JsonBase* result = json::parseString(toParse);

            Assert::IsTrue(JsonType::Array == result->Type(), L"Parsed object must be JSON array");
            Assert::AreEqual(12, result->count(), L"Some property was lost, count not equal total input properties");

            JsonArray* o = static_cast<JsonArray*>(result);

            int i = 4;
            for (i; i < 4 + 3; ++i) {
                Assert::IsTrue(o->get(i) == i, L"Property value lost");
            }

            for (i; i < 4 + 3 + 3; ++i) {
                Assert::IsTrue(o->get(i) == double(i), L"Property value lost");
            }

            Assert::IsTrue(o->get(i).isNull(), L"Must be null");
            ++i;

            Assert::IsTrue(o->get(i).getBool(), L"Must be true");

            delete result;
        }

    };

}

