/*
Static Member Variable
Static Member Function
Static Class
*/

#include <bits/stdc++.h>
using namespace std;

class A {
public:
    int x;
    static int y;
    void readValue() {
        cout << this->x << ", " << this->y << endl;
    }

    void readX() { cout << this->x << endl; }

    //static member function can access only static member variable
    //in function below it x cannot be accessed and 
    // "this pointer" cannot be accessed as well
    //but y can be
    static void readY() { cout << y << endl; }
};

//static member variable requires specific memory allocation 
//as this is common across objects
int A::y;




int main() {
    shared_ptr<A> a1 = make_shared<A>();
    shared_ptr<A> a2 = make_shared<A>();
    a1->x = 10;
    a2->x = 20;

    a1->y = 100;
    a2->y = 200;

    a1->readValue();
    a2->readValue();

    cout << "STATIC MEMBER FUNCTION DEMO" << endl;
    a1->readX();
    a2->readX();

    a1->readY();
    a2->readY();
    cout << "another declaration for static member function" << endl;
    A::readY();

}
