#include <iostream>
#include <string>
using namespace std;

string convertToWords(int n) {
    string ones[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string tens[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n < 20) {
        return ones[n];
    } else if (n < 100) {
        return tens[n / 10] + (n % 10 != 0 ? " " + ones[n % 10] : "");
    } else if (n == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int number;
    cout << "Masukkan angka (0-100): ";
    cin >> number;

    if (number < 0 || number > 100) {
        cout << "Angka harus antara 0 dan 100." << endl;
    } else {
        cout << number << ":" + convertToWords(number)  << endl;
    }

    return 0;
}