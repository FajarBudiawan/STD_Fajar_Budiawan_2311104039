#include <iostream>
using namespace std;

// definisi pointer ke elemen
struct Elemen
{
    int data;
    Elemen *next;
};

// definisi tipe data untuk list
struct List
{
    Elemen *first;
};

// buat list kosong
void createList(List &L)
{
    L.first = NULL;
}

// fungsi alokasi elemen baru
Elemen *alokasi(int x)
{
    Elemen *p = new Elemen;
    if (p != NULL)
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

// tambah elemen didepan
void insertFirst(List &L, Elemen *P)
{
    P->next = L.first;
    L.first = P;
}

// cetak semua elemen
void printInfo(List L)
{
    Elemen *p = L.first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// cari elemen x
Elemen *findElm(List L, int x)
{
    Elemen *p = L.first;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// fungsi hitung total nilai semua elemen
int hitungTotal(List L)
{
    Elemen *p = L.first;
    int total = 0;
    while (p != NULL)
    {
        total += p->data;
        p = p->next;
    }
    return total;
}