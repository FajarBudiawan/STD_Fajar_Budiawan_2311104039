#include "pelajaran.h"

Pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    Pelajaran pelajaran;

    pelajaran.namaMapel = namaMapel;
    pelajaran.kodeMapel = kodeMapel;

    return pelajaran;
}

void tampil_pelajaran(Pelajaran pelajaran) {
    cout << "Nama Pelajaran : " << pelajaran.namaMapel << endl;
    cout << "Kode Pelajaran : " << pelajaran.kodeMapel << endl;
}