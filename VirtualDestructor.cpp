/*
Base and Derived class constructor and destructor
virtual
*/

#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal Constructor" << endl; }
    virtual ~Animal() { cout << "Animal Destructor" << endl; }
    virtual void setName() = 0;
    virtual void getName() = 0;
};

class Lion : public Animal{
string name;
public:
    Lion() { cout << "Lion CTor" << endl; }
    ~Lion() { cout << "Lion DTor" << endl; }
    void setName() { this->name = "Lion"; }
    void getName() { cout << this->name << endl; }
};

int main() {
    Animal *a = new Lion();
    a->setName();
    a->getName();
    delete a;
    return 0;
}