#pragma once
#include "Document.h"

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void exec() = 0;
	virtual void unexec() = 0;
	virtual void setDocument(Document *doc) final
	{
		_doc = doc;
	}
protected:
	Document *_doc;
};

class ReplaceCommand : public ICommand
{
public:
	ReplaceCommand(size_t num, std::string str);

	virtual void exec() override;
	virtual void unexec() override;
	virtual ~ReplaceCommand() = default;
private:
	std::string _last_str, _new_str;
	size_t _num;
};

class InsertCommand: public ICommand
{
public:
	InsertCommand(size_t lineNum, std::string str);
	virtual void exec() override;
	virtual void unexec() override;
	virtual ~InsertCommand() = default;
private:
	int _lineNum;
	std::string _str;
};
