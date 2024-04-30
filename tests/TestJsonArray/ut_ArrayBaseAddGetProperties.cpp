#include <CppUnitTest.h>
#include "JsonArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonArray {

    TEST_CLASS(BaseAddGetProperties)
    {
    public:
        TEST_METHOD(integerProperty) {
            JsonArray o;
            int testValue = 10;

            o.add(testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");
            
            int res = o.get(0).getInt();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");

            Assert::ExpectException<std::out_of_range>([=]() { o.get(1); });
        }

        TEST_METHOD(doubleProperty) {
            JsonArray o;
            double testValue = 10;

            o.add(testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            double res = o.get(0).getDouble();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");
        }

        TEST_METHOD(stringProperty) {
            JsonArray o;
            std::string testValue = "SomeString";

            o.add(testValue);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");

            std::string res = o.get(0).getStr();
            Assert::AreEqual(testValue, res, L"Return value don't equal input value");
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(nullProperty)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(nullProperty) {
            JsonArray o;
            ObjectValueType nullObject;
            nullObject.setNull();

            o.add(nullObject);
            Assert::AreEqual(1, o.count(), L"There are must be only one added property");
            Assert::IsTrue(o.get(0).isNull(), L"Expected return value null");
        }

    };

}

