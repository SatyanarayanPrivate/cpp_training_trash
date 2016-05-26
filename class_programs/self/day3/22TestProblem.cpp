#include <iostream>
using namespace std;
#if 0

// without deep copy
class CA {
    int *i;
public:
    CA ():i(new int(10)) {
        cout << "Ctor called ..."<< endl; 
    }
    
    CA (const CA & para ): i (para.i) {
        cout << "CCtor called ..."<< endl; 
    }
    void fun () {
        cout << "func called ..."<< endl; 
    }
    ~CA () {
        cout << "Dtor called ..."<< endl; 
        delete i;
    }
};

class smart {
    CA *ptr;
public:
    smart () : ptr(new CA()) {
    }
    smart (const smart & sm) : ptr(sm.ptr) {
    }
    
    CA *operator-> () {
        return ptr;
    }
    ~smart () {
        delete ptr;
    }    
};
#endif

class CA {
    int *i;
public:
    CA ():i(new int(10)) {
        cout << "Ctor called ..."<< endl; 
    }
    
    CA (const CA & para ): i (new int(*para.i)) {
        cout << "CCtor called ..."<< endl; 
    }
    void fun () {
        cout << "func called ..."<< endl; 
    }
    ~CA () {
        cout << "Dtor called ..."<< endl; 
        delete i;
    }
    CA & operator= (const CA &para) {
        this->i = para->i;
    }
};

class smart {
    CA *ptr;
public:
    smart () : ptr(new CA()) {
    }
    smart (const smart & sm) : ptr(new CA(*sm.ptr)) {
    }
    
    CA *operator-> () {
        return ptr;
    }
    ~smart () {
        delete ptr;
    }    
};

int main (void) {

    smart sm1;
    smart sm2;
    smart sm3(sm1);
//     sm2 = sm3;
    
    cout << endl << endl;
    return 0;
}