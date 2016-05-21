// calling conventions

// vendors functions
void func (int x, int y) {

}// ret 0

// variable number of arguments 
void __cdecl func1 (int x, int y) {

}// ret 0//consumer is going to be release parameters values from stack (stack unwinding)


// percise number of arguments
void __stdcall func2 (int x, int y) {

}// ret 8 //vendor is going to be release parameters values from stack


void __fastcall func3 (int x, int y) {
    
}//ret 0

class CA 
{
public: 
    void __thiscall func4 ()
    {
    }
    void fun5()
    {
    }
};

int main (void) {
    
    // consumers func
    func (2, 2);
    
    func1 (4, 7);
    
    func2 (4, 7); // arguments are pushed to stack
    
    func3 (2, 4); //arguments are moves to register
    
    CA obj1;
    
    obj1.func4()
    
    return 0;
}