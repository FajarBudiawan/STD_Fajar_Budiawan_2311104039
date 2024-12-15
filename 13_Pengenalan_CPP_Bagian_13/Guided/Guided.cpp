#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next; //Pointer ke elemen berikutnya
};

struct List {
    address first; //Menyimpan pointer ke elemen head
};

//Membuat list kosong dengan pointer first
void createList(List &L) {
    L.first = nullptr;
}

//Membuat elemen(node) baru pada list
address allocate(infotype data) {
    address P = new ElmList;
    P->info = data;
    P->next = nullptr;
    return P;
}

//Menamabahkan elemen di awal 
void insertFirst(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

//Menamabahkan elemen di akhir
void insertLast(List &L, address P) {
    if (L.first == nullptr){
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

//Menambahkan elemen setelah elemen tertentu
void insertAfter(address prec, address P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

//Menampilkan isi list
void printList(const List &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    //Memebuat data mahasiswa
    infotype m1 = {"Ali", "01", 'L', 3.3};
    infotype m2 = {"Bobi", "02", 'L', 3.71};
    infotype m3 = {"Cindi", "03", 'P', 3.5};
    infotype m4 = {"Danu", "04", 'L', 4.0};
    infotype m5 = {"Eli", "05", 'P', 3.4};
    infotype m6 = {"Fahmi", "06", 'L', 3.45};
    infotype m7 = {"Gita", "07", 'P', 3.75};
    infotype m8 = {"Hilmi", "08", 'L', 3.3};

    // Alokasi elemen
    address p1 = allocate(m1);
    address p2 = allocate(m2);
    address p3 = allocate(m3);
    address p4 = allocate(m4);
    address p5 = allocate(m5);
    address p6 = allocate(m6);
    address p7 = allocate(m7);
    address p8 = allocate(m8);

    // Memasukkan elemen ke list
    insertFirst(L, p1);     //Ali
    insertLast(L, p2);      //Bobi
    insertLast(L, p4);      //Danu
    insertAfter(p2, p3);    //Cindi setelah Bobi
    insertLast(L, p5);      //Eli
    insertLast(L, p6);      //Fahmi
    insertLast(L, p7);      //Gita
    insertLast(L, p8);      //Hilmi

    // Cetak isi list
    cout << "Coba insert first, last, dan after\n" << endl;
    printList(L);

    return 0;
}