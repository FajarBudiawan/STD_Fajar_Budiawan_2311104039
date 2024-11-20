#include <iostream>
#include <limits>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

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
        cout << "Node " << data << " berhasil dibuat sebagai root.\n";
    } else {
        cout << "Tree sudah dibuat.\n";
    }
}

// Tambah Kiri
Pohon *InsertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return NULL;
    }
    if (node->left != NULL) {
        cout << "Node " << node->data << " sudah ada child kiri.\n";
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kiri " << node->data << ".\n";
    return baru;
}

// Tambah Kanan
Pohon *InsertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return NULL;
    }
    if (node->right != NULL) {
        cout << "Node " << node->data << " sudah ada child kanan.\n";
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kanan " << node->data << ".\n";
    return baru;
}

// Tampilkan Child
void showChild(Pohon *node) {
    if (!node) {
        cout << "Node tidak ditemukan.\n";
        return;
    }
    cout << "Node " << node->data << ":\n";
    if (node->left)
        cout << "  Child kiri: " << node->left->data << "\n";
    else
        cout << "  Child kiri: NULL\n";
    if (node->right)
        cout << "  Child kanan: " << node->right->data << "\n";
    else
        cout << "  Child kanan: NULL\n";
}

// Tampilkan Descendant
void showDescendants(Pohon *node) {
    if (!node) return;
    cout << node->data << " ";
    showDescendants(node->left);
    showDescendants(node->right);
}

// Validasi BST
bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val)
        return false;
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Cari Simpul Daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Menu Interaktif
void menu() {
    char pilih, data, parent_data;
    Pohon *parent = NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Child Kiri\n";
        cout << "3. Tambah Child Kanan\n";
        cout << "4. Tampilkan Child\n";
        cout << "5. Tampilkan Descendant\n";
        cout << "6. Periksa Validitas BST\n";
        cout << "7. Hitung Jumlah Simpul Daun\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case '1':
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data parent: ";
                cin >> parent_data;
                cout << "Masukkan data child kiri: ";
                cin >> data;
                parent = root; // Untuk simulasi (cari parent jika dibutuhkan)
                InsertLeft(data, parent);
                break;
            case '3':
                cout << "Masukkan data parent: ";
                cin >> parent_data;
                cout << "Masukkan data child kanan: ";
                cin >> data;
                parent = root; // Untuk simulasi (cari parent jika dibutuhkan)
                InsertRight(data, parent);
                break;
            case '4':
                cout << "Masukkan data node: ";
                cin >> parent_data;
                parent = root; // Untuk simulasi (cari parent jika dibutuhkan)
                showChild(parent);
                break;
            case '5':
                cout << "Masukkan data node: ";
                cin >> parent_data;
                parent = root; // Untuk simulasi (cari parent jika dibutuhkan)
                cout << "Descendants: ";
                showDescendants(parent);
                cout << "\n";
                break;
            case '6':
                if (is_valid_bst(root, numeric_limits<char>::min(), numeric_limits<char>::max()))
                    cout << "Tree adalah Binary Search Tree.\n";
                else
                    cout << "Tree BUKAN Binary Search Tree.\n";
                break;
            case '7':
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << "\n";
                break;
            case '8':
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != '8');
}

// Fungsi Utama
int main() {
    init();
    menu();
    return 0;
}