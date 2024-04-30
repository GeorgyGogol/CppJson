#include <CppUnitTest.h>
#include "JsonArray.h"
#include "JsonFuncs.h"
//#include "ValideMethods.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestJsonArray {

    TEST_CLASS(SimpleCreateJsonArray)
    {
    private:
        const int nProps = 4;
        int iVal = 10;
        std::string sVal = "Somestring";
        double dVal = 45.55;

        std::string correctJsonStr = "[10,\"Somestring\",45.550000,null]";
        std::string result;
        
        //TestObjectValueType::ValideMethods Validator;

    public:
        TEST_METHOD(Create)
        {
            JsonArray a;

            a.add(iVal);
            a.add(sVal);
            a.add(dVal);

            {
                ObjectValueType ot;
                ot.setNull();
                a.add(ot);
            }

            Assert::AreEqual(nProps, a.count(), L"Some property was lost, count not equal total input properties");
            
            result = a.toString();
            Assert::AreEqual(correctJsonStr, result, L"The generated string does not match the expected value");
        }
    };

}

