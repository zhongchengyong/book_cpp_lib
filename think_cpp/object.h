#ifndef CPPLIB_OBJECT_H
#define CPPLIB_OBJECT_H

#include <cstdlib>

namespace think{
    struct X{
        int a[1000];
    };
    void PrintStruct(X* x);
}


#endif // CPPLIB_OBJECT_H