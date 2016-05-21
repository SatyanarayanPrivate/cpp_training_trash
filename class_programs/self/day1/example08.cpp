
// operator overloading

// casting operator


#include <iostream>
using namespace std;

class CComplex
{

    double real;
    double imag;    
public:
        CComplex(): real(0.0),imag(0.0)
        {
            
        }
        CComplex(double real, double imag): real (real), imag (imag)
        {
            
        }
        
        void Display ()
        {
            cout << real << (real>=0.0 ?"+":"")     <<imag<< "i"<<endl;
        }
//         friend void DisplayComplex(ostream &os, CComplex & par);
    friend ostream & operator<<(ostream &os, CComplex & par);
        
};

void DisplayComplex(ostream &os, CComplex & par)
{
    os << par.real << (par.real>=0.0 ?"+":"") << par.imag<< "i"<<endl;
}

ostream & operator<<(ostream &os, CComplex & par)
{
    os << par.real << (par.real>=0.0 ?"+":"") << par.imag<< "i"<<endl;
}


int main (void)
{
    CComplex c1(2.3, 4.5);
    
    CComplex c2(11.2, 34.7);
//     DisplayComplex(cout, c1);
    operator<<(cout, c2);
    
    cout << endl;
    return 0;
}