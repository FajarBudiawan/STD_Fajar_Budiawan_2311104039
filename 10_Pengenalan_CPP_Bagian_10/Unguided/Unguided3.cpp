#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;


void init() {
    root = NULL;
}


bool isEmpty() {
    return root == NULL;
}


void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}


Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }

    Pohon *baru = new Pohon;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    baru->parent = node;
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}


Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }

    Pohon *baru = new Pohon;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    baru->parent = node;
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}


void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        return;
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}


void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}


void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        return;
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    
    if (node->parent) {
        cout << "Parent: " << node->parent->data << endl;
    } else {
        cout << "Parent: (tidak punya parent)" << endl;
    }

    if (node->parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

int cari_simpul_daun(Pohon *node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
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

    cout << "\n== Pemanggilan Retrieve";
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout << "\n== Pemanggilan Find (Node B)";
    find(nodeB);

    cout << "\n== Pemanggilan Find (Node C)";
    find(nodeC);

    cout << "\n== Pemanggilan Update (Mengubah Node B menjadi Z)";
    update('Z', nodeB);

    cout << "\n== Pemanggilan Retrieve setelah Update";
    retrieve(nodeB);

\
    int jumlahSimpulDaun = cari_simpul_daun(root);
    cout << "\nJumlah simpul daun dalam pohon: " << jumlahSimpulDaun << endl;

    return 0;
}