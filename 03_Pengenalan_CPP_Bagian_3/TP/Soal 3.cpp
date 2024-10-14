#include <iostream>

int main() {
    int x = 25;   // Variabel biasa dengan nilai 25
    int *ptr;     // Deklarasi pointer bertipe int

    ptr = &x;     // Pointer ptr menyimpan alamat memori dari x

    // Menampilkan alamat memori dari x melalui pointer
    std::cout << "Alamat memori dari x: " << ptr << std::endl;

    // Menampilkan nilai x melalui pointer (dereferencing)
    std::cout << "Nilai dari x (melalui pointer): " << *ptr << std::endl;

    return 0;
}
