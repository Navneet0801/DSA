#include<iostream>
using namespace std;

class hello{
    double b;
    int a;
    char ch;
};

class hello1{
    int a;
    double b;
    char ch;
};

int main(){
    hello h;
    cout << sizeof(h) << endl;      //16

    hello1 h1;
    cout << sizeof(h1) << endl;     //24        coz of padding

    char ch;
    cout << sizeof(ch) << endl;
}