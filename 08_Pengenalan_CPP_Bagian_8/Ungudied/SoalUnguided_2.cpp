#include <iostream>
using namespace std;

// Definisikan struktur Node untuk linked list
struct Node {
    string nama;  // Nama mahasiswa
    string nim;   // NIM mahasiswa
    Node* next;   // Pointer ke node berikutnya dalam list
};

// Definisikan kelas Queue untuk mengelola antrian berbasis linked list
class Queue {
private:
    Node* front;   // Pointer ke depan antrian
    Node* back;    // Pointer ke belakang antrian

public:
    // Konstruktor, inisialisasi queue dengan front dan back null
    Queue() : front(nullptr), back(nullptr) {}

    // Cek apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Menambahkan elemen ke dalam antrian (enqueue)
    void enqueue(const string& nama, const string& nim) {
        Node* newNode = new Node{nama, nim, nullptr};  // Buat node baru

        if (isEmpty()) {
            front = back = newNode;  // Jika kosong, front dan back menunjuk ke node baru
        } else {
            back->next = newNode;  // Sambungkan node baru di belakang antrian
            back = newNode;        // Update pointer back ke node baru
        }
    }

    // Menghapus elemen dari antrian (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
            return;
        }

        Node* temp = front;  // Simpan node depan sementara
        front = front->next; // Pindahkan front ke node berikutnya
        if (front == nullptr) {
            back = nullptr;  // Jika antrian kosong, back juga null
        }
        delete temp;  // Hapus node lama (node yang terdepan)
    }

    // Menghitung jumlah elemen dalam antrian
    int count() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Menghapus semua elemen dalam antrian
    void clear() {
        while (!isEmpty()) {
            dequeue();  // Dequeue hingga antrian kosong
        }
    }

    // Menampilkan elemen-elemen dalam antrian
    void view() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
            return;
        }

        cout << "Data Antrian Mahasiswa:" << endl;
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            position++;
        }
    }
};

int main() {
    Queue q;  // Membuat objek Queue
    int pilihan;
    string nama, nim;

    do {
        cout << "\nMenu Antrian Mahasiswa:" << endl;
        cout << "1. Tambah Mahasiswa ke Antrian (Enqueue)" << endl;
        cout << "2. Hapus Mahasiswa dari Antrian (Dequeue)" << endl;
        cout << "3. Lihat Daftar Antrian Mahasiswa" << endl;
        cout << "4. Hapus Semua Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Mengabaikan newline tersisa dari input sebelumnya
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                getline(cin, nim);
                q.enqueue(nama, nim);
                cout << "Mahasiswa berhasil ditambahkan ke antrian." << endl;
                break;

            case 2:
                q.dequeue();
                cout << "Mahasiswa di depan antrian telah dihapus." << endl;
                break;

            case 3:
                q.view();
                cout << "Jumlah Antrian = " << q.count() << endl;
                break;

            case 4:
                q.clear();
                cout << "Semua antrian telah dihapus." << endl;
                break;

            case 5:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
