#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambah node di depan linked list
void insertAtFront(Node** head, int nilai) {
    Node* newNode = createNode(nilai);
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menambah node di belakang linked list
void insertAtBack(Node** head, int nilai) {
    Node* newNode = createNode(nilai);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int nilai) {
    while (head != nullptr) {
        if (head->data == nilai) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// Fungsi untuk menghitung panjang linked list
int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk mencetak isi linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Tambah node di depan (nilai: 10)
    insertAtFront(&head, 10);

    // Tambah node di belakang (nilai: 20)
    insertAtBack(&head, 20);

    // Tambah node di depan (nilai: 5)
    insertAtFront(&head, 5);

    // Cari node dengan nilai 20
    if (searchNode(head, 20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }

    // Cetak panjang linked list
    cout << "Panjang linked list: " << countNodes(head) << endl;

    return 0;
}