// constructor
#include <iostream>

using namespace std;

class CA
{
public:
    // constructor name not standard depnds upon compiler
    CA ()
    {
        cout << "CA Ctor" << endl; 
    }
    
    void fun()
    {
        
    }
};

class CB:public CA
{
public:
    // constructor name not standard depnds upon compiler
    CB ()
    { // call to base class constructor
        cout << "CB Ctor" << endl; 
    }
};

class CC:public CB
{
public:
    // if base class has constructor and derirved class dont have then compiler has to be synthsize constructor to call base class constructor.
    /*
    CC ()
    {
        cout << "CC Ctor" << endl; 
    }*/
};

int main (void) {
    CB obj;
    // called derirved constructor called 1st
    obj.fun();    
    
    CC obj1;
    
    obj1.fun();    
}



class CA
{
public:
    // constructor name not standard depnds upon compiler
    CA ()
    {
        cout << "CA Ctor" << endl; 
    }
    
    void fun()
    {
        
    }
};

class CC
{
public: 
    CC ()
    {
        cout << "CC Ctor" << endl; 
    }
};

class CB:public CC
{
    // if container has constructor then compiler will synthsize constructor to call obj's constructor
    CA obj;
public:
    // constructor name not standard depnds upon compiler
    CB ()
    { // call to constructor of CA
        cout << "CB Ctor" << endl; 
    }
    
};

class CB:public CC
{
    // if container has constructor then compiler will synthsize constructor to call obj's constructor
    CA obj;
public:
    // constructor name not standard depnds upon compiler
    CB ()
    { // call to constructor of CA
        cout << "CB Ctor" << endl; 
    }
    
};

int main ()
{
    CB obj;
}



using namespace std;

class animal
{
public:
    animal ()
    {// if class has virtual fun and class have constructor then here set vtable entry in vptr.
        
        
    }
    // if class has virtual fun and class dont have constructor then compiler will synthesize constructor to set vtable entry in vptr
    virtual void fun () {
    }
};

int main (void)
{
    animal obj;
}
