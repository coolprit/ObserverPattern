#include "Listener.h"
#include <iostream>
#include <string>

// Example struct
struct Clickable : Listener
{
    void click()
    {
        emit();
    }
};

// Example struct
struct Button : Observer
{
    explicit Button(std::string name, Clickable& clickable) : clickable_(clickable)
    {
        name_ = name;
        clickable_.add(*this);
    }

    ~Button() override
    {
        clickable_.remove(*this);
    }

    void intercept(Listener& el) override
    {
        std::cout << "Button " + name_ + " has been clicked!" << std::endl;
    }

private:
    std::string name_;
    Clickable& clickable_;
};

int main(int argc, char* argv[])
{
    Clickable clickable;
    Button btn("btn1", clickable);
    Button btn2("btn2", clickable);

    clickable.click();
    
    return 0;
}
