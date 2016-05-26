#include <iostream>
using namespace std;

class CA {
    CA () {
        cout << "CA Ctor\n";
    }
    ~CA () {
        cout << "CA Dtor\n";
    }   
    static CA* CreateCA () {
        return new CA();
    }
    static void ReleaseCA (CA *ptr) {
        delete ptr;
    }
public:
    void fun() {
        cout << "CA_fun\n";
    }
    
    friend class wrapper;
};

class wrapper { 
    void* operator new(size_t);          // standard new
    void* operator new(size_t, void*);   // placement new
    void* operator new[](size_t);        // array new
    void* operator new[](size_t, void*); // placement array new
    CA *ca_ptr;
public:
    wrapper ():ca_ptr(CA:: CreateCA()) {
    }
    
    ~wrapper () {
        CA:: ReleaseCA (ca_ptr);
    }
    
    CA *operator-> () {
        return ca_ptr;
    }
    
};

int main (void) {
    
    wrapper obj;
    
    obj->fun();
    
    cout << endl << endl;
    return 0;
}
