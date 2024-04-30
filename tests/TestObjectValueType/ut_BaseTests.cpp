#include <CppUnitTest.h>
#include "ObjectValueType.h"
#include "ValideMethods.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestObjectValueType {

    TEST_CLASS(BaseTests)
    {
    private:
        ValideMethods ValideMethodsCheck;

    public:

        TEST_METHOD(DefaultCretateDelete)
        {
            ObjectValueType t;
            ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNotValideConditions());
        }

        TEST_METHOD(IntInitMethod)
        {
            int someValue = 5;
            ObjectValueType t = someValue;
            ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNumberConditions());
            Assert::AreEqual(t.getInt(), someValue);
        }

        TEST_METHOD(DoubleInitMethod) {
            double someValue = 13.52;
            ObjectValueType t = someValue;
            ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNumberConditions());
            Assert::AreEqual(t.getDouble(), someValue);
        }

        TEST_METHOD(StrInitMethod) {
            std::string someString = "SomeString";
            ObjectValueType stringObject = someString;
            ValideMethodsCheck.CheckConditionMethods(stringObject, ValideMethodsCheck.getStringConditions());
            Assert::AreEqual(stringObject.getStr(), someString);
        }

        TEST_METHOD(CharInitMethod) {
            ObjectValueType charObject = "char";
            ValideMethodsCheck.CheckConditionMethods(charObject, ValideMethodsCheck.getStringConditions());
            Assert::AreEqual(charObject.getStr(), std::string("char"));
            Assert::AreEqual(charObject.getStr().c_str(), "char");
        }

        TEST_METHOD(AssignObject) {
            int checkValue = 5;
            std::string checkString = "SomeString";

            ObjectValueType t1, t2;

            t1 = checkValue;
            t2 = t1;
            Assert::AreEqual(t2.getInt(), checkValue);

            t2 = checkString;
            t1 = t2;
            Assert::AreEqual(t1.getStr(), checkString);
        }

        TEST_METHOD(NullObject) {
            ObjectValueType t;
            t.setNull();
            ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getNullConditions());
        }

        TEST_METHOD(BooleanInit) {
            ObjectValueType t(true);
            ValideMethodsCheck.CheckConditionMethods(t, ValideMethodsCheck.getBoolArrayConditions());
            Assert::IsTrue(t.getBool());
        }

    };

}

