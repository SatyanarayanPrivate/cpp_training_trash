#include <iostream>
using namespace std;


class CA 
{
public:
    int x;
    mutable int y;
    static int s;
    static const int sc;
    
    CA() :x(10),y(30)
    {
        
    }
    
    // Inspector 
    // method will never change state 
    void DisplayValue() const
    {
        y ++;
        cout << "x:: " << x << endl;
        cout << "y:: " << y << endl;
    }
    // Mutator
    // method will change state 
    void ChangeValue()
    {
        x += 20;
        y += 50;
    }
    
    static void statfun()
    {
        cout << "s:: " << s << endl;
        cout << "sc:: " << sc << endl;
    }
};  

int CA::s = 20;
const int CA::sc = 99;

int main (void)
{
    const CA obj;
    obj.y = 1123;
//     obj.ChangeValue();
    obj.DisplayValue();
    CA::statfun();
    cout << "sc:: "<< CA::sc << endl;
    return 0;
}

