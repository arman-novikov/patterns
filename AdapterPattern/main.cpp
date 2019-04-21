#include <iostream>

using namespace std;

class USB
{
public:
    virtual ~USB(){};
    virtual void connect(char pins[4]) {cout<<"USB connected\n";}
};

class COM
{
public:
    virtual ~COM(){};
    virtual void connect(char pins[9]) {cout<<"COM connected\n";}
};

class USB_COM_adapter : public USB
{
    COM _com;
public:
    USB_COM_adapter(const COM &com):_com(com){};
    virtual ~USB_COM_adapter(){};
    virtual void connect(char pins[4])  override
    {
        char _pins[9] = {0};
        for (int i = 0; i < 4; i++)
            _pins[i] = pins[i];
        _com.connect(_pins);
    }
};

class USB_Socket
{
    USB * _usb;
    char _pins[4];
public:
    USB_Socket(USB *usb): _usb(usb)
    {
        for (int i = 0; i < 4; ++i)
            _pins[i] = i;
    }

    void connect()
    {
        _usb->connect(_pins);
    }
};

int main()
{
    USB usb1;
    COM com1;

    USB_Socket soc1(&usb1);
    soc1.connect();

    USB_COM_adapter adap(com1);
    USB_Socket soc2(&adap);
    soc2.connect();
    return 0;
}
