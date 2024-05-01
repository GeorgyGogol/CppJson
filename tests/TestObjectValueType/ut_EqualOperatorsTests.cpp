#include "gtest/gtest.h"
#include "ObjectValueType.h"
#include <string>

using namespace json;

TEST(TestObjectValueType_EqualOperatorsTests, OnlyIntCheck) 
{
    ObjectValueType t1;
    int checkValue = 5;
    t1 = checkValue;
    ASSERT_TRUE(t1 == checkValue);
    ASSERT_FALSE(t1 != checkValue);
}

TEST(TestObjectValueType_EqualOperatorsTests, OnlyDoubleCheck) 
{
    ObjectValueType t1;
    double checkValue = 15.149456;
    t1 = checkValue;
    ASSERT_TRUE(t1 == checkValue);
    ASSERT_FALSE(t1 != checkValue);
}

TEST(TestObjectValueType_EqualOperatorsTests, OnlyStrCheck) 
{
    ObjectValueType t1;
    std::string checkValue = "SomeString";
    t1 = checkValue;
    ASSERT_TRUE(t1 == checkValue);
    ASSERT_FALSE(t1 != checkValue);
}

TEST(TestObjectValueType_EqualOperatorsTests, ObjectsCase01) 
{
    ObjectValueType t1, t2, t3;
    int checkValue1 = 5;
    t1 = checkValue1;
    t2 = checkValue1;

    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 != t2);

    ASSERT_FALSE(t1 == t3);
    ASSERT_TRUE(t1 != t3);
    ASSERT_FALSE(t2 == t3);
    ASSERT_TRUE(t2 != t3);
}

TEST(TestObjectValueType_EqualOperatorsTests, ObjectsCase02) 
{
    ObjectValueType t1, t2, t3;
    int checkValue1 = 5;
    t1 = checkValue1;
    t2 = checkValue1;
    t3 = "SomeString";

    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 != t2);

    ASSERT_FALSE(t1 == t3);
    ASSERT_TRUE(t1 != t3);
    ASSERT_FALSE(t2 == t3);
    ASSERT_TRUE(t2 != t3);
}

TEST(TestObjectValueType_EqualOperatorsTests, ObjectsCase03) 
{
    ObjectValueType t1, t2, t3;
    int checkValue1 = 5;
    t1 = checkValue1;
    t2 = checkValue1;
    t3 = 12.5;

    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 != t2);

    ASSERT_FALSE(t1 == t3);
    ASSERT_TRUE(t1 != t3);
    ASSERT_FALSE(t2 == t3);
    ASSERT_TRUE(t2 != t3);
}

TEST(TestObjectValueType_EqualOperatorsTests, ObjectsCase04) 
{
    ObjectValueType t1, t2, t3;
    int checkValue1 = 5;
    t1 = checkValue1;
    t2 = checkValue1;
    t3 = 5.0;

    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 != t2);

    ASSERT_FALSE(t1 == t3);
    ASSERT_TRUE(t1 != t3);
    ASSERT_FALSE(t2 == t3);
    ASSERT_TRUE(t2 != t3);
}

TEST(TestObjectValueType_EqualOperatorsTests, NotEqualObjects)
{
    ObjectValueType t1, t2;
    t1 = 4;
    t2 = "someString";

    ASSERT_FALSE(t1 == t2);
    ASSERT_TRUE(t1 != t2);
}

TEST(TestObjectValueType_EqualOperatorsTests, OnlyBool) 
{
    ObjectValueType t;
    t = false;

    ASSERT_FALSE(t == true);
    ASSERT_TRUE(t == false);

    ASSERT_TRUE(t != true);
    ASSERT_FALSE(t != false);
}

TEST(TestObjectValueType_EqualOperatorsTests, ObjectsCase05_Boolean) 
{
    ObjectValueType t1, t2, t3;
    bool checkValue1 = true;
    t1 = checkValue1;
    t2 = checkValue1;
    t3 = !checkValue1;

    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 != t2);

    ASSERT_FALSE(t1 == t3);
    ASSERT_TRUE(t1 != t3);
    ASSERT_FALSE(t2 == t3);
    ASSERT_TRUE(t2 != t3);
}

