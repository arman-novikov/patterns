#include <iostream>
#include <array>
using namespace std;

typedef array<char, 4> usb_pins_t;
typedef array<char, 9> com_pins_t;

class USB
{
public:
    virtual ~USB(){};
    virtual void connect(usb_pins_t& pins) {cout<<"USB connected\n";}
};

class COM
{
public:
    virtual ~COM(){};
    virtual void connect(com_pins_t pins) {cout<<"COM connected\n";}
};

class USB_COM_adapter : public USB
{
    COM _com;
public:
    USB_COM_adapter(const COM &com):_com(com){};
    virtual ~USB_COM_adapter(){};
    virtual void connect(usb_pins_t& pins)  override
    {
        com_pins_t _pins{};
        for (size_t i = 0; i < _pins.size(); ++i)
            _pins[i] = pins[i];
        _com.connect(_pins);
    }
};

class USB_Socket
{
    USB * _usb;
    usb_pins_t _pins;
public:
    USB_Socket(USB *usb): _usb(usb)
    {
        for (size_t i = 0; i < _pins.size(); ++i)
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
