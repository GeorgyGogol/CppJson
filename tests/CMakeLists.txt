#
# Unit test sub project
#
message (STATUS "Unit Test project build enabled, configuring test project")
add_subdirectory("modules/googletest")

#
# Adding unit tests
#
file(GLOB
    UNIT_TESTS_SOURCES
    Test*/ut_*.cpp
)
list(REMOVE_ITEM UNIT_TESTS_SOURCES TestJsonObject/ut_AdditionalAddGetProperties.cpp)

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
# Creating ut project
#
enable_testing()
add_executable(CppJsonTests main.cpp)
target_include_directories(CppJsonTests PRIVATE ${INCLUDE_PATH})
target_sources(CppJsonTests PRIVATE ${UNIT_TESTS_SOURCES} ${SRC_FILES})

target_link_libraries(CppJsonTests PRIVATE gtest_main)
target_link_libraries(CppJsonTests PRIVATE modules::CppJson)

