#include <CppUnitTest.h>
#include "ObjectValueType.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestObjectValueType {

    TEST_CLASS(EqualOperatorsTests)
    {
    public:
        TEST_METHOD(EqualsOnlyIntCheck) {
            ObjectValueType t1;
            int checkValue = 5;
            t1 = checkValue;
            Assert::IsTrue(t1 == checkValue);
            Assert::IsFalse(t1 != checkValue);
        }

        TEST_METHOD(EqualsOnlyDoubleCheck) {
            ObjectValueType t1;
            double checkValue = 15.149456;
            t1 = checkValue;
            Assert::IsTrue(t1 == checkValue);
            Assert::IsFalse(t1 != checkValue);
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(EqualOnlyStrCheck)
            //TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(EqualOnlyStrCheck) {
            ObjectValueType t1;
            std::string checkValue = "SomeString";
            t1 = checkValue;
            Assert::IsTrue(t1 == checkValue);
            Assert::IsFalse(t1 != checkValue);
        }

        TEST_METHOD(EqualObjects) {
            ObjectValueType t1, t2, t3;
            int checkValue1 = 5;
            t1 = checkValue1;
            t2 = checkValue1;

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 != t2);

            Assert::IsFalse(t1 == t3);
            Assert::IsTrue(t1 != t3);
            Assert::IsFalse(t2 == t3);
            Assert::IsTrue(t2 != t3);
        }

        TEST_METHOD(EqualObjects2) {
            ObjectValueType t1, t2, t3;
            int checkValue1 = 5;
            t1 = checkValue1;
            t2 = checkValue1;
            t3 = "SomeString";

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 != t2);

            Assert::IsFalse(t1 == t3);
            Assert::IsTrue(t1 != t3);
            Assert::IsFalse(t2 == t3);
            Assert::IsTrue(t2 != t3);
        }

        TEST_METHOD(EqualObjects3) {
            ObjectValueType t1, t2, t3;
            int checkValue1 = 5;
            t1 = checkValue1;
            t2 = checkValue1;
            t3 = 12.5;

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 != t2);

            Assert::IsFalse(t1 == t3);
            Assert::IsTrue(t1 != t3);
            Assert::IsFalse(t2 == t3);
            Assert::IsTrue(t2 != t3);
        }

        TEST_METHOD(EqualObjects4) {
            ObjectValueType t1, t2, t3;
            int checkValue1 = 5;
            t1 = checkValue1;
            t2 = checkValue1;
            t3 = 5.0;

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 != t2);

            Assert::IsFalse(t1 == t3);
            Assert::IsTrue(t1 != t3);
            Assert::IsFalse(t2 == t3);
            Assert::IsTrue(t2 != t3);
        }

        TEST_METHOD(NotEqualObjects) {
            ObjectValueType t1, t2;
            t1 = 4;
            t2 = "someString";

            Assert::IsFalse(t1 == t2);
            Assert::IsTrue(t1 != t2);
        }

        TEST_METHOD(EqualsOnlyBool) {
            ObjectValueType t;
            t = false;

            Assert::IsFalse(t == true);
            Assert::IsTrue(t == false);
            
            Assert::IsTrue(t != true);
            Assert::IsFalse(t != false);
        }

        TEST_METHOD(EqualObjects5_Boolean) {
            ObjectValueType t1, t2, t3;
            bool checkValue1 = true;
            t1 = checkValue1;
            t2 = checkValue1;
            t3 = !checkValue1;

            Assert::IsTrue(t1 == t2);
            Assert::IsFalse(t1 != t2);

            Assert::IsFalse(t1 == t3);
            Assert::IsTrue(t1 != t3);
            Assert::IsFalse(t2 == t3);
            Assert::IsTrue(t2 != t3);
        }

    };

}

