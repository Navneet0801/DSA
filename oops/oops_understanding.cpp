#include<iostream>
using namespace std;

class person{
    string name;
    int age;

public:
    void getDetails(){             //getter
        cout << "Person name is: " << name << endl;
        cout << "Person's age is: " << age << endl;
    }

    void setDetails(string s, int a){       //setter
        name = s;
        age = a;
    }
};

int main(){
    person p1;

    p1.setDetails("Navneet", 21);

    p1.getDetails();
}