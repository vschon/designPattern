#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance();

private:
    Singleton() {cout << "Ctor\n"; };
    ~Singleton() {cout << "Dtor\n";};
    Singleton(const Singleton&);
    const Singleton& operator=(const Singleton&);
};


Singleton& Singleton::getInstance() {
    static Singleton instance;//static variable, initialized once and guranteed destructed;
    return instance;
}

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    return 0;
}
