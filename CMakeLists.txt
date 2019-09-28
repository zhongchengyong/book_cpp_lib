cmake_minimum_required(VERSION 3.10)
project(CppLib)


set(CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)


AUX_SOURCE_DIRECTORY(sword_offer SWORDOFFER)
AUX_SOURCE_DIRECTORY(standard_library STANDARD)
AUX_SOURCE_DIRECTORY(dsa DSA)
AUX_SOURCE_DIRECTORY(think_cpp THINK)

add_executable(runner main.cpp  ${SWORDOFFER} ${STANDARD} ${DSA} ${THINK})
target_link_libraries(runner GTest::GTest GTest::Main )

# To run google test by filter, use --gtest_fileter=xxx*