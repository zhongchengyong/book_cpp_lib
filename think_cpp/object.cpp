#include "object.h"
#include <iostream>

using namespace std;

namespace think{
    void PrintStruct(X* x){
        for(int i = 0; i < 100; i++){
            cout << x->a[i] << ' ';
        }
        cout << endl << "-----------------" << endl;
    }
}
