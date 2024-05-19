#include "Builder.hpp"

// Product
void Product::operator=(const Product& rhs) {
    this->flavour = rhs.flavour;
    this->layers = rhs.layers;
}

// CakeBaker
void CakeBaker::reset() {
    cake_ = Cake();
}

void CakeBaker::setLayers(const int& numberOfLayers) {
    cake_.layers = numberOfLayers;
}

void CakeBaker::setFlavour(const std::string& flavour) {
    cake_.flavour = flavour;
}


// RecipeBaker
void RecipeBaker::reset() {
    recipe_ = Recipe();
}
void RecipeBaker::setLayers(const int& numberOfLayers) {
    recipe_.layers = numberOfLayers;
}

void RecipeBaker::setFlavour(const std::string& flavour) {
    recipe_.flavour = flavour;
}

// Director
std::shared_ptr<Product> Director::makeChocolateCake(std::shared_ptr<Baker> baker) {
    baker->reset();
    baker->setFlavour("Chocolate");
    baker->setLayers(2);
    
    return baker->getProduct();
}

std::shared_ptr<Product> Director::makeChocolateCakeRecipe(std::shared_ptr<Baker> baker) {
    baker->reset();
    baker->setFlavour("Chocolate");
    baker->setLayers(2);
    
    return baker->getProduct();
}