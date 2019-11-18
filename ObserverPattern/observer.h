#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void handleEvent(const Observed<std::string> &obj) = 0;
};

class Observer: public IObserver
{
public:
    virtual ~Observer(){};
    virtual void handleEvent(const Observed<std::string> &obj) override;
};

void Observer::handleEvent(const Observed<std::string> &obj)
{
    cout<<obj.getEvent()<<endl;
}
