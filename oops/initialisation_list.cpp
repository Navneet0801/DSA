#include<iostream>
using namespace std;

class points{
    int x;
    int y;

    public:

    points(int x, int y):x(x), y(y) {}

    int getx(){
        return x;
    }

    int gety(){
        return y;
    }
};

int main(){
    points p(10, 23);

    cout << p.getx() << endl;
    cout << p.gety() << endl;

    return 0;
}