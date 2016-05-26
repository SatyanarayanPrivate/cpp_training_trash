#include <iostream>
#include <cstdlib>
using namespace std;
#if 0
class CA {
    
    bool isonheap;
    void check() {
        char j;
        if ((char *)this < &j)
            isonheap = true;
        else
            isonheap = false;
    }
    
public:
    CA () {
        
    }
    void objectlocation () {
        check ();
        if (isonheap == true) {
            cout << "object on heap" << endl;
        }
        else
        {
            cout << "object not on heap" << endl;
        }
    }    
};
#endif

#if 0
class CA {
    
    bool isonheap;
    static bool global_heap;
public:
    CA () {
        isonheap = global_heap;
        global_heap = false;
        
    }
    static void * operator new (size_t size) {
        CA *temp = (CA *) malloc (size);
        global_heap = true;
        return temp;
    }
    void objectlocation () {
        if (isonheap == true) {
            cout << "object on heap" << endl;
        }
        else
        {
            cout << "object not on heap" << endl;
        }
    }    
};

bool CA:: global_heap=false;

int main (void) {

    CA obj1;
    CA *ptr1 = new CA();
    CA obj2;
    CA *ptr2 = new CA();
    
    cout << "---------- non heap --------------" << endl;
    obj1.objectlocation ();
    obj2.objectlocation ();
    
    cout << "\n---------- on heap --------------" << endl;
    ptr1-> objectlocation ();
    ptr2-> objectlocation ();
    
    cout << "\n---------- on heap --------------" << endl;
    CA *ptr3 = new CA [5];
    
    for (int i = 0x00; i < 5; i++)
    {
        (ptr3+i)->objectlocation ();
    }
    
    cout << endl << endl;
    return 0;
}
#endif 

class CA {
    
    bool isonheap;
    static bool global_heap;
    static int count;
public:
    CA () {
        isonheap = global_heap;
        if (-- count == 0x00)
            global_heap = false;
        
    }
    static void * operator new (size_t size) {
        
        CA *temp = (CA *) malloc (size);
        global_heap = true;
        count = 1;
        return temp;
    }
    static void * operator new[] (size_t size) {
        
        CA *temp = (CA *) malloc (size);
        count = size / sizeof (CA);
        global_heap = true;
        return temp;
    }
    void objectlocation () {
        if (isonheap == true) {
            cout << "object on heap" << endl;
        }
        else
        {
            cout << "object not on heap" << endl;
        }
    }    
};
int CA:: count = 0x00;
bool CA:: global_heap=false;

int main (void) {

    CA obj1;
    CA *ptr1 = new CA();
    CA obj2;
    CA *ptr2 = new CA();
    
    cout << "---------- non heap --------------" << endl;
    obj1.objectlocation ();
    obj2.objectlocation ();
    
    cout << "\n---------- on heap --------------" << endl;
    ptr1-> objectlocation ();
    ptr2-> objectlocation ();
    
    cout << "\n---------- on heap --------------" << endl;
    CA *ptr3 = new CA [5];
    
    for (int i = 0x00; i < 5; i++)
    {
        (ptr3+i)->objectlocation ();
    }
    cout << "\n---------- non heap --------------" << endl;
    CA obj3;
    obj3.objectlocation ();
    cout << endl << endl;
    return 0;
}
