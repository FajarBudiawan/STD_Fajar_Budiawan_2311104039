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

// Fungsi untuk mencari elemen dalam linked list
void searchElement(Node* head, int i) {
    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->data == i) {
            cout << "Elemen " << i << " ditemukan pada alamat " << current << " di posisi ke-" << position << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Elemen " << i << " tidak ada dalam list." << endl;
    }
}

int main() {
    Node* head = nullptr;
    int value;

    cout << "Masukkan 6 elemen integer ke dalam list:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> value;
        tambahElemen(head, value);
    }

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> value;
    searchElement(head, value);

    return 0;
}
