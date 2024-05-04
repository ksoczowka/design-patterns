#include "builder.hpp"

#include <iostream>

int main() {
    Director director = Director();
    director.changeBuilder('A');

    std::shared_ptr<Product> prod = director.make();

    std::cout << prod->info() << ": " << prod->to_string() << '\n';

    director.changeBuilder('B');

    prod = director.make();

    std::cout << prod->info() << ": " << prod->to_string() << '\n';

    return 0;
}