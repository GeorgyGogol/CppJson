#
# Unit test
#
message (STATUS "Unit Test project build enabled, configuring test project")

project(CppJsonTests)

#
# Adding unit tests
#
file(GLOB
    UNIT_TESTS_SOURCES
#    Test*/ut_*.cpp
    TestObjectValueType/ut_BaseTests.cpp
)

#
# Set additional sources
#
set(
    INCLUDE_PATH
    Utils
)

file(GLOB
    SRC_FILES
    Utils/*.h
    Utils/*.cpp
)

# 
enable_testing()

#find_package(MSUnitTestFramework REQUIRED)

add_library(CppJsonTests SHARED)
target_include_directories(CppJsonTests PRIVATE ${INCLUDE_PATH})
target_sources(CppJsonTests PRIVATE ${UNIT_TESTS_SOURCES} ${SRC_FILES})

target_link_libraries(CppJsonTests PRIVATE modules::CppJson)

