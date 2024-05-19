// Builder but it's about cakes

#include "Builder.hpp"

#include <iostream>

int main() {
    std::shared_ptr<Product> cake = std::make_shared<Cake>(Cake());
    std::shared_ptr<Product> recipe = std::make_shared<Recipe>(Recipe());

    std::shared_ptr<Baker> chocolateCakeBaker = std::make_shared<CakeBaker>(CakeBaker());
    std::shared_ptr<Baker> chocholateCakeRecipeBaker = std::make_shared<RecipeBaker>(RecipeBaker());
 
    std::shared_ptr<Director> director = std::make_shared<Director>(Director());

    cake = director->makeChocolateCake(chocolateCakeBaker);

    std::cout << cake->flavour << ' ' << cake->layers << '\n';

    recipe = director->makeChocolateCakeRecipe(chocholateCakeRecipeBaker);

    std::cout << recipe->flavour << ' ' << recipe->layers << '\n';
    
    

    return 0;
}