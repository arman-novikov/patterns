#pragma once

#include <vector>
#include <string>
#include <iostream>

class Document
{
public:
    Document(size_t docSize = Document::DEFAULT_SIZE);
    void insertLine(size_t lineNum, const std::string &str);
    void removeLine(size_t lineNum);
    void show();
    std::string& operator[](size_t num);
    static constexpr size_t DEFAULT_SIZE = 100U;
private:
    std::vector<std::string> _data;
};
