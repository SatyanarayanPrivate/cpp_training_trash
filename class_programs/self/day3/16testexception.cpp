#include <iostream>
#include <cstdlib>
using namespace std;

void VendorApi (int para) {
    cout << "Apple" << endl;
    if (20 == para)
        throw 404;
    cout << "orange\n"; 
}


void Myterminate () {
    cout << "my terminate" << endl;
    exit (0);
}

int main11 (void) {
    set_terminate (Myterminate);
    cout << "before call \n";
    VendorApi(20);
    cout << "after call\n";
    cout << endl << endl;
    return 0;
}

class CA {
public: 
    CA () {
        cout << "CA default Ctor\n";
    }

    CA (CA &obj) {
        cout << "CA default CCtor\n";
    }
    
    ~CA () {
        cout << "CA default Dtor\n";
    }
};

int main (void) {
    cout << "before call \n";
    try {
        cout << "apple\n";
        throw 403;
        cout << "apple_1\n";
    }catch (int exp) {
        cout << "EXp int:: " << exp;
    }
    
    VendorApi(20);
    cout << "after call\n";
    cout << endl << endl;
    return 0;    
}
