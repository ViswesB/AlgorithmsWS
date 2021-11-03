/*
Demo on Friend class and Friend Function

friend function or class is used primarily to access other class private and protected 
member function and member variables
*/ 

#include <iostream>
#include <memory>
using namespace std;

class Entity {
private:
    int x;
public:
    Entity(int a) : x{a} {}
    Entity(const Entity& other) {
        this->x = other.x;
    }

    Entity& operator=(const Entity& other) {
        this->x = other.x;
        return *this;
    }

    int getX() {
        return this->x;
    }

    friend void setX(Entity&,int);
    friend class Player;
};

class Player {
public:
    void setXFromPlayer(Entity& ent,int x) {
        ent.x = x;
    }
};

// function trying to set x in Entity class
void setX(Entity& obj,int x) {
    obj.x = x;
}

int main() {
    shared_ptr<Entity> ent = make_shared<Entity>(10);

    //setting from friend function
    setX(*(ent.get()),40);
    cout << ent->getX() << endl;

    //setting from friend class
    shared_ptr<Player> player = make_shared<Player>();
    player->setXFromPlayer(*(ent.get()),100);
    cout << ent->getX() << endl;
}