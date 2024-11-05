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

    // Fungsi untuk menambahkan elemen di awal list
    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // Jika list kosong
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
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
    dll.insertFirst(firstElement);

    // Input elemen kedua di awal
    int secondElement;
    cout << "Masukkan elemen kedua di awal = ";
    cin >> secondElement;
    dll.insertFirst(secondElement);

    // Input elemen ketiga di akhir
    int thirdElement;
    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> thirdElement;
    dll.insertLast(thirdElement);

    // Tampilkan seluruh elemen dalam list
    dll.display();

    return 0;
}