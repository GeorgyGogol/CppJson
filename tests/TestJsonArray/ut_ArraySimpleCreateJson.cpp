#include "gtest/gtest.h"
#include "JsonArray.h"
#include "JsonFuncs.h"
//#include "ValideMethods.h"

using namespace json;

class TestJsonArray_SimpleCreateJsonArray : public testing::Test
{
protected:
    const int nProps = 4;
    int iVal = 10;
    std::string sVal = "Somestring";
    double dVal = 45.55;

    std::string correctJsonStr = "[10,\"Somestring\",45.550000,null]";
    std::string result;

};

TEST_F(TestJsonArray_SimpleCreateJsonArray, Create)
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

    ASSERT_EQ(nProps, a.count()) << "Some property was lost, count not equal total input properties";

    result = a.toString();
    ASSERT_EQ(correctJsonStr, result) << "The generated string does not match the expected value";
}

