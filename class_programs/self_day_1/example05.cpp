// test pointers
#include <iostream>

using namespace std;

int main5_1 (void)
{
    int x = 10;
    int y = 20;
        
    int *px = &x;
    //const int *px = &x;   // pointer to a constant
    //int const *px = &x;   // pointer to a constant
//     int * const px = &x;    // constant pointer
//     int const * const px = &x; // consant pointer to a constant
    
    px = &y;    // gives error on int *const px = &x;
    *px = 999;  // gives error on const int *px = &x;
    
    cout << "px= "<< px << endl;
    cout << "&x= "<< &x << endl;
    cout << "&y= "<< &y << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<< endl;
    cout << "*px= "<< *px << endl;
    cout << "x= "<< x << endl;
    cout << "y= "<< y << endl;
    
    return 0;
}


int main5_2 (void)
{
    int x = 10;
    int & y = x;

    cout << "&x= "<< &x << endl;
    cout << "&y= "<< &y << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<< endl;
    cout << "x= "<< x << endl;
    cout << "y= "<< y << endl;
    
    return 0;
}


int i = 10;

int fun1 () {
    
    return i;
}

int * fun2 ()
{
    return &i;
}

int & fun3()
{
    return i;
}

// int && fun4()
// {
//     return std::move(i);
// }


int main5_3 (void) {
    
    fun3() = 1000;
    
    cout << "i = "<< i<< endl;
    return 0;
}



// default args
/* previously
void fx (int , int , int=120);
void fx (int , int=33 , int);
void fx (int=12 , int , int);
*/
// OR
// void fx (int=12 , int=33 , int=120);
// OR
//void fx (int x, int y, int z)
void fx (int x=12 , int y=33 , int z=120)
{
    cout << "x = "<< x << endl;
    cout << "y = "<< y << endl;
    cout << "z = "<< z << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main5_4()
{
    fx (1, 2, 3);
    fx (1, 2);
    fx (1);
    fx ();
    return 0;
}




