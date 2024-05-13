#include "Builder.hpp"

// Director

// CakeBaker
void CakeBaker::setLayers(const int& numberOfLayers) {
    cake_.layers = numberOfLayers;
}

void CakeBaker::setFlavour(const std::string& flavour) {
    cake_.flavour = flavour;
}


// RecipeBaker
void RecipeBaker::setLayers(const int& numberOfLayers) {
    recipe_.layers = numberOfLayers;
}

void RecipeBaker::setFlavour(const std::string& flavour) {
    recipe_.flavour = flavour;
}