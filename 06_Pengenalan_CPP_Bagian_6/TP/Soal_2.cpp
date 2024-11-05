#include <iostream>
using namespace std;

// Node class untuk Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan elemen di akhir list
    void insertLast(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // Jika list kosong
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) { // Mencari node terakhir
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Fungsi untuk menghapus elemen pertama
    void deleteFirst() {
        if (head == nullptr) { // Jika list kosong
            cout << "List kosong, tidak ada elemen yang dihapus." << endl;
            return;
        }
        Node* temp = head;
        head = head->next; // Pindahkan head ke node berikutnya
        if (head != nullptr) {
            head->prev = nullptr; // Set prev dari head baru menjadi nullptr
        }
        delete temp; // Hapus node yang lama
    }

    // Fungsi untuk menghapus elemen terakhir
    void deleteLast() {
        if (head == nullptr) { // Jika list kosong
            cout << "List kosong, tidak ada elemen yang dihapus." << endl;
            return;
        }
        if (head->next == nullptr) { // Jika hanya ada satu elemen
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) { // Mencari node terakhir
            current = current->next;
        }
        current->prev->next = nullptr; // Set next dari node sebelum terakhir menjadi nullptr
        delete current; // Hapus node terakhir
    }

    // Fungsi untuk menampilkan seluruh elemen dalam list
    void display() {
        Node* current = head;
        cout << "DAFTAR ANGGOTA LIST: ";
        while (current != nullptr) { // Menampilkan elemen dari depan ke belakang
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

// Fungsi utama
int main() {
    DoublyLinkedList dll;

    // Input elemen pertama
    int firstElement;
    cout << "Masukkan elemen pertama = ";
    cin >> firstElement;
    dll.insertLast(firstElement);

    // Input elemen kedua di akhir
    int secondElement;
    cout << "Masukkan elemen kedua di akhir = ";
    cin >> secondElement;
    dll.insertLast(secondElement);

    // Input elemen ketiga di akhir
    int thirdElement;
    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> thirdElement;
    dll.insertLast(thirdElement);

    // Tampilkan seluruh elemen dalam list sebelum penghapusan
    cout << "DAFTAR ANGGOTA LIST SEBELUM PENGHAPUSAN: ";
    dll.display();

    // Hapus elemen pertama dan terakhir
    dll.deleteFirst();
    dll.deleteLast();

    // Tampilkan seluruh elemen dalam list setelah penghapusan
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    dll.display();

    return 0;
}