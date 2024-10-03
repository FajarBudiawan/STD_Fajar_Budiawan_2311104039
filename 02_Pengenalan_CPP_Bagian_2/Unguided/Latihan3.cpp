#include <iostream>

#define MAX 5

using namespace std;

int main() {
    // Deklarasi variabel
    int num[MAX], max_num, min_num;

    // Input loop 5x
    for (int i = 0; i < MAX; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> num[i];
    }

    // Menampilkan angka yang diinputkan
    cout << "Angka yang Diinputkan : ";
    for (int i = 0; i < MAX; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    cout << "Angka Terbesar : ";
    max_num = num[0];
    for (int i = 0; i < MAX; i++) {
        if (num[i+1] > max_num && i+1 != MAX) {
            max_num = num[i+1];
        }
    }
    cout << max_num << endl;

    cout << "Angka Terkecil : ";
    min_num = num[0];
    for (int i = 0; i < MAX; i++) {
        if (num[i+1] < min_num && i+1 != MAX) {
            min_num = num[i+1];
        }
    }
    cout << min_num << endl;

    return 0;
}