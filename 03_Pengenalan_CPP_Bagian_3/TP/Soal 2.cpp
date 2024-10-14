#include <iostream>

int main() {
    int x = 10;
    double y = 20.5;
    char z = 'A';

    std::cout << "Alamat memori dari x: " << &x << std::endl;
    std::cout << "Alamat memori dari y: " << &y << std::endl;
    std::cout << "Alamat memori dari z: " << (void*)&z << std::endl;

    return 0;
}