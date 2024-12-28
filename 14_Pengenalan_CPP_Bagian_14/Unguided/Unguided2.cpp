#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numVertices, numEdges;

    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > numVertices || v < 1 || v > numVertices) {
            cout << "Error: Simpul harus berada di antara 1 dan " << numVertices << ". Coba lagi..." << endl;
            i--;
            continue;
        }

        u--; 
        v--;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}