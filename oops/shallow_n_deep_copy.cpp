#include<iostream>
#include<string.h>
using namespace std;

class person{
    public:

    int age;
    string name;
    char *ch;

    person(char ch1[], string name, int age){
        ch = new char[100];
        this -> age = age;
        this -> name = name;
        strcpy(this->ch, ch1);
    }


    //Deep copy
    person(person &temp){
        char *ch1 = new char[strlen(temp.ch) + 1];
        strcpy(ch1, temp.ch);
        this -> ch = ch1;

        this -> age = temp.age;
        this -> name = temp.name;
    }

    void print(){
        cout << "Char: " << this->ch << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

int main(){

    /*  Shallow Copy
    person p1("ABCDE", "Mohan", 16);

    person p2(p1);      //shallow copy

    p1.print();
    p2.print();

    p1.ch[0] = 'S';
    p1.name = "Sohan";
    p1.age = 17;

    p1.print();     //changes of char array occur in both p1, p2
    p2.print();  */


    //Deep copy

    person p1("ABCDE", "Mohan", 16);

    person p2(p1);

    p1.print();
    p2.print();

    p1.ch[0] = 'S';
    p1.name = "Sohan";
    p1.age = 17;

    p1.print();    
    p2.print();
}