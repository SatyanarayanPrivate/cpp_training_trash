#include <iostream>
#include <map>
using namespace std;

class IFile {
public:
    virtual void DoProcess() = 0;
};

class BMP: public IFile {
public:
    BMP() {
        cout << "BMP Ctor"<< endl;
    }
    void DoProcess () {
        cout << "BMP Processed"<< endl;
    }
};

IFile * CreateBMP() {
    return new BMP();
}

class JPG: public IFile {
public:
    JPG() {
        cout << "JPG Ctor"<< endl;
    }
    void DoProcess () {
        cout << "JPG Processed"<< endl;
    }
};

IFile * CreateJPG() {
    return new JPG();
}

class IRegister {
public:
    static map <int, IFile *(*)()> myMap;
    IRegister () {
        
        myMap[10] = [](){return (IFile *) new BMP();};
        myMap[20] = [](){return (IFile *) new JPG();};
        
//         myMap[10] = &CreateBMP;
//         myMap[20] = &CreateJPG;
    }
    void DoRegister(int choice, IFile *(*fp)()) {
        myMap[choice] = fp;
    }
    static IFile *BuildFileObject (int choice) {
        return IRegister:: myMap[choice]();
    }
};
// for initializing static variable
map <int, IFile *(*)()> IRegister:: myMap;
IRegister reg;

int main (void) {
    
    cout << "Enter a choice " << endl;
    int choice;
    cin >> choice;
    
    IFile *file = IRegister:: BuildFileObject (choice);
    file->DoProcess();
    
    cout << endl << endl;
    return 0;
}