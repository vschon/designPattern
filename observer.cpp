#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class ObserverInterface {
public:
    virtual ~ObserverInterface() {}
    virtual void update(int message) = 0;
};

class SubjectInterface {
public:
    virtual ~SubjectInterface();
    virtual void subscribe(ObserverInterface*);
    virtual void unsubscribe(ObserverInterface*);
    virtual void notify(int message);
private:
    vector<ObserverInterface*> observers;
};

SubjectInterface::~SubjectInterface() {}

void SubjectInterface::subscribe(ObserverInterface* observer) {
    observers.push_back(observer);
}

void SubjectInterface::unsubscribe(ObserverInterface* observer) {
    vector<ObserverInterface*>::iterator it = find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
        observers.erase(it);
}

void SubjectInterface::notify(int message) {
    for(auto observer_ : observers) {
        observer_->update(message);
    }
}

class MyObserver : public ObserverInterface {

public:
    explicit MyObserver(const string& str) : name(str) {}
    void update(int message) {
        cout << name << "Got message " << message << endl;
    }
private:
    string name;
};

class MySubject : public SubjectInterface {
public:
    enum Message {ADD, REMOVE};
};

int main() {

    MyObserver observerA("observerA");
    MyObserver observerB("observerB");
    MyObserver observerC("observerC");

    MySubject subject;
    subject.subscribe(&observerA);
    subject.subscribe(&observerB);
    subject.subscribe(&observerC);

    subject.notify(MySubject::ADD);
    subject.notify(MySubject::REMOVE);

    return 0;
}


