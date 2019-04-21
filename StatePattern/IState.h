#ifndef ISTATE_H_INCLUDED
#define ISTATE_H_INCLUDED

#include <memory>

class IProcess;

class IState
{
protected:
	IProcess *_process;
public:
	IState(IProcess *process):
        _process(process) {};
	virtual ~IState() {};
	virtual void getReady() = 0;
	virtual void getStarted() = 0;
	virtual void getStopped() = 0;
};

class ReadyState: public IState
{
public:
	ReadyState(IProcess *process) : IState(process) {};
	void getReady() override;
	void getStarted() override;
	void getStopped() override;
};

class RunningState: public IState
{
public:
	RunningState(IProcess *process) : IState(process) {};

	void getReady() override;
	void getStarted() override;
	void getStopped() override;
};

class StopState: public IState
{
public:
	StopState(IProcess *process) : IState(process) {};
	void getReady() override;
	void getStarted() override;
	void getStopped() override;
};
#endif // ISTATE_H_INCLUDED
