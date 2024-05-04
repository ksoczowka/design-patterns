#include <iostream>

#include "factory.hpp"

int main() {
    std::shared_ptr<Creator> creator = nullptr;

    char version = 'A';

    if (version == 'A') {
        creator = std::make_shared<CreatorProductA>(CreatorProductA());
    } else if (version == 'B') {
        creator = std::make_shared<CreatorProductB>(CreatorProductB());
    } else {
        std::cerr << "No.\n";
        return 1;
    }

    std::shared_ptr<Product> prod = creator->makeProduct();

    std::cout << prod->info() << '\n';

    return 0;
}