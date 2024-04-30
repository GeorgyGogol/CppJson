#include <CppUnitTest.h>
#include "ObjectValueType.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "ValideMethods.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace json;

namespace TestObjectValueType {

    TEST_CLASS(ValuesWithJsonObject)
    {
    private:
        ValideMethods ValideMethodsCheck;

    public:
        TEST_METHOD(BaseCreatingWithJsonObject) {
            JsonObject o;
            o.add("Test");

            ObjectValueType ot(o);

            ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonObjectConditions());
        }

        TEST_METHOD(CreateAndDeleteWithJsonObject) {
            ObjectValueType ot;

            {
                JsonObject o;
                o.add("Test");

                ot = ObjectValueType(o);

            }

            ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonObjectConditions());

            JsonObject res = ot.getJsonObject();
            Assert::AreEqual(1, res.count());
        }

        TEST_METHOD(BaseCreatingWithJsonArray) {
            JsonArray o;
            o.add("Test");

            ObjectValueType ot(o);

            ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonArrayConditions());
        }

        TEST_METHOD(CreateAndDeleteWithJsonArray) {
            ObjectValueType ot;

            {
                JsonArray o;
                o.add("Test");

                ot = ObjectValueType(o);

            }

            ValideMethodsCheck.CheckConditionMethods(ot, ValideMethodsCheck.getJsonArrayConditions());

            JsonArray res = ot.getJsonArray();
            Assert::AreEqual(1, res.count());
        }

    };

}

