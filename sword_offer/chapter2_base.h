//
// Created by 钟乘永 on 2019-07-28.
//

#ifndef CPPLIB_CHAPTER2_BASE_H
#define CPPLIB_CHAPTER2_BASE_H

#include <iostream>
#include <string>

namespace sword {
    // 一个空的对象，不包含任何成员和函数，求sizeof
    class Empty {
    };

    //如果包含析构函数，则实例的sizeof结果为8，因为有一个指向虚函数表的指针，64位机器上是8字节
    class EmptyWithVirtualMethod {
    public:
        virtual ~EmptyWithVirtualMethod() = default;
    };

    // 赋值构造函数必须是深拷贝
    class CMyString {
    public:
        explicit CMyString(char *str = nullptr) : m_pData(str) {}

        /**
         * Not safe.
         * @param str
         * @return
         */
//        CMyString &operator=(const CMyString &str) {
//            if(this == &str){
//                return *this;
//            }
//            delete[]m_pData;
//            m_pData = nullptr;
//            m_pData = new char[strlen(str.m_pData) + 1];
//            strcpy(m_pData, str.m_pData);
//            return *this;
//        }
        CMyString&operator=(const CMyString &str){

        }
        ~CMyString(){
            std::cout << "DST invoked" << std::endl;
            delete []m_pData;
        }

        char *m_pData;
    };

}


#endif //CPPLIB_CHAPTER2_BASE_H
