#include <string>
#include <iostream>

using namespace std;

class Window {
public:
    virtual void draw() = 0;
    virtual string getDescription() = 0;
    virtual ~Window() {}
};

class SimpleWindow : public Window {
public:
    void draw() {
        cout << "Draw simple window" << endl;
    }

    string getDescription() {
        return "simple window\n";
    }
};

class WindowDecorator : public Window {
protected:
    Window* decoratedWindow;
public:
    WindowDecorator(Window* decoratedWindow_) :
        decoratedWindow(decoratedWindow_)
        {}
};

class VerticalScrollBarDecorator : public WindowDecorator {
public:
    VerticalScrollBarDecorator (Window* decoratedWindow_) :
        WindowDecorator(decoratedWindow_) {
           cout <<  "ctor of vertical scroll bar\n";
        }
    void draw() {
        drawVerticalScrollBar();
        decoratedWindow->draw();
    }
    string getDescription() {
        return decoratedWindow->getDescription() + " with vertical scroll bar\n";
    }
private:
    void drawVerticalScrollBar() {}
};

int main() {

    Window* simple = new SimpleWindow;
    cout << simple->getDescription() << endl;

    Window* vert = new VerticalScrollBarDecorator(new SimpleWindow());
    cout << vert->getDescription() << endl;
 
    

    return 0;
}
