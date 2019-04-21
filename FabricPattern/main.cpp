#include <iostream>
#include <memory>

using namespace std;

class IProduct
{
public:
    virtual ~IProduct(){};
    virtual void getName() const = 0;
};

class ProductA: public IProduct
{
    virtual ~ProductA(){};
    virtual void getName() const override
    {
        cout<<"product A\n";
    }
};

class ProductB: public IProduct
{
    virtual ~ProductB(){};
    virtual void getName() const override
    {
        cout<<"product B\n";
    }
};

class IProducer
{
public:
    virtual ~IProducer(){};
    virtual IProduct* produce() const = 0;
};

class ProducerA: public IProducer
{
public:
    virtual ~ProducerA(){};
    virtual IProduct* produce() const override
    {
        return new ProductA();
    }
};

class ProducerB: public IProducer
{
public:
    virtual ~ProducerB(){};
    virtual IProduct* produce() const override
    {
        return new ProductB();
    }
};

int main()
{
    ProducerA Apro;
    ProducerB Bpro;
    const IProducer* producers[2] {&Apro, &Bpro};

    for (int i = 0; i < 2; ++i) {
        unique_ptr<IProduct> product(producers[i]->produce());
        product->getName();
    }
    return 0;
}
