//
// Created by 钟乘永 on 2019-07-28.
//
#include "chapter2_base.h"
#include "chapter3_base.h"
#include <gtest/gtest.h>
#include <cassert>

using namespace sword;
using namespace std;
TEST(SWORDOFFER_CHAPTER2, SIZEOF){
    Empty empty;
    EXPECT_EQ(sizeof(empty), 1);
    EmptyWithVirtualMethod emptyWithVirtualMethod;
    EXPECT_EQ(8,sizeof(emptyWithVirtualMethod));

}

TEST(SWORDOFFER_CHAPTER2, ASSIGN){
    char* v = "abc";
    CMyString str;
    str.m_pData = v;
    CMyString str2;
    str2 = str;
    str2.m_pData = "def";
    cout << str2.m_pData << endl;
}


TEST(SWORDOFFER_CHAPTER3, DOUBLE_EQUAL){
    double a = 0.1 + 0.1;
    double b = 0.1;
    assert(a != b);
    float fa = 0.1 + 0.1;
    float fb = 0.2;
    assert(fa == fb);
}

TEST(SWORDOFFER_SORT, QUICK){
    int arr[] = {3, 1, 2, 4, 5, 7, 6};
    QuickSort(arr, 0, 6);
    int result[] = {1, 2, 3, 4, 5, 6, 7};
    for(size_t i = 0; i < 7; i++){
        cout << arr[i] << " ";
        EXPECT_EQ(arr[i], result[i]);
    }
    cout << endl;
}