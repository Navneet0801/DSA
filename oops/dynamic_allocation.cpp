#include<iostream>
using namespace std;

class person{
    public:

    string name;
    int age;
};


int main(){
    person p1;      //static

    p1.name = "Raman";
    p1.age = 35;

    cout << "person 1 name : " << p1.name << endl;
    cout << "person 1 age : " << p1.age << endl;

    person * p2 = new person();     //dynamic

    (*p2).name = "Vaibhav";
    p2 -> age = 45;

    cout << "person 1 name : " << (*p2).name << endl;
    cout << "person 1 age : " << p2 -> age << endl;

    free(p2);
}