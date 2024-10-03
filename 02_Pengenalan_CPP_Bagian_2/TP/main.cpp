#include <iostream>
using namespace std;

// Deklarasi struct untuk elemen list
struct Elemen {
    string namaPerawat;
    int idPerawat;
    string jadwalPiket;
    Elemen* next;
};

// Deklarasi struct untuk list
struct List {
    Elemen* first;
    Elemen* last;
};

// Fungsi untuk membuat list baru
void createList(List& list) {
    list.first = NULL;
    list.last = NULL;
}

// Fungsi untuk membuat elemen baru
void createElement(Elemen*& elemen, string namaPerawat, int idPerawat, string jadwalPiket) {
    elemen = new Elemen;
    elemen->namaPerawat = namaPerawat;
    elemen->idPerawat = idPerawat;
    elemen->jadwalPiket = jadwalPiket;
    elemen->next = NULL;
}

// Fungsi untuk insert first
void insertFirst(List& list, Elemen* elemen) {
    if (list.first == NULL) {
        list.first = elemen;
        list.last = elemen;
    } else {
        elemen->next = list.first;
        list.first = elemen;
    }
}

// Fungsi untuk insert last
void insertLast(List& list, Elemen* elemen) {
    if (list.last == NULL) {
        list.first = elemen;
        list.last = elemen;
    } else {
        list.last->next = elemen;
        list.last = elemen;
    }
}

// Fungsi untuk delete first
void deleteFirst(List& list) {
    if (list.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        Elemen* temp = list.first;
        list.first = list.first->next;
        delete temp;
        if (list.first == NULL) {
            list.last = NULL;
        }
    }
}

// Fungsi untuk delete last
void deleteLast(List& list) {
    if (list.last == NULL) {
        cout << "List kosong" << endl;
    } else if (list.first == list.last) {
        delete list.first;
        list.first = NULL;
        list.last = NULL;
    } else {
        Elemen* temp = list.first;
        while (temp->next != list.last) {
            temp = temp->next;
        }
        delete list.last;
        list.last = temp;
        list.last->next = NULL;
    }
}

// Fungsi untuk menampilkan data
void show(List list) {
    Elemen* temp = list.first;
    while (temp != NULL) {
        cout << "Nama Perawat: " << temp->namaPerawat << ", ID Perawat: " << temp->idPerawat << ", Jadwal Piket: " << temp->jadwalPiket << endl;
        temp = temp->next;
    }
}

int main() {
    // Deklarasi variable List
    List listPerawat;

    // Membuat list
    createList(listPerawat);

    // Meminta user data pertama yang akan dimasukkan ke list
    string namaPerawat1;
    int idPerawat1;
    string jadwalPiket1;
    cout << "Masukkan nama perawat pertama: ";
    cin >> namaPerawat1;
    cout << "Masukkan ID perawat pertama: ";
    cin >> idPerawat1;
    cout << "Masukkan jadwal piket pertama: ";
    cin >> jadwalPiket1;

    // Membuat elemen baru
    Elemen* elemen1;
    createElement(elemen1, namaPerawat1, idPerawat1, jadwalPiket1);

    // Memanggil insert first
    insertFirst(listPerawat, elemen1);

    // Meminta user data kedua yang akan dimasukkan ke list
    string namaPerawat2;
    int idPerawat2;
    string jadwalPiket2;
    cout << "Masukkan nama perawat kedua: ";
    cin >> namaPerawat2;
    cout << "Masukkan ID perawat kedua: ";
    cin >> idPerawat2;
    cout << "Masukkan jadwal piket kedua: ";
    cin >> jadwalPiket2;
}
    // Membuat elemen baru