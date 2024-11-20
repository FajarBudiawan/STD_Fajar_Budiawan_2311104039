#include <iostream>
using namespace std;

// BINARY TREE

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat jadi root" << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu." << endl;
        return NULL;
    }

    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu!" << endl;
        return NULL;
    }

    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Update Tree
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu!" << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ingin diganti tidak ada." << endl;
        return;
    }

    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah jadi " << data << endl;
}

// Show alldata
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu." << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada." << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

// Search Data
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu." << endl;
        return;
    }

    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada." << endl;
        return;
    }

    cout << "\nData Node : " << node->data << endl;
    cout << "Root : " << root->data << endl;
    cout << "Parent : " << (node->parent ? node->parent->data : '(Tidak ada parent)') << endl;

    if (node->parent)
    {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling : " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling : " << node->parent->left->data << endl;
        else
            cout << "Sibling : (Tidak ada sibling)" << endl;
    }
}

// Main
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB);
    insertRight('E', nodeB);
    insertLeft('F', nodeC);
    insertRight('G', nodeC);

    cout << "\n== Pemanggilan Retrieve ==";
    retrieve(root);
    retrieve(nodeB);
    retrieve(nodeC);

    cout << "\n== Pemanggilan find nodeB ==";
    find(nodeB);

    cout << "\n== Pemanggilan find nodeC ==";
    find(nodeC);

    cout << "\n== Pemanggilan Retrieve setelah Update ==";
    update('Z', nodeB); // contoh update nodeB menjadi 'Z'
    retrieve(nodeB);

    return 0;
}
