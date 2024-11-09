#include <iostream>
#include <string>
using namespace std;

// Struktur untuk merepresentasikan mahasiswa dengan Nama dan NIM
struct Mahasiswa {
    string nama;
    int NIM;
    Mahasiswa* berikut;
};

// Kelas Antrian untuk mengelola queue berbasis linked list
class Antrian {
private:
    Mahasiswa* depan;  // Pointer ke depan antrian
    Mahasiswa* belakang;   // Pointer ke belakang antrian

public:
    Antrian() : depan(nullptr), belakang(nullptr) {} // Konstruktor

    // Mengecek apakah antrian kosong
    bool isEmpty() {
        return depan == nullptr;
    }

    // Fungsi enqueue dengan prioritas berdasarkan NIM (NIM lebih kecil mendapat prioritas lebih tinggi)
    void enqueue(string nama, int NIM) {
        Mahasiswa* mahasiswaBaru = new Mahasiswa{nama, NIM, nullptr};

        // Jika antrian kosong, tambahkan elemen pertama
        if (isEmpty()) {
            depan = belakang = mahasiswaBaru;
        } else {
            // Menyisipkan berdasarkan prioritas (NIM urutan naik)
            if (mahasiswaBaru->NIM < depan->NIM) {
                // Sisipkan di awal jika NIM paling kecil
                mahasiswaBaru->berikut = depan;
                depan = mahasiswaBaru;
            } else {
                // Cari posisi yang tepat
                Mahasiswa* saatIni = depan;
                while (saatIni->berikut != nullptr && saatIni->berikut->NIM <= mahasiswaBaru->NIM) {
                    saatIni = saatIni->berikut;
                }
                // Sisipkan mahasiswa baru di posisi yang tepat
                mahasiswaBaru->berikut = saatIni->berikut;
                saatIni->berikut = mahasiswaBaru;
                if (mahasiswaBaru->berikut == nullptr) {
                    belakang = mahasiswaBaru;
                }
            }
        }
    }

    // Fungsi dequeue untuk menghapus mahasiswa di depan
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak ada mahasiswa untuk dihapus." << endl;
            return;
        }

        Mahasiswa* temp = depan;
        depan = depan->berikut;
        if (depan == nullptr) {
            belakang = nullptr;
        }
        cout << "Dihapus dari antrian: " << temp->nama << " dengan NIM " << temp->NIM << endl;
        delete temp;
    }

    // Menampilkan semua mahasiswa di antrian
    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Mahasiswa dalam antrian:" << endl;
        Mahasiswa* saatIni = depan;
        int posisi = 1;
        while (saatIni != nullptr) {
            cout << posisi << ". Nama: " << saatIni->nama << ", NIM: " << saatIni->NIM << endl;
            saatIni = saatIni->berikut;
            posisi++;
        }
    }

    // Mengosongkan antrian
    void kosongkanAntrian() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Menghitung jumlah mahasiswa dalam antrian
    int hitungAntrian() {
        int hitung = 0;
        Mahasiswa* saatIni = depan;
        while (saatIni != nullptr) {
            hitung++;
            saatIni = saatIni->berikut;
        }
        return hitung;
    }
};

int main() {
    Antrian antrianMahasiswa;

    int pilihan;
    do {
        cout << "\nMenu Antrian\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Hapus Mahasiswa dari Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Kosongkan Antrian\n";
        cout << "5. Hitung Mahasiswa dalam Antrian\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            int NIM;
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> NIM;
            antrianMahasiswa.enqueue(nama, NIM);
        } else if (pilihan == 2) {
            antrianMahasiswa.dequeue();
        } else if (pilihan == 3) {
            antrianMahasiswa.tampilkanAntrian();
        } else if (pilihan == 4) {
            antrianMahasiswa.kosongkanAntrian();
            cout << "Antrian dikosongkan." << endl;
        } else if (pilihan == 5) {
            cout << "Jumlah mahasiswa dalam antrian: " << antrianMahasiswa.hitungAntrian() << endl;
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (pilihan != 0);

    cout << "Keluar dari program." << endl;
    return 0;
}
