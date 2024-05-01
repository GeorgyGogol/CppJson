#include "gtest/gtest.h"
//#include <cstdlib>

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    int result = RUN_ALL_TESTS();

    //std::printf("Press Enter to close test console");
    //std::getchar();
    return result;
}
