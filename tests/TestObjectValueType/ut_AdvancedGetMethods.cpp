#include <CppUnitTest.h>
#include "ObjectValueType.h"
#include <string>
#include <future>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestObjectValueType {

    TEST_CLASS(AdvancedGetMethods)
    {
    private:

    public:
        TEST_METHOD(IntegerValue) {
            int testValue = 5;
            ObjectValueType o = testValue;

            Assert::AreEqual(o.getInt(), testValue);
            Assert::AreEqual(o.getDouble(), double(testValue));
            Assert::AreEqual(o.getStr(), std::to_string(testValue));
        }

        TEST_METHOD(DoubleValue) {
            double testValue = 5.15;
            ObjectValueType o = testValue;

            Assert::AreEqual(o.getInt(), int(testValue));
            Assert::AreEqual(o.getDouble(), testValue);
            Assert::AreEqual(o.getStr(), std::to_string(testValue));
        }

        TEST_METHOD(StringValue_Integer) {
            int testNumber = 4;
            std::string testStrnig = std::to_string(testNumber);
            ObjectValueType o = testStrnig;

            Assert::AreEqual(o.getInt(), testNumber);
            Assert::AreEqual(o.getDouble(), double(testNumber));
            Assert::AreEqual(o.getStr(), testStrnig);
        }

        TEST_METHOD(StringValue_Double) {
            double testNumber = 4.5;
            std::string testStrnig = std::to_string(testNumber);
            ObjectValueType o = testStrnig;

            Assert::AreEqual(o.getInt(), int(testNumber));
            Assert::AreEqual(o.getDouble(), testNumber);
            Assert::AreEqual(o.getStr(), testStrnig);
        }

        TEST_METHOD(StringValue_String) {
            std::string testStrnig = "SomeText";
            ObjectValueType o = testStrnig;

            Assert::ExpectException<std::invalid_argument>([=]() {o.getInt(); });
            Assert::ExpectException<std::invalid_argument>([=]() {o.getDouble(); });
            Assert::AreEqual(o.getStr(), testStrnig);
        }

        TEST_METHOD(NullObject) {
            ObjectValueType o;
            o.setNull();

            Assert::ExpectException<std::runtime_error>([=]() {o.getInt(); });
            Assert::ExpectException<std::runtime_error>([=]() {o.getDouble(); });
            Assert::AreEqual(o.getStr(), std::string("null"));
        }

        TEST_METHOD(UnvalideObject) {
            ObjectValueType o;

            Assert::ExpectException<std::runtime_error>([=]() {o.getInt(); });
            Assert::ExpectException<std::runtime_error>([=]() {o.getDouble(); });
            Assert::ExpectException<std::runtime_error>([=]() {o.getStr(); });
        }

        TEST_METHOD(BoolObject) {
            bool testBool = true;
            ObjectValueType o = testBool;

            Assert::IsTrue(o.isBool());
            Assert::AreEqual(testBool, o.getBool());
        }


    };

}

