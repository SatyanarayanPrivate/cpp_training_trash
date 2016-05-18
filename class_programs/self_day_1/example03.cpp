#include <iostream>

using namespace std;


// according to ARM organization size of empty class is always 1 byte
class CA
{
};

// padin concept
// padding is for offset calculation
class CA1
{
    char c;
    double h;
    char b;
};

class CA2
{
public:
    virtual void fun1 (void)
    {
        cout << "fun1 called" << endl; 
    }
    virtual void fun2 (void)
    {
        cout << "fun2 called" << endl;
    }
    void fun3 (void)
    {
        cout << "fun3 called" << endl;
    }
};


int main3_1 (void)
{
    cout << sizeof (CA2)<< endl;
    
    CA2 obj;
    //((void (*)())*(long *)*(long *)&obj;
    //1 reach vptr
    long *vp = (long *) &obj;
    //2 reach vtable 
    long *vt = (long *) *vp;
    //3 reach function
    typedef void (*FPTR) ();
    
    FPTR fp = (FPTR)vt[0];
    //4 call back
    fp();
    
    return 0;
}


int main3_2 ()
{
    CA2 obj;
    // non virtual funs 
    obj.fun1(); // resolved from code segment
    obj.fun3(); // resolved from code segment

    CA2 &objref = obj;
    objref.fun1();// resolved from vtable //objref.vptr->vtable[0]()
    objref.fun3();// resolved from code segment

    CA2 *ptr = &obj;
    ptr->fun1();//ptr->vptr->vtable[0]()
    ptr->fun3();
    
    return 0;
}
    
