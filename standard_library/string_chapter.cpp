//
// Created by 钟乘永 on 2019-09-08.
//

#include "string_chapter.h"
#include <string>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(STANDARD, STRING) {
    string s;
    cout << s.max_size() << endl;
    cout << s.capacity() << endl;
    cout << s.size() << endl;
    s.reserve(80);
    cout << s.capacity() << endl;
}