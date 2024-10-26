#include "singlelist.h"


void createList(List &L) {
    L.First = NULL;
}


address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}


void dealokasi(address &P) {
    delete P;
    P = NULL;
}


void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}


void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}


address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
 