#include <iostream>
#include <memory>

using namespace std;

class IObject
{
public:
    void virtual operation() = 0;
    virtual ~IObject() = default;
};

class ObjectA: public IObject
{
public:
    void virtual operation() override
    {
        cout<<"car\n";
    }
    virtual ~ObjectA() {cout << "dtor\n";};
};

class Decorator
{
public:
    Decorator(shared_ptr<IObject> obj):
        _obj_ptr(obj){}
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
    auto obj = make_shared<ObjectA>(ObjectA());
    Decorator dectr(obj);
    dectr.decor();
    obj->operation();
    return 0;
}
