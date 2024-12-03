#include <iostream>
#include <queue>

using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;

    Pohon(char data, Pohon *left = NULL, Pohon *right = NULL, Pohon *parent = NULL)
        : data(data), left(left), right(right), parent(parent) {}
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

    Pohon *baru = new Pohon(data, NULL, NULL, node);
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

    Pohon *baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void tampilChild(Pohon *node) {
    if (!node) {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }

    cout << "\nChild dari node " << node->data << ": ";
    if (node->left) cout << "Left: " << node->left->data << " ";
    if (node->right) cout << "Right: " << node->right->data;
    if (!node->left && !node->right) cout << "(tidak ada)";
    cout << endl;
}

void tampilDescendants(Pohon *node) {
    if (!node) {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }

    cout << "\nDescendants dari node " << node->data << ": ";
    queue<Pohon *> q;
    q.push(node);

    while (!q.empty()) {
        Pohon *current = q.front();
        q.pop();

        if (current->left) {
            cout << current->left->data << " ";
            q.push(current->left);
        }
        if (current->right) {
            cout << current->right->data << " ";
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    int pilihan;
    char data, parentData;
    Pohon *parentNode = NULL;
    queue<Pohon *> q;

    do {
        cout << "\n=== Menu Pohon Biner ===";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Tambah Child Kiri";
        cout << "\n3. Tambah Child Kanan";
        cout << "\n4. Tampilkan Child";
        cout << "\n5. Tampilkan Descendants";
        cout << "\n0. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (root) {
                    cout << "\nRoot sudah dibuat!" << endl;
                } else {
                    cout << "Masukkan data root: ";
                    cin >> data;
                    buatNode(data);
                }
                break;

            case 2:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = root;
                q = queue<Pohon *>(); 
                q.push(root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == parentData) {
                        parentNode = current;
                        break;
                    }
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
                cout << "Masukkan data node: ";
                cin >> data;
                insertLeft(data, parentNode);
                break;

            case 3:
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = root;
                q = queue<Pohon *>(); 
                q.push(root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == parentData) {
                        parentNode = current;
                        break;
                    }
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
                cout << "Masukkan data node: ";
                cin >> data;
                insertRight(data, parentNode);
                break;

            case 4:
                cout << "Masukkan data node: ";
                cin >> data;
                parentNode = root;
                q = queue<Pohon *>(); 
                q.push(root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        parentNode = current;
                        break;
                    }
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
                tampilChild(parentNode);
                break;

            case 5:
                cout << "Masukkan data node: ";
                cin >> data;
                parentNode = root;
                q = queue<Pohon *>(); 
                q.push(root);
                while (!q.empty()) {
                    Pohon *current = q.front();
                    q.pop();
                    if (current->data == data) {
                        parentNode = current;
                        break;
                    }
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
                tampilDescendants(parentNode);
                break;

            case 0:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

 