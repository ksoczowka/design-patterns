#include "bridge.hpp"

#include <iostream>

int main () {
    std::shared_ptr<NewImplementationA> impl = std::make_shared<NewImplementationA>();

    std::shared_ptr<NewAbstractionA> abst = std::make_shared<NewAbstractionA>();

    abst->setImplementation(impl);

    std::cout << abst->info() << ' ' << abst->getImplementationVersionn() << '\n';

    return 0;
}