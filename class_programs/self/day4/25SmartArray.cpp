#include <iostream>
using namespace std;
// /*working code*/
// class SmArray {
//     int arr[5];
// public:
//     
//     SmArray () {
//         arr [0] = 10;
//         arr [1] = 20;
//         arr [2] = 30;
//         arr [3] = 40;
//         arr [4] = 50;
//     }
//     class Helper {
//         SmArray *smptr;
//         int index;
//     public:
//         Helper (SmArray *smptr, int index): smptr (smptr), index (index) {
//         }
//         
//         operator int() {
//             cout << "read operation" << endl;
//             return smptr->arr[index];
//         }
//         Helper &operator= (int para) {
//             cout << "write operation" << endl;
//             smptr-> arr[index] = para;
//             return *this;
//         }
//         Helper &operator= (Helper para) {
//             cout << "read/write operation" << endl;
//             smptr->arr[index] = para.smptr->arr[para.index];
//             return *this;
//         }        
//     };
//     Helper operator[] (int index) {
//         return Helper(this, index);
//     }
//     friend ostream & operator << (ostream & os, SmArray &sm) {
//         for (int i = 0x00; i < 5; i++) {
//             os << "arr [" << i << "]:: " << sm.arr [i] << endl;
//         }
//         return os;
//     }
// };
// 
// int main (void) {
//     int x = 0x00;
//     SmArray arr;
//     arr [1] = 999;
//     x = arr [3];
//     arr [4] = arr [0];
//         
//     cout << arr << endl; 
//     
//     cout << endl << endl;
//     return 0;
// }


class SmArray {
    int arr[2][3];
public:
    
    SmArray () {
        arr [0][0] = 10;
        arr [0][1] = 20;
        arr [0][2] = 30;
        arr [1][0] = 40;
        arr [1][1] = 50;
        arr [1][2] = 50;
    }
    class Helper {
        SmArray *smptr;
        int index;
    public:
        Helper (SmArray *smptr, int index): smptr (smptr), index (index) {
        }
        
        operator int() {
            cout << "read operation" << endl;
            return smptr->arr[index];
        }
        Helper &operator= (int para) {
            cout << "write operation" << endl;
            smptr-> arr[index] = para;
            return *this;
        }
        Helper &operator= (Helper para) {
            cout << "read/write operation" << endl;
            smptr->arr[index] = para.smptr->arr[para.index];
            return *this;
        }        
    };
    Helper operator[] (int index) {
        return Helper(this, index);
    }
    friend ostream & operator << (ostream & os, SmArray &sm) {
        for (int i = 0x00; i < 5; i++) {
            os << "arr [" << i << "]:: " << sm.arr [i] << endl;
        }
        return os;
    }
};

int main (void) {
    int x = 0x00;
    SmArray arr;
    arr [1] = 999;
    x = arr [3];
    arr [4] = arr [0];
        
    cout << arr << endl; 
    
    cout << endl << endl;
    return 0;
}