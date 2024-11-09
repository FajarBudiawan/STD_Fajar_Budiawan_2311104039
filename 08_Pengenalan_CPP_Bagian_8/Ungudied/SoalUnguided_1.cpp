#include <iostream>
using namespace std;

// Definisikan struktur Node untuk linked list
struct Node {
    string data;    // Data untuk disimpan (bisa tipe lain, di sini string)
    Node* next;     // Pointer ke node berikutnya dalam list
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
    void enqueue(const string& data) {
        Node* newNode = new Node{data, nullptr};  // Buat node baru

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

        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". " << current->data << endl;
            current = current->next;
            position++;
        }
    }
};

int main() {
    Queue q;  // Membuat objek Queue

    // Menambahkan elemen ke antrian
    q.enqueue("Andi");
    q.enqueue("Maya");
    q.view();  // Menampilkan antrian
    cout << "Jumlah Antrian = " << q.count() << endl;

    // Menghapus elemen dari antrian
    q.dequeue();
    q.view();  // Menampilkan antrian setelah dequeue
    cout << "Jumlah Antrian = " << q.count() << endl;

    // Menghapus semua elemen dalam antrian
    q.clear();
    q.view();  // Menampilkan antrian setelah clear
    cout << "Jumlah Antrian = " << q.count() << endl;

    return 0;
}
