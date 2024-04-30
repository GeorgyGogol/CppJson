#include <CppUnitTest.h>
#include "JsonObject.h"
#include "JsonFuncs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonObject {

    TEST_CLASS(SimpleCreateJson)
    {
    private:
        const int nProps = 4;
        std::string props[4]{ "One", "Two", "Tree", "Four" };
        std::string vals[4]{ "10", "SomeString", "45.550000", "null" };
        std::string correctJsonStr = "{\"Four\":\"null\",\"One\":\"10\",\"Tree\":\"45.550000\",\"Two\":\"SomeString\"}";
        std::string result;

    public:
        TEST_METHOD(Create)
        {
            JsonObject o;

            for (int i = 0; i < nProps; ++i) {
                o.add(props[i], vals[i]);
            }
            Assert::AreEqual(nProps, o.count(), L"Some property was lost, count not equal total input properties");
            
            result = o.toString();
            Assert::AreEqual(correctJsonStr, result, L"The generated string does not match the expected value");
        }
    };

}

