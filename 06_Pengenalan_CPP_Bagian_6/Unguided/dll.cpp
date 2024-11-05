#include <iostream>
#include <string>

using namespace std;

struct Buku {
    int idBuku;
    string judul;
    string penulis;
    Buku* prev;
    Buku* next;
};

// Fungsi untuk menambahkan buku di akhir linked list
void tambahBuku(Buku*& head, Buku*& tail, int idBuku, string judul, string penulis) {
    Buku* newNode = new Buku;
    newNode->idBuku = idBuku;
    newNode->judul = judul;
    newNode->penulis = penulis;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == nullptr) {
        head = newNode;
    }
}

// Fungsi untuk mencetak semua buku dari awal ke akhir
void cetakBukuDariAwal(Buku* head) {
    Buku* current = head;
    while (current != nullptr) {
        cout << "ID Buku: " << current->idBuku << ", Judul: " << current->judul << ", Penulis: " << current->penulis << endl;
        current = current->next;
    }
}

// Fungsi untuk mencetak semua buku dari akhir ke awal
void cetakBukuDariAkhir(Buku* tail) {
    Buku* current = tail;
    while (current != nullptr) {
        cout << "ID Buku: " << current->idBuku << ", Judul: " << current->judul << ", Penulis: " << current->penulis << endl;
        current = current->prev;
    }
}

int main() {
    Buku* head = nullptr;
    Buku* tail = nullptr;

    tambahBuku(head, tail, 101, "Pemrograman C++", "Andi");
    tambahBuku(head, tail, 102, "Struktur Data", "Budi");

    cout << "Daftar Buku dari Awal ke Akhir:" << endl;
    cetakBukuDariAwal(head);

    cout << "\nDaftar Buku dari Akhir ke Awal:" << endl;
    cetakBukuDariAkhir(tail);

    return 0;
}