#include "stack.h"

// Membuat stack baru dengan Top = 0
void createStack(Stack &S) {
    S.Top = 0;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return (S.Top == 0);
}

// Mengecek apakah stack penuh
bool isFull(Stack S) {
    return (S.Top == 15);
}

// Menambahkan elemen ke dalam stack
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

// Mengeluarkan elemen dari stack
infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.Top];
        S.Top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return '\0';  // Mengembalikan karakter kosong jika stack kosong
    }
}

// Menampilkan semua elemen di stack dari bawah ke atas dan melakukan pop sesuai jumlah tertentu
void printInfo(Stack S, int num_to_pop) {
    // Cetak isi stack awal
    cout << "Isi stack awal: ";
    for (int i = 1; i <= S.Top; i++) {
        cout << S.info[i] << " ";
    }
    cout << endl;

    // Pop sejumlah elemen sesuai permintaan dan tampilkan sisanya
    cout << "Isi stack setelah pop: ";
    for (int i = 0; i < num_to_pop; i++) {
        pop(S);
    }
    for (int i = 1; i <= S.Top; i++) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}