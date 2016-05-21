
void func (int x, int y) {

}

void func (double x, double y) {

}

void func (const char *x, const char *y) {

}

void func () {
}

extern "c++" void func () {
}

extern "c" void Otherfunc () {
}

extern "PASCAL" void Otherfunc () {
}

int main (void) {
    func (2,2);
    func (2.2,2.4);
    func ("name_1", "name_2");
    
    return 0;
}