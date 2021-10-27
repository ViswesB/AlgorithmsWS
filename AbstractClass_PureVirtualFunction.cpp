/*
abstract class and pure virtual function
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Person {
public:
    virtual void getName() = 0;
};

class Father : public Person {
    string s;
public:
    Father(string str) : s{str} {}
    void getName() override {
        cout << s << endl;
    }
};

class Mother : public Person {
    string s;
public:
    Mother(string str) : s{str} {}
    void getName() override {
        cout << s << endl;
    }
};

int main() {
    shared_ptr<Father> f = make_shared<Father>("Viswes");
    f->getName();
    shared_ptr<Mother> m = make_shared<Mother>("Shilpa");
    m->getName();

    cout << "trying to assign father and mother " << endl;
    Person *p = new Father("ABC");
    p->getName();
    delete p;
    p = new Mother("PQR");
    p->getName();
    delete p;
    p = nullptr;
    return 0;
}