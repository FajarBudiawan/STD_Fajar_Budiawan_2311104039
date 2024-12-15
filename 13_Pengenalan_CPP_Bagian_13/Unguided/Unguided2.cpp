#include <iostream>

using namespace std;

struct InfoBuku {
    string nama;
    string pengembalian;
};

struct Buku {
    InfoBuku info;
    Buku *next;
};

struct InfoAnggota {
    string nama;
    string id;
};

struct Anggota {
    InfoAnggota info;
    Anggota *next;
    Buku *nextBuku;
};

struct List {
    Anggota *first;
};

void createAnggota(InfoAnggota info, Anggota &A) {
    A.info.nama = info.nama;
    A.info.id = info.id;
    A.next = nullptr;
    A.nextBuku = nullptr;
}

void createBuku(InfoBuku info, Buku &buku) {
    buku.info.nama = info.nama;
    buku.info.pengembalian = info.pengembalian;
    buku.next = nullptr;
}

void insertAnggota(List &L, Anggota &A) {
    if (L.first == nullptr) {
        L.first = &A;
    } else {
        Anggota *current = L.first;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = &A;
    }
}

void insertBuku(Anggota &A, Buku &buku) {
    if (A.nextBuku == nullptr) {
        A.nextBuku = &buku;
    } else {
        Buku *current = A.nextBuku;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = &buku;
    }
}

void deleteAnggota(List &L, Anggota &A) {
    if (L.first != nullptr) {
        Anggota *prev = nullptr;
        Anggota *current = L.first;

        while (current != nullptr) {
            if (current == &A) {
                if (prev == nullptr) {
                    L.first = current->next;
                } else {
                    prev->next = current->next;
                }

                return;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

void deleteBukuFirst(Anggota &A) {
    if (A.nextBuku != nullptr) {
        Buku *temp = A.nextBuku;
        A.nextBuku = A.nextBuku->next;
        temp->next = nullptr;
    }
}

void showList(List &L) {
    if (L.first != nullptr) {
        Anggota *currentAnggota = L.first;

        cout << "Daftar Pengembalian Buku:" << endl;

        while (currentAnggota != nullptr) {
            cout << currentAnggota->info.nama << ":" << endl;
            
            if (currentAnggota != nullptr) {
                Buku *currentBuku = currentAnggota->nextBuku;

                while (currentBuku != nullptr) {
                    cout << "- " << currentBuku->info.nama << ": " << currentBuku->info.pengembalian << endl;

                    currentBuku = currentBuku->next;
                }
            }

            currentAnggota = currentAnggota->next;
        }
    }
}

void printSeparator() {
    cout << "-----------------------------------------------------" << endl;
}

int main() {
    List L;
    L.first = nullptr;

    Anggota a1;
    Anggota a2;
    Anggota a3;

    createAnggota({ "Rani", "A001" }, a1);
    createAnggota({ "Dito", "A002" }, a2);
    createAnggota({ "Vina", "A003" }, a3);

    Buku buku1;
    Buku buku2;

    createBuku({ "Pemrograman C++", "01/12/2024" }, buku1);
    createBuku({ "Algoritma Pemrograman", "15/12/2024" }, buku2);

    insertAnggota(L, a1);
    insertAnggota(L, a2);
    insertAnggota(L, a3);

    printSeparator();
    showList(L);
    printSeparator();

    insertBuku(a1, buku1);
    insertBuku(a2, buku2);

    showList(L);
    printSeparator();

    Buku buku3;
    createBuku({ "Struktur Data", "10/12/2024" }, buku3);
    insertBuku(a1, buku3);

    showList(L);
    printSeparator();

    deleteAnggota(L, a2);

    showList(L);
    printSeparator();

    return 0;
}