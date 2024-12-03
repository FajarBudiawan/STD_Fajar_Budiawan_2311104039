#include <iostream>
#include <climits>
using namespace std;


struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root = NULL;


void init() {
    root = NULL;
}


bool isEmpty() {
    return root == NULL;
}


void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
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
    Pohon *baru = new Pohon();
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
    Pohon *baru = new Pohon();
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    baru->parent = node;
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}


bool is_valid_bst(Pohon *node, int min_val, int max_val) {
    if (node == NULL) {
        return true;
    }


    if (node->data <= min_val || node->data >= max_val) {
        return false;
    }

    
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}


int main() {
    init();
    
    
    buatNode('M');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeT = insertRight('T', root);
    insertLeft('A', nodeB);
    insertRight('C', nodeB);
    insertLeft('R', nodeT);
    insertRight('Z', nodeT);

    cout << "\n== Memeriksa apakah tree adalah BST ==";
    if (is_valid_bst(root, INT_MIN, INT_MAX)) {
        cout << "\nTree adalah BST yang valid." << endl;
    } else {
        cout << "\nTree BUKAN BST yang valid." << endl;
    }

  
    cout << "\n== Memodifikasi tree menjadi tidak valid ==";
    nodeB->right->data = 'X';  

    if (is_valid_bst(root, INT_MIN, INT_MAX)) {
        cout << "\nTree adalah BST yang valid." << endl;
    } else {
        cout << "\nTree BUKAN BST yang valid." << endl;
    }

    return 0;
}