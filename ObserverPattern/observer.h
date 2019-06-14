#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

#include <iostream>
//#include "observed.h"
/*
template <typename EventType>
class Observed;
*/
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

#endif // OBSERVER_H_INCLUDED
