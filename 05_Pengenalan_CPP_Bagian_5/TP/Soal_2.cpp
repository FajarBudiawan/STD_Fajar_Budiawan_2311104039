#include <iostream>
using namespace std;

// Struktur node untuk menyimpan data integer
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke dalam linked list
void tambahElemen(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk mengurutkan linked list menggunakan Bubble Sort
void bubbleSortList(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;  // Menandai bagian akhir list yang sudah diurutkan

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Pertukaran data antar node
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;  // Memperbarui posisi terakhir yang sudah diurutkan
    } while (swapped);
}

// Fungsi untuk menampilkan elemen-elemen dalam linked list
void tampilkanList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int value;

    cout << "Masukkan 5 elemen integer ke dalam list:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> value;
        tambahElemen(head, value);
    }

    cout << "\nList sebelum diurutkan: ";
    tampilkanList(head);

    bubbleSortList(head);

    cout << "List setelah diurutkan: ";
    tampilkanList(head);

    return 0;
}
