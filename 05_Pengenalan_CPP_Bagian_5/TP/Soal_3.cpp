#include <iostream>
using namespace std;

// Struktur node untuk menyimpan data integer
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen secara terurut dalam linked list
void insertSorted(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Jika list kosong atau nilai elemen baru lebih kecil dari head, masukkan di awal
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        // Menelusuri list untuk menemukan posisi yang tepat
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        // Menyisipkan elemen baru di antara current dan current->next
        newNode->next = current->next;
        current->next = newNode;
    }
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

    cout << "Masukkan 4 elemen integer secara terurut ke dalam list:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> value;
        insertSorted(head, value);
    }

    cout << "\nList setelah memasukkan 4 elemen: ";
    tampilkanList(head);

    // Memasukkan elemen tambahan secara terurut
    cout << "\nMasukkan elemen tambahan yang ingin ditambahkan secara terurut: ";
    cin >> value;
    insertSorted(head, value);

    cout << "List setelah memasukkan elemen tambahan: ";
    tampilkanList(head);

    return 0;
}
