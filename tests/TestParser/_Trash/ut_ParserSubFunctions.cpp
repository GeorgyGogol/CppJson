#include <CppUnitTest.h>
//#include "SupFunctions.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace sup::pars;
//using namespace json;

namespace TestParser
{
    
    TEST_CLASS(ParserSubFunctions)
    {
    public:

        BEGIN_TEST_METHOD_ATTRIBUTE(seekEndOfSub_Test)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(seekEndOfSub_Test)
        {
            std::string test = "{\"Name\":\"PersonsName\",\"Count\":2,\"Vals\":{\"Jhon\":\"male\",\"Eva\":\"woman\"}}";
            int correct = test.size();

            //Assert::AreEqual(correct, sup::pars::seekEndOfSub(test.c_str(), test.size(), '{', '}'));

        }

    };

}

