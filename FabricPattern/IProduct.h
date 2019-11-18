#pragma once
#include <iostream>

class IProduct
{
public:
    virtual void use() const = 0;
    virtual ~IProduct() = default;
};

class ProductA: public IProduct
{
public:
    void use() const override
        { std::cout<<"product A\n"; }
    virtual ~ProductA() = default;
};

class ProductB: public IProduct
{
public:
    void use() const override
        { std::cout<<"product B\n"; }
    virtual ~ProductB() = default;
};
