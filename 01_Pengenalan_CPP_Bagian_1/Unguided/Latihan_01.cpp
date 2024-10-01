#include <iostream>
using namespace std;

int main() {
    float num1, num2;

    cout << "Masukkan bilangan pertama: ";
    cin >> num1;
    cout << "Masukkan bilangan kedua: ";
    cin >> num2;

    float penjumlahan = num1 + num2;
    float pengurangan = num1 - num2;
    float perkalian = num1 * num2;
    float pembagian = num1 / num2;

    cout << "Hasil penjumlahan: " << penjumlahan << endl;
    cout << "Hasil pengurangan: " << pengurangan << endl;
    cout << "Hasil perkalian: " << perkalian << endl;
    cout << "Hasil pembagian: " << pembagian << endl;

    return 0;
}