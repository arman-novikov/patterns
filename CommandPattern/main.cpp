#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::swap;

class Document
{
public:
	Document()
	{
		_data.reserve(100);
	}

	void insertLine(int lineNum, const string &str)
	{
		if (lineNum <= _data.size())
			_data.insert(_data.begin() + lineNum, str);
		else
			cout << "error\n";
	}

	void removeLine(int lineNum)
	{
		if (lineNum <= _data.size())
			_data.erase(_data.begin() + lineNum);
		else
			cout << "error\n";
	}

	void show()
	{
		for (int i = 0; i < _data.size(); ++i)
			cout << i << ". " << _data[i] << endl;

		cout << "==============================================\n";
	}

	string& operator[](int num)
	{
		return _data[num];
	}
private:
	vector<string> _data;
};

class ICommand
{
public:
	virtual ~ICommand() {};
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
	ReplaceCommand(int nnum, string nstr) : _new_str(nstr), _num(nnum) {};

	virtual void exec() override
	{
		_last_str = (*_doc)[_num];
		(*_doc)[_num] = _new_str;
		swap(_last_str, _new_str);
	}

	virtual void unexec() override
	{
		exec();
	}

	virtual ~ReplaceCommand() {};

private:
	string _last_str, _new_str;
	int _num;
};

class InsertCommand: public ICommand
{
public:
	InsertCommand(int lineNum, string str) : _lineNum(lineNum), _str(str) {};
	virtual void exec() override
	{
		_doc->insertLine(_lineNum, _str);
	}

	virtual void unexec() override
	{
		_doc->removeLine(_lineNum);
	}

	virtual ~InsertCommand() {};
private:
	int _lineNum;
	string _str;
};

class Receiver
{
public:
	void insert(int lineNum, string str)
	{
		comm = new InsertCommand(lineNum, str);
		comm->setDocument(&doc);
		comm->exec();
		doneCommands.push_back(comm);
	}

	void replace(int nnum, string nstr)
	{
		comm = new ReplaceCommand(nnum, nstr);
		comm->setDocument(&doc);
		comm->exec();
		doneCommands.push_back(comm);
	}

	void undo()
	{
		comm = doneCommands.back();
		comm->unexec();

		doneCommands.pop_back();
		delete comm;
	}

	void show()
	{
		doc.show();
	}
private:
	vector<ICommand*> doneCommands;
	Document doc;
	ICommand *comm;
};

int main()
{
	char s = '1';
	int line;
	string str;
	Receiver res;
	while (s != 'e') {
		cout << "What to do: \n1.Add a line\n2.Replace a line\n3.Undo last command" << endl;
		cin >> s;
		switch (s)
		{
		case '1':
			cout << "What line to insert: ";
			cin >> line;
			cout << "What to insert: ";
			cin >> str;
			res.insert(line, str);
			break;
		case '2':
			cout << "What line to replace: ";
			cin >> line;
			cout << "What to replace with: ";
			cin >> str;
			res.replace(line, str);
			break;
		case '3':
			res.undo();
			break;
		}
		cout << "$$$DOCUMENT$$$" << endl;
		res.show();
		cout << "$$$DOCUMENT$$$" << endl;
	}

	return 0;
}
