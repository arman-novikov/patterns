#ifndef OBSERVED_H_INCLUDED
#define OBSERVED_H_INCLUDED

#include <list>
using std::list;

class IObserver;

template <typename EventType>
class Observed
{
public:
    void addObserver(IObserver&);
    void removeObserver(IObserver&);
    void setEvent(const EventType&);
    EventType getEvent() const;
private:
    void notifyObservers();
    list<IObserver*> _observers;
    EventType _event;
};

template <typename EventType>
void Observed<EventType>::addObserver(IObserver &obs)
{
    _observers.push_back(&obs);
}

template <typename EventType>
void Observed<EventType>::removeObserver(IObserver &obs)
{
    _observers.remove(&obs);
}

template <typename EventType>
void Observed<EventType>::setEvent(const EventType &event)
{
    _event = event;
    notifyObservers();
}

template <typename EventType>
EventType Observed<EventType>::getEvent() const
{
    return _event;
}

template <typename EventType>
void Observed<EventType>::notifyObservers()
{
    for (auto obs: _observers)
        obs->handleEvent(*this);
}

#endif // OBSERVED_H_INCLUDED
