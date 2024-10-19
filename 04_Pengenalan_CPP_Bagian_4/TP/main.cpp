#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;

int main() {
    List L;
    createList(L);

    int data;
    cout << "Masukkan angka pertama yang ingin diinput ke List: ";
    cin >> data;
    address P = allocate(data);
    insertFirst(L, P);
    cout << "Isi list setelah input pertama: ";
    printInfo(L);

    cout << "Masukkan angka kedua yang ingin diinput ke List: ";
    cin >> data;
    P = allocate(data);
    insertFirst(L, P);
    cout << "Isi list setelah input kedua: ";
    printInfo(L);

    cout << "Masukkan angka ketiga yang ingin diinput ke List: ";
    cin >> data;
    P = allocate(data);
    insertFirst(L, P);
    cout << "Isi list setelah input ketiga: ";
    printInfo(L);

    return 0;
}