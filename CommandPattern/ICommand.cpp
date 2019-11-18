#include "ICommand.h"

ReplaceCommand::ReplaceCommand(size_t num, std::string str):
    _new_str(str), _num(num) {}

void ReplaceCommand::exec()
{
    _last_str = (*_doc)[_num];
    (*_doc)[_num] = _new_str;
    std::swap(_last_str, _new_str);
}

void ReplaceCommand::unexec()
{
    ReplaceCommand::exec();
}

InsertCommand::InsertCommand(size_t lineNum, std::string str):
    _lineNum(lineNum), _str(str) {}

void InsertCommand::exec()
{
    _doc->insertLine(_lineNum, _str);
}

void InsertCommand::unexec()
{
    _doc->removeLine(_lineNum);
}
