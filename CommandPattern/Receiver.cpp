#include "Receiver.h"

void Receiver::insert(size_t lineNum, std::string str)
{
    ICommand *comm = new InsertCommand(lineNum, str);
    comm->setDocument(&doc);
    comm->exec();
    doneCommands.push_back(comm);
}

void Receiver::replace(size_t nnum, std::string nstr)
{
    ICommand *comm = new ReplaceCommand(nnum, nstr);
    comm->setDocument(&doc);
    comm->exec();
    doneCommands.push_back(comm);
}

void Receiver::undo()
{
    if (doneCommands.empty()) {
        std::cerr << "nothing to undo" << std::endl;
        return;
    }
    ICommand *comm = doneCommands.back();
    comm->unexec();

    doneCommands.pop_back();
    delete comm;
}

void Receiver::show()
{
    doc.show();
}

Receiver::~Receiver() {}
