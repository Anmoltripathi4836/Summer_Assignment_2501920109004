#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Compartment {
public:
    virtual string notice() = 0; 
    virtual ~Compartment() {}
};

class FirstClass : public Compartment {
public:
    string notice() override {
        return "First Class Compartment";
    }
};

class Ladies : public Compartment {
public:
    string notice() override {
        return "Ladies Compartment";
    }
};

class General : public Compartment {
public:
    string notice() override {
        return "General Compartment";
    }
};

class Luggage : public Compartment {
public:
    string notice() override {
        return "Luggage Compartment";
    }
};

int main() {
    srand(time(0));

    Compartment* coaches[10];

    for (int i = 0; i < 10; i++) {
        int r = rand() % 4 + 1; 

        switch (r) {
            case 1:
                coaches[i] = new FirstClass();
                break;
            case 2:
                coaches[i] = new Ladies();
                break;
            case 3:
                coaches[i] = new General();
                break;
            case 4:
                coaches[i] = new Luggage();
                break;
        }
    }

    cout << "Railway Compartments:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Compartment " << i + 1
             << " : " << coaches[i]->notice() << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete coaches[i];
    }

    return 0;
}