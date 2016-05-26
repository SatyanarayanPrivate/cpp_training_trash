// limit object creation on heanp
// #include <iostream>
// using namespace std;
// 
// class CA {
// public: 
//     CA () {
//         cout << "CA Ctor\n";
//     }
//     ~CA () {
//         cout << "CA Dtor\n";
//     }   
// private:
//     void* operator new(size_t);          // standard new
//     void* operator new(size_t, void*);   // placement new
//     void* operator new[](size_t);        // array new
//     void* operator new[](size_t, void*); // placement array new
// };
// 
// CA obj1;
// 
// int main (void) {
//     CA obj2;
//     CA *obj3 = new CA();
//     CA *obj4 = new CA[3];
//     
//     delete obj3;
//     cout << endl << endl;
//     return 0;
// }


// object creation only on heap

#include <iostream>
using namespace std;
 
// A class whose object can only be dynamically created
class Test
{
private:
    ~Test() { cout << "Destroying Object\n"; }
public:
     Test() { cout << "Object Created\n"; }
friend void destructTest(Test* );
};
 
// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
    cout << "Object Destroyed\n";
}

/* Uncommenting following following line would cause compiler error */
//     Test obj;
 
int main()
{
    /* Uncommenting following following line would cause compiler error */
//     Test t1;
 
    // create an object
    Test *ptr = new Test;
 
    // destruct the object to avoid memory leak
    destructTest(ptr);
 
    return 0;
}