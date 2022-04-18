#include <iostream>
#include "Weight.h"

Weight ehak;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << Weight::convertWeight(3.0, Weight::KILO, Weight::POUND);
    ehak = Weight(3.0, Weight::KILO, 300);
    Weight eknl = Weight(4.1, Weight::SLUG, 30);
    Weight::UnitOfWeight unitOfWeight = Weight::KILO;
    std::cout << unitOfWeight ;
    ehak.dump();
    eknl.dump();
    Weight nan = Weight();
    nan.dump();
}
