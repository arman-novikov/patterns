#include "IProcess.h"
#include <iostream>
using namespace std;

void ReadyState::getReady()
{
	cout << "process has already been ready\n";
}

void ReadyState::getStarted()
{
	IState *newState = new RunningState(_process);
	_process->setState(newState);
	cout << "process is on\n";
}

void ReadyState::getStopped()
{
	cout << "process can't be stopped cos it's not running\n";
}

void RunningState::getReady()
{
	cout << "process has already been ready and is running now\n";
}

void RunningState::getStarted()
{
	cout << "process has already been set on\n";
}

void RunningState::getStopped()
{
	IState *newState = new StopState(_process);
	_process->setState(newState);
	cout << "process is stopped\n";
}

void StopState::getReady()
{
	IState *newState = new ReadyState(_process);
	_process->setState(newState);
	cout << "process is ready\n";
}

void StopState::getStarted()
{
	cout << "can't be on cos of process is not ready\n";
}

void StopState::getStopped()
{
	cout << "process has already been stoppped\n";
}
