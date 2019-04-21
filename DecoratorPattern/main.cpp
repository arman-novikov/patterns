#include <iostream>
#include <memory>

using namespace std;

class IObject
{
public:
    void virtual operation() = 0;
};

class Object: public IObject
{
public:
    virtual ~Object() {cout<<"del\n";};
    void virtual operation() override
    {
        cout<<"car\n";
    }
};

class Decorator
{
public:
    Decorator(IObject *obj): _obj_ptr(obj){};
    void decor()
    {
        cout<<"big ";
        _obj_ptr->operation();
    }
private:
    shared_ptr<IObject> _obj_ptr;
};

int main()
{
    Object *obj = new Object();
    Decorator dectr(obj);
    dectr.decor();
    return 0;
}
