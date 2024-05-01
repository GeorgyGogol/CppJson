#include "gtest/gtest.h"
#include "JsonObject.h"
#include "JsonFuncs.h"

#include <string>

using namespace json;

namespace TestJsonObject {

    /*
    class ExampleKeeper
    {
    public:
        ExampleKeeper(const std::string& dataFileName);

    private:
        int nElements;
        std::string* PropNames;
        std::string* PropValues;
        std::string CorrectJsonString;

    public:
        int getCount() const;
        std::string getPropName(int n) const;
        std::string getPropVal(int n) const;
        const std::string& getCorrectJsonString() const;

    };
    */

    TEST_CLASS(AdditionalAddGetProperties)
    {
    public:
        /*
        TEST_METHOD(SimpleCreateObjectInObject)
        {
            ExampleKeeper examples("AdditionalJson_1");
            JsonObject test;
            test.add("Name", "Test1");

            JsonObject subJson;
            for (int i = 0; i < examples.getCount(); ++i) {
                subJson.add(examples.getPropName(i), examples.getPropVal(i));
            }

            test.add("Props", subJson);
            ASSERT_EQ(2, test.count(), L"Some property was lost, count not equal total input properties");

            std::string result = test.toString();
            ASSERT_EQ(examples.getCorrectJsonString(), result, L"The generated string does not match the expected value");
        }
        */

        /*
        TEST_METHOD(SimpleParseObjectInObject)
        {
            ExampleKeeper examples("AdditionalJson_1");

            JsonObject test = json::parseString(examples.getCorrectJsonString());
            ASSERT_EQ(2, test.count(), L"Some property was lost, count parsed properties not equal total input properties");

            ASSERT_EQ("Test1", test.get("Name"));

            JsonObject subJson = test.get("Props");
            ASSERT_EQ(examples.getCount(), subJson.count());
            for (int i = 0; i < subJson.count(); ++i) {
                ASSERT_TRUE(subJson.isExists(examples.getPropName(i)));
                ASSERT_EQ(examples.getPropVal(i), subJson.get(examples.getPropName(i)));
            }
        }
        */

        BEGIN_TEST_METHOD_ATTRIBUTE(CreateMultiObject)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(CreateMultiObject)
        {
            //ExampleKeeper examples("AdditionalJson_2");
        }
    };

}

