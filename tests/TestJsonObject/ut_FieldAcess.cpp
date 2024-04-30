#include <CppUnitTest.h>
#include "JsonObject.h"
#include "CppJson.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonObject {

    TEST_CLASS(FieldAcess) {
    public:
        FieldAcess()
        {
            o.add("String", "String");
            o.add("Int", 5);
            o.add("Dob", 1.15);
            o.add("Bool", false);
        }

    private:
        JsonObject o;

    public:

        TEST_METHOD(Check_String)
        {
            Assert::IsTrue(o.get("String") == "String", L"Value must be string, string equals");
        }

        TEST_METHOD(Check_Integer)
        {
            Assert::IsTrue(o.get("Int") == 5, L"Value must be Int, Int equals");
        }

        TEST_METHOD(Check_Boolean)
        {
            Assert::IsTrue(o.get("Bool") == false, L"Value must be Boolean, Boolean equals");
        }
    };

}

