#include <iostream>
#include "pelajaran.cpp"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";
    
    Pelajaran pelajaran = create_pelajaran(namaMapel, kodeMapel);
    
    tampil_pelajaran(pelajaran);

    return 0;
}