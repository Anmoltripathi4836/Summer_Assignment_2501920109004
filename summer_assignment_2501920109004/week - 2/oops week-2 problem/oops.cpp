#include <iostream>
using namespace std;


class Playable {
public:
    virtual void play() = 0;   
    virtual ~Playable() {}
};

class Veena : public Playable {
public:
    void play() override {
        cout << "Veena is playing..." << endl;
    }
};

class Saxophone : public Playable {
public:
    void play() override {
        cout << "Saxophone is playing..." << endl;
    }
};

int main() {

    Veena v;
    v.play();

    Saxophone s;
    s.play();

    Playable* p1 = new Veena();
    Playable* p2 = new Saxophone();

    p1->play();
    p2->play();

    delete p1;
    delete p2;

    return 0;
}