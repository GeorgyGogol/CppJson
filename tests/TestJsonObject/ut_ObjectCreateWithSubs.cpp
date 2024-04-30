#include <CppUnitTest.h>
#include "JsonObject.h"
#include "JsonFuncs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonObject {

    TEST_CLASS(CreateJsonWithSubs)
    {
    private:
        std::string result;

    public:
        TEST_METHOD(CreateWithSubJson)
        {
            std::string correctJsonStr = "{\"1\":\"200\",\"2\":{\"1\":\"200\",\"2\":\"200\",\"3\":\"Total\"},\"3\":\"Total\"}";

            JsonObject base;
            JsonObject sub;

            const int nProps = 3;
            std::string props[3]{ "1", "3", "2" };
            std::string vals[3]{ "200", "Total", "200" };
            

            for (int i = 0; i < nProps; ++i) {
                sub.add(props[i], vals[i]);
            }
            Assert::AreEqual(nProps, sub.count(), L"Some property was lost, count not equal total input properties");

            for (int i = 0; i < nProps - 1; ++i) {
                base.add(props[i], vals[i]);
            }
            base.add(props[nProps - 1], sub);
            
            result = base.toString();
            Assert::AreEqual(correctJsonStr, result, L"The generated string does not match the expected value");
        }
    };

}

