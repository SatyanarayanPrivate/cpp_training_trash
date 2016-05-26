#include <iostream>
using namespace std;

class CA {

    CA () {
        cout << "CA Ctor" << endl;
    }

    ~CA () {
        cout << "CA Dtor" << endl;
    }
    static CA *CreateCA ()
    {
        if (head == NULL)
            head  = new CA();
        return head;        
    } 
    static void ReleaseCA () {
        delete head;
        head = NULL;        
    }

    static CA *head;
public:
    void fun () {
        cout << "CA fun" << endl;
    }
    friend class smart;
};
CA *CA:: head = NULL;

class smart {
    CA *ptr;
    static int count;
public:
    smart () : ptr (CA:: CreateCA() ) {
        count ++;
    }
    CA *operator-> () {
        return ptr;
    }
    ~smart () {
        if (-- count == 0x00)
            CA::ReleaseCA();
    }
};

int smart::count = 0x00;

void fun () {
    smart s2;
    smart s4;
}

int main (void) {
    
//     fun ();
    smart s1;
    smart s2;
    
    
    cout << endl << endl;
    return 0;
}