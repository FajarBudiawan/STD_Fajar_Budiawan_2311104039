#include <iostream>

using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;

    
    Pohon(char data, Pohon* left = NULL, Pohon* right = NULL, Pohon* parent = NULL) 
        : data(data), left(left), right(right), parent(parent) {}
};

Pohon *root = NULL, *baru = NULL;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu." << endl;
        return NULL;
    }

    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }

    baru = new Pohon(data, NULL, NULL, node);
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu." << endl;
        return NULL;
    }

    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }

    baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu." << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }

    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu." << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData node " << node->data << endl;
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu." << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: ";
    if (node->parent) {
        cout << node->parent->data << endl;
    } else {
        cout << "(tidak punya parent)" << endl;
    }

    if (node->parent) {
        if (node->parent->left == node && node->parent->right) {
            cout << "Sibling: " << node->parent->right->data << endl;
        } else if (node->parent->right == node && node->parent->left) {
            cout << "Sibling: " << node->parent->left->data << endl;
        } else {
            cout << "Sibling: (tidak ada sibling)" << endl;
        }
    }
}

int main() {
    init();
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeB);
    insertLeft('F', nodeC);
    insertRight('G', nodeC);

    cout << "\n=== Pemanggilan Retrieve ===" << endl;
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout << "\n=== Pemanggilan Find (Node B) ===" << endl;
    find(nodeB);

    cout << "\n=== Pemanggilan Find (Node C) ===" << endl;
    find(nodeC);
    
    cout << "\n=== Pemanggilan Update (Mengubah Node B menjadi 2) ===" << endl;
    update('2', nodeB);

    cout << "\n=== Pemanggilan Retrieve setelah Update ===" << endl;
    retrieve(nodeB);

    return 0;
}