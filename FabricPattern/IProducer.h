#pragma once
#include "IProduct.h"
#include <memory>

class IProducer
{
public:
    virtual ~IProducer() = default;
    virtual IProduct* produce() const = 0;
};

class ProducerA: public IProducer
{
public:
    IProduct* produce() const override
        { return new ProductA(); }
    virtual ~ProducerA() = default;
};

class ProducerB: public IProducer
{
public:
    IProduct* produce() const override
        { return new ProductB(); }
    virtual ~ProducerB() = default;
};
