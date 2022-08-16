#include<iostream>

using namespace std;

class ComplexNumbers {
    int r;
    int i;
    
    public:
    ComplexNumbers(int real, int imaginary){
        this -> r = real;
        this -> i = imaginary;
    }
    
    void plus(ComplexNumbers c2){
        this -> r += c2.r;
        this -> i += c2.i;
    }

    void print(){
        cout << this->r << " + " << "i" << this->i;
    }
    
    void multiply(ComplexNumbers c2){
        int real = this -> r;
        int image = this -> i;
        this -> r = (real * c2.r) - (image * c2.i);
        this -> i = (real * c2.i) + (image * c2.r);
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}