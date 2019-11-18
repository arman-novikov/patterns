#pragma once
#include "ICommand.h"

class Receiver
{
public:
	void insert(size_t lineNum, std::string str);
	void replace(size_t nnum, std::string nstr);
	void undo();
	void show();
	~Receiver();
	Receiver() = default;
private:
	std::vector<ICommand*> doneCommands;
	Document doc;
};
