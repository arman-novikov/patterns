#include <iostream>

using namespace std;

class Comp
{
public:
    Comp(string CPU, string GPU, string RAM):
        _CPU(CPU), _GPU(GPU), _RAM(RAM) {};
    void show()
    {
        cout<<"\n+++\nCPU: "<<_CPU
            <<" ||| GPU: "<<_GPU
            <<" ||| RAM: "<<_RAM
            <<"\n===\n";
    }
protected:
    string _CPU;
    string _GPU;
    string _RAM;
};


class ICompBuilder
{
public:
    virtual ~ICompBuilder() {};
    virtual Comp* getComp() = 0;
};

class OfficeCompBuilder: public ICompBuilder
{
public:
    Comp* getComp() override
    {
        return new Comp(string("2 cores, 4 threads"),
                        string("embedded graphics"),
                        string("4 gb DDR3"));
    }
};

int main()
{
    OfficeCompBuilder officeCompBuilder;
    Comp *officePC = officeCompBuilder.getComp();
    officePC->show();

    if (officePC)
        delete officePC;

    return 0;
}
