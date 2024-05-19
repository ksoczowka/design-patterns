#pragma once

#include <memory>
#include <string>

class Product {
 public:
    int layers;
    std::string flavour;

    void operator=(const Product& rhs);
};

class Cake : public Product {
 public:
    Cake() {}
};

class Recipe : public Product {
 public:
    Recipe() {}
};

class Baker {
 public:
    virtual void reset() = 0;
    virtual void setLayers(const int& numberOfLayers) = 0;
    virtual void setFlavour(const std::string& flavour) = 0;

    virtual std::shared_ptr<Product> getProduct() const = 0; 
};

class CakeBaker : public Baker {
 public:
    CakeBaker() {}

    void reset() override;
    void setLayers(const int& numberOfLayers) override;
    void setFlavour(const std::string& flavour) override;

    std::shared_ptr<Product> getProduct() const override { return std::make_shared<Product>(cake_); }
 private:
    Cake cake_;
};

class RecipeBaker : public Baker {
 public:
    RecipeBaker() {}

    void reset() override;
    void setLayers(const int& numberOfLayers) override;
    void setFlavour(const std::string& flavour) override;

    std::shared_ptr<Product> getProduct() const override { return std::make_shared<Product>(recipe_); }
 private:
    Recipe recipe_;
};

class Director {
 public:
    std::shared_ptr<Product> makeChocolateCake(std::shared_ptr<Baker> baker);
    std::shared_ptr<Product> makeStarberryCake(std::shared_ptr<Baker> baker);

    std::shared_ptr<Product> makeChocolateCakeRecipe(std::shared_ptr<Baker> baker);
    std::shared_ptr<Product> makeStarberryRecipe(std::shared_ptr<Baker> baker);
};
