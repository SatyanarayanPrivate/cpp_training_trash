#include <iostream>
using namespace std;
#if 0
class RecCoord {
    double xCord;
    double yCord;
public:
    RecCoord (): xCord (0.00), yCord (0.00) {
        
    }
    friend ostream & operator << (ostream & os, RecCoord rec) {
        os << "xCord:: " << rec.xCord << " yCord:: " << rec.yCord << endl;
    }
};

class Polar {
    double distance;
    double angle;
public:
    Polar (): distance (0.00), angle (0.00) {
        
    }
    Polar (double distance, double angle): distance (distance), angle (angle) {
        
    }
    friend ostream & operator << (ostream & os, Polar pol) {
        os << "distance:: " << pol.distance << " yCord:: " << pol.angle << endl;
    }
};

int main (void) {

    Polar p (5.00, 60);
    RecCoord r;
    
    cout << p << endl;
    cout << r << endl;
    
    cout << endl << endl;
    return 0;
}
#endif

class RecCoord;

class Polar {
    double distance;
    double angle;
public:
    Polar (): distance (0.00), angle (0.00) {
        
    }
    Polar (double distance, double angle): distance (distance), angle (angle) {
        
    }
    friend ostream & operator << (ostream & os, Polar pol) {
        os << "distance:: " << pol.distance << " yCord:: " << pol.angle << endl;
    }
    
    operator RecCoord() {
        
        return RecCoord(2.2, 1.1);
    }    
};

class RecCoord {
    double xCord;
    double yCord;
public:
    RecCoord (): xCord (0.00), yCord (0.00) {
        
    }
    RecCoord (double xcord, double ycord): xCord (xcord), yCord (yCord) {
        
    }

    friend ostream & operator << (ostream & os, RecCoord rec) {
        os << "xCord:: " << rec.xCord << " yCord:: " << rec.yCord << endl;
    }
    RecCoord & operator = (Polar &pol) {
        return *this;
    }
    operator Polar() {
        return Polar(7.7, 30);
    }
};


int main (void) {

    Polar p (5.00, 60);
    RecCoord r = p; // this only work in casting not with operator overloading
        
    
    
    cout << p << endl;
    cout << r << endl;
    
    cout << endl << endl;
    return 0;
}