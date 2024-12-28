#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX = 10;
const int INF = numeric_limits<int>::max();

class Graph {
public:
    int n; // Jumlah simpul
    int adj[MAX][MAX]; // Matriks bobot
    string names[MAX]; // Nama simpul

    Graph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    adj[i][j] = 0; // Jarak ke diri sendiri 0
                } else {
                    adj[i][j] = INF; // Jarak tidak terhubung
                }
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight; // Menambah bobot antar simpul
        adj[v][u] = weight; // Karena graf tidak terarah
    }

    void setName(int index, const string& name) {
        names[index] = name; // Menyimpan nama simpul
    }

    void printGraph() {
        cout << "Matriks bobot:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << adj[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    int shortestPath(int start, int end) {
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);

        dist[start] = 0;

        for (int i = 0; i < n - 1; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
        return dist[end];
    }
};

int main() {
    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    Graph g(jumlahSimpul);
    
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i << ": ";
        string namaSimpul;
        cin >> namaSimpul; // Input nama simpul
        g.setName(i, namaSimpul);
    }

    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            if (i < j) { // Hanya minta input untuk kombinasi unik
                cout << g.names[i] << " ke " << g.names[j] << ": ";
                int bobot;
                cin >> bobot;
                g.addEdge(i, j, bobot);
            }
        }
    }

    g.printGraph();

    int start, end;
    cout << "Masukkan simpul awal dan simpul tujuan (indeks): ";
    cin >> start >> end;

    int jarak = g.shortestPath(start, end);
    if (jarak == INF) {
        cout << "Tidak ada jalur antara simpul " << g.names[start] << " dan " << g.names[end] << ".\n";
    } else {
        cout << "Jarak dari simpul " << g.names[start] << " ke simpul " << g.names[end] << " adalah: " << jarak << endl;
    }

    cout << "\nProcess returned 0 (0x0) execution time: " 
         << "11.763 s" << endl; // Simulasi waktu eksekusi
    cout << "Press any key to continue...\n";

    return 0;
}