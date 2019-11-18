#include "Document.h"

using namespace std;

Document::Document(size_t docSize)
{
    _data.resize(docSize, std::string(""));
}

void Document::insertLine(size_t lineNum, const std::string &str)
{
    if (lineNum <= _data.size())
        _data.insert(_data.begin() + lineNum, str);
    else
        cout << "error\n";
}

void Document::removeLine(size_t lineNum)
{
    if (lineNum <= _data.size())
        _data.erase(_data.begin() + lineNum);
    else
        cout << "error\n";
}

void Document::show()
{
    for (size_t i = 0; i < _data.size(); ++i)
        if(!_data[i].empty())
            cout << i << ". " << _data[i] << endl;

    cout << "==============================================\n";
}


std::string& Document::operator[](size_t num)
{
    return _data[num];
}
