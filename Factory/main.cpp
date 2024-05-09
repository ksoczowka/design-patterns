#include <iostream>

#include "factory.hpp"

int main() {
    std::shared_ptr<Creator> creator = nullptr;

    char version = ' ';
    std::cout << "Please choose version of Creator to use [A/B]: ";
    std::cin >> version;

    if (version == 'A' || version == 'a') {
        creator = std::make_shared<CreatorProductA>(CreatorProductA());
    } else if (version == 'B' || version == 'b') {
        creator = std::make_shared<CreatorProductB>(CreatorProductB());
    } else {
        std::cerr << "No.\n";
        return 1;
    }

    std::shared_ptr<Product> prod = creator->makeProduct();

    std::cout << prod->info() << '\n';

    return 0;
}