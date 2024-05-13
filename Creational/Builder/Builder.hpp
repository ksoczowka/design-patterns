#pragma once

#include <string>

class Cake {
 public:
    int layers;
    std::string flavour;
};

class Recipe {
 public:
    int layers;
    std::string flavour;
};

class Baker {
 public:
    virtual void reset() = 0;
    virtual void setLayers(const int& numberOfLayers) = 0;
    virtual void setFlavour(const std::string& flavour) = 0;
};

class CakeBaker : public Baker {
 public:
    CakeBaker(){}
    void setLayers(const int& numberOfLayers) override;
    void setFlavour(const std::string& flavour) override;
 private:
    Cake cake_;
};

class RecipeBaker : public Baker {
 public:
    void setLayers(const int& numberOfLayers) override;
    void setFlavour(const std::string& flavour) override;
 private:
    Recipe recipe_;
};

class Director {
 public:
    Cake makeChocolateCake(Baker baker);
    Cake makeStarberryCake(Baker baker);

    Recipe makeChocolateCakeRecipe(Baker baker);
    Recipe makeStarberryRecipe(Baker baker);
};
