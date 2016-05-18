#include <iostream>
using namespace std;

class CA
{
public: 
    CA()
    {
        cout << "CA default\n";        
    }
    
    CA(int x)
    {
        cout << "one param \n";
    }
//     
    CA(CA &cpy)
    {
        cout << "CA copy \n";
    }
};
    

int main (void)
{
    CA obj; // default
    CA obj1(10); // one param
    CA obj2 = 20;// one param
//     
    obj = 45; // one param
//     
    return 0;
}