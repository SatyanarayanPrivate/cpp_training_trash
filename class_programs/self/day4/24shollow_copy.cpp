#include <iostream>
#include <map>
using namespace std;

#if 0
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
        i = para.i;
        return *this;
    }
};

class smart {
    CA *ptr;
    int *ref_count;
public:
    smart () : ptr(new CA()), ref_count(new int(1)) {
    }
    smart (const smart & sm) : ptr(new CA(*sm.ptr)), ref_count(sm.ref_count) {
        (*ref_count)++;
    }
    
    CA *operator-> () {
        return ptr;
    }
    ~smart () {
        if (--(*ref_count) == 0x00) {
            delete ptr;
            delete ref_count;
        }
    }    
    smart & operator= (const smart &para) {
        this->smart::~smart();
        this->smart::smart(para);
        return *this;
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
        i = para.i;
        return *this;
    }
};

class smart {
    CA *ptr;
    int *ref_count;
public:
    smart () : ptr(new CA()), ref_count(new int(1)) {
    }
    smart (const smart & sm) : ptr(new CA(*sm.ptr)), ref_count(sm.ref_count) {
        (*ref_count)++;
    }
    
    CA *operator-> () {
        return ptr;
    }
    ~smart () {
        if (--(*ref_count) == 0x00) {
            delete ptr;
            delete ref_count;
        }
    }    
    smart & operator= (const smart &para) {
        this->smart::~smart();
        this->smart::smart(para);
        return *this;
    }
};
int main (void) {

    smart s1;
    smart s2(s1);
    smart s3(s2);
    smart s4;
    smart s5;
    smart s6(s5);
    
    s3 = s4;
    s2 = s6;
    
    cout << endl << endl;
    return 0;
}