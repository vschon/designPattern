#include <iostream>
using namespace std;

class Button {

public:
    virtual void paint() = 0;
};

class WinButton : public Button {

public:
    void paint() {
        cout << "window button \n";
    }
};

class MacButton : public Button {
public:
    void paint() {
        cout << "Mac Button \n";
    }
};

class ScrollBar {
public:
    virtual void paint() = 0;
};

class WinScrollBar : public ScrollBar {
public:
    void paint() {
        cout << "Window ScrollBar \n";
    }
};

class MacScrollBar : public ScrollBar {
public:
    void paint() {
        cout << "Mac ScrollBar \n";
    }
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual ScrollBar* createScrollBar() = 0;
};


class WinFactory : public GUIFactory {

public:
    Button* createButton() {
        return new WinButton;
    }
    ScrollBar* createScrollBar() {
        return new WinScrollBar;
    }
};

class MacFactory : public GUIFactory {

    Button* createButton() {
        return new MacButton;
    }

    ScrollBar* createScrollBar() {
        return new MacScrollBar;
    }
};

int main() {
    GUIFactory* guiFactory;
    Button* btn;
    ScrollBar *sb;

    guiFactory = new MacFactory;
    btn = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollBar();
    sb->paint();

    guiFactory = new WinFactory;
    btn = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollBar();
    sb->paint();
   


    

    return 0;
}
