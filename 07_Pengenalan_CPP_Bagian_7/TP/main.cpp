#include <iostream>
#include <string>
#include "stack.h"

// Fungsi untuk menguji stack berdasarkan sisa digit terakhir NIM MOD 4
void testStack(int remainder) {
    Stack S;
    createStack(S);

    string data;
    int num_to_pop;

    // Menentukan data dan jumlah elemen yang akan di-pop berdasarkan remainder
    if (remainder == 0) {
        data = "IFLABJAYA";
        num_to_pop = 5;
    } else if (remainder == 1) {
        data = "HALOBANDUNG";
        num_to_pop = 7;
    } else if (remainder == 2) {
        data = "PERCAYADIRI";
        num_to_pop = 8;
    } else if (remainder == 3) {
        data = "STRUKTURDATA";
        num_to_pop = 9;
    }

    // Menyimpan data ke dalam stack
    for (char c : data) {
        push(S, c);
    }

    // Cetak hasil sesuai dengan jumlah elemen yang di-pop
    printInfo(S, num_to_pop);
}

int main() {
    int NIM_last_digit = 2;
    int remainder = NIM_last_digit % 4;

    testStack(remainder);

    return 0;
}