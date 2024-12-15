#include <iostream>
using namespace std;

/// PROGRAM BINARY TREE

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
bool isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Fungsi untuk Menghapus Node
void deleteNode(Pohon *&node) {
    if (!node) return;

    // Leaf node
    if (!node->left && !node->right) {
        delete node;
        node = NULL;
    }
    // Node dengan satu child
    else if (node->left && !node->right) {
        Pohon *temp = node;
        node = node->left;
        node->parent = temp->parent;
        delete temp;
    } else if (!node->left && node->right) {
        Pohon *temp = node;
        node = node->right;
        node->parent = temp->parent;
        delete temp;
    }
    // Node dengan dua child
    else {
        // Ambil most-left dari right subtree
        Pohon *successor = node->right;
        while (successor->left) {
            successor = successor->left;
        }
        node->data = successor->data;
        deleteNode(successor);
    }
}

// Cari Most-Left Node
Pohon *mostLeft(Pohon *node) {
    if (!node) return NULL;
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Cari Most-Right Node
Pohon *mostRight(Pohon *node) {
    if (!node) return NULL;
    while (node->right) {
        node = node->right;
    }
    return node;
}

// Fungsi main
int main() {
    init();
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeB);
    insertLeft('F', nodeC);
    insertRight('G', nodeC);

    cout << "\n== Most-Left Node ==";
    Pohon *left = mostLeft(root);
    if (left) cout << "\nMost-Left Node: " << left->data << endl;

    cout << "\n== Most-Right Node ==";
    Pohon *right = mostRight(root);
    if (right) cout << "\nMost-Right Node: " << right->data << endl;

    cout << "\n== Hapus Node ==";
    deleteNode(nodeB);  // Contoh menghapus node B
    cout << "Node B telah dihapus." << endl;

    return 0;
}