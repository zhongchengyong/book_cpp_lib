#include "object.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using namespace think;

TEST(THINK_CPP, SYSTEM){
   system("ls"); 
}

TEST(THINK_CPP, DATA_TYPE){
    double d = 2e-1;
    cout << &d << endl;
    EXPECT_EQ(0.2, d);
}

TEST(THINK_CPPP, POINTER){
    int *pa, a=5;
    cout << "pa" << *pa << endl;
    cout << "a:" << a <<endl;
}

TEST(THINK_CPP, STRUCT_DEFAULT_VALUE){
    X x;
    PrintStruct(&x);
    cout << "--------sizeof---------" << endl;
    cout << sizeof(x) << endl;    
    if(1 == 1 and 2 == 2){
        cout << "and can be used" << endl;
    }
}
