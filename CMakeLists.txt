cmake_minimum_required(VERSION 3.12)
project(CppLib)


set(CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)


AUX_SOURCE_DIRECTORY(sword_offer SWORDOFFER)

add_executable(runner main.cpp  ${SWORDOFFER})
target_link_libraries(runner GTest::GTest GTest::Main )

# To run google test by filter, use --gtest_fileter=xxx*