#pragma once

#include <iostream>
#include <memory>

class Product {
 public:
    Product(){}

    virtual std::string info() = 0;
};

class NewProductA : public Product {
 public:
    NewProductA() {}

    std::string info() override {
        return "NewProductA()";
    }
};

class NewProductB : public Product {
 public:
    NewProductB() {}

    std::string info() override {
        return "NewProductB()";
    }
};

class Creator {
 public:
    Creator() {}

    virtual std::shared_ptr<Product> makeProduct() = 0;
};

class CreatorProductA : public Creator {
 public:
    CreatorProductA() {}
    std::shared_ptr<Product> makeProduct() override {
        return std::make_shared<NewProductA>(NewProductA());
    }
};

class CreatorProductB : public Creator {
 public:
 CreatorProductB() {}
    std::shared_ptr<Product> makeProduct() override {
        return std::make_shared<NewProductB>(NewProductB());
    }
};