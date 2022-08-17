#include<iostream>
using namespace std;

class human{
    private:
        int age;
    public:
        string gender;
    protected:
        string name;
};

class male : public human{
    public:
    void provide(){
        cout << "He is providing" << endl;
    }
};

class female : protected human{
    public:
    void care(){
        cout << "Take care of everything" << endl;
    }
};

class others : private human{
    public:
    void people(){
        cout << "others" << endl;
    }
};

int main(){
    human h;
    male m;
    female f;
    others o;

    //error private member cout << h.age << endl;
    cout << h.gender << endl;
    //error protected member cout << h.name << endl;

    //error private cout << m.age << endl;
    cout << m.gender << endl;
    //error protected cout << m.name << endl;
    m.provide();

    /* error in all private and protected cout << f.age << endl;
    cout << f.gender << endl;
    cout << f.name << endl;*/
    f.care();

    /* all are not accessible cout << o.age << endl;
    cout << o.gender << endl;
    cout << o.name << endl;*/
    o.people();
}