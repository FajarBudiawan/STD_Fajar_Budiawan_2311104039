#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3*uts, 0.4*uas, 0.3*tugas);
}

int main(){
    const int MAKS = 10;
    Mahasiswa mahasiswa[MAKS];
    int jumlahMahasiswa;

    cout << "Masukkan Jumlah Mahasiswa : ";
    cin >> jumlahMahasiswa;

    if(jumlahMahasiswa > MAKS)
    {
        cout << "Jumlah Maksimal 10" << endl;
        return 1;
    }

    for(int i = 0; i < jumlahMahasiswa; i++) {
        cout <<"\n Masukan Mahasiswa ke " << i+1 << endl;
        cout <<"Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    cout << "\nHasil Akhir Nilai Mahasiwa\n";
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Mahasiswa Ke- " << i+1 << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].nim << endl;
        cout << "Nilai Tugas: " << mahasiswa[i].tugas << endl;
        cout << "Nilai UTS: " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS: " << mahasiswa[i].uas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}