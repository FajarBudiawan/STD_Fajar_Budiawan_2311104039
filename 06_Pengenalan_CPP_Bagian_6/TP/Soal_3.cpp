#include <iostream>
using namespace std;

// Node class untuk Doubly Linked List
class Node {
public:
    int data; // Data yang disimpan dalam node
    Node* prev; // Pointer ke node sebelumnya
    Node* next; // Pointer ke node berikutnya

    // Constructor untuk menginisialisasi node
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Pointer ke node pertama

public:
    // Constructor untuk menginisialisasi list
    DoublyLinkedList() {
        head = nullptr; // List dimulai dengan head yang kosong
    }

    // Fungsi untuk menambahkan elemen di akhir list
    void insertLast(int data) {
        Node* newNode = new Node(data); // Buat node baru
        if (head == nullptr) { // Jika list kosong
            head = newNode; // Node baru menjadi head
        } else {
            Node* current = head; // Mulai dari head
            while (current->next != nullptr) { // Cari node terakhir
                current = current->next;
            }
            current->next = newNode; // Hubungkan node terakhir dengan node baru
            newNode->prev = current; // Set prev dari node baru
        }
    }

    // Fungsi untuk menampilkan elemen dari depan ke belakang
    void displayForward() {
        Node* current = head; // Mulai dari head
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current != nullptr) { // Selama current tidak null
            cout << current->data; // Tampilkan data
            if (current->next != nullptr) {
                cout << " <-> "; // Tampilkan panah jika ada node berikutnya
            }
            current = current->next; // Pindah ke node berikutnya
        }
        cout << endl;
    }

    // Fungsi untuk menampilkan elemen dari belakang ke depan
    void displayBackward() {
        if (head == nullptr) { // Jika list kosong
            cout << "List kosong." << endl;
            return;
        }

        Node* current = head; // Mulai dari head
        // Mencari node terakhir
        while (current->next != nullptr) {
            current = current->next;
        }

        cout << "Daftar elemen dari belakang ke depan: ";
        while (current != nullptr) { // Selama current tidak null
            cout << current->data; // Tampilkan data
            if (current->prev != nullptr) {
                cout << " <-> "; // Tampilkan panah jika ada node sebelumnya
            }
            current = current->prev; // Pindah ke node sebelumnya
        }
        cout << endl;
    }
};

// Fungsi utama
int main() {
    DoublyLinkedList dll; // Buat objek dari DoublyLinkedList

    // Input 4 elemen
    for (int i = 0; i < 4; i++) {
        int element;
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        cin >> element; // Ambil input dari pengguna
        dll.insertLast(element); // Tambahkan elemen ke list
    }

    // Tampilkan elemen dari depan ke belakang
    dll.displayForward();

    // Tampilkan elemen dari belakang ke depan
    dll.displayBackward();

    return 0;
}