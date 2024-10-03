#include <iostream>

using namespace std;

void tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int bil1, bil2;
    cout << "masukan bilangan pertama: ";
    cin >> bil1;
    cout << "masukakn bilangan kedua: ";
    cin >> bil2;
    cout << "sebelum penukaran:\n";
    cout << "bil 1: " << bil1 << "bil 2" << bil2 << endl;
    tukar(&bil1, &bil2);
    cout << "setelah pertukaran:\n";
    cout << "bil 1: " << bil1 << "bil 2: " << bil2 << endl;
    return 0;
}