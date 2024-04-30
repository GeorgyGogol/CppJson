#include <CppUnitTest.h>
#include "JsonObject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonObject {

    TEST_CLASS(BaseAddGetProperties)
    {
    public:
        TEST_METHOD(integerProperty) {
            JsonObject o;
            int testValue = 10;

            o.add("Test1", testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");
            
            int res = o.get("Test1").getInt();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");
        }

        TEST_METHOD(integerProperty_raw) {
            JsonObject o;

            o.add("Test1", 10);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");
            
            int res = o.get("Test1").getInt();
            Assert::AreEqual(10, res, L"Return value don't equal input value");
        }

        TEST_METHOD(doubleProperty) {
            JsonObject o;
            double testValue = 10;

            o.add("Test1", testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            double res = o.get("Test1").getDouble();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");
        }

        TEST_METHOD(stringProperty) {
            JsonObject o;
            std::string testValue = "SomeString";

            o.add("Test1", testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            std::string res = o.get("Test1").getStr();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");
        }

        TEST_METHOD(nullProperty) {
            JsonObject o;
            ObjectValueType n;
            n.setNull();

            o.add("Test1", n);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            Assert::IsTrue(o.get("Test1").isNull(), L"Return value don't equal input value");
        }

        TEST_METHOD(nullProperty_pureAdding) {
            JsonObject o;

            o.add("Test");
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            std::string res = o.get("Test").getStr();
            Assert::AreEqual("null", res.c_str(), L"Return value don't equal input value");
            Assert::IsTrue(o.get("Test").isNull(), L"Input value must change internal state to null");
        }

        TEST_METHOD(isExistProperty) {
            JsonObject o;
            std::string testValue = "SomeString";

            o.add(testValue, testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            Assert::IsTrue(o.isExists(testValue));
            Assert::IsFalse(o.isExists("SomeAnotherProperty"));
        }
    };

}

