#include <iostream>
#include "Weight.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << Weight::convertWeight(3.0, Weight::KILO, Weight::POUND);

}
