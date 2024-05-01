#include "gtest/gtest.h"
#include "JsonObject.h"
#include "JsonFuncs.h"

using namespace json;

TEST(TestJsonObject_CreateJsonWithSubs, Case01)
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
    ASSERT_EQ(nProps, sub.count()) << "Some property was lost, count not equal total input properties";

    for (int i = 0; i < nProps - 1; ++i) {
        base.add(props[i], vals[i]);
    }
    base.add(props[nProps - 1], sub);

    std::string result = base.toString();
    ASSERT_EQ(correctJsonStr, result) << "The generated string does not match the expected value";
}

