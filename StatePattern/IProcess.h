#ifndef IPROCESS_H_INCLUDED
#define IPROCESS_H_INCLUDED

#include "IState.h"

class IProcess
{
public:
	void setState(IState *state)
	{
		if (_currentState)
			delete _currentState;
		_currentState = state;
	}
protected:
	IState *_currentState;
};

class Process: public IProcess
{
public:
	Process()
	{
		_currentState = new ReadyState(this);
	}

	~Process()
	{
		if (_currentState)
			delete _currentState;
	}
	void getReady()
	{
		_currentState->getReady();
	}

	void getStarted()
	{
		_currentState->getStarted();
	}

	void getStopped()
	{
		_currentState->getStopped();
	}
};

#endif // IPROCESS_H_INCLUDED
