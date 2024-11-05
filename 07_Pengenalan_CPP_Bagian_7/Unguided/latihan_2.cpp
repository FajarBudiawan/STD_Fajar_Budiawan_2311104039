#include <iostream>
#include <stack>
#include <sstream> // Untuk std::istringstream
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat
string reverseSentence(const string& sentence) {
    stack<string> words; // Stack untuk menyimpan kata-kata
    string word;
    istringstream iss(sentence); // Menggunakan istringstream untuk memisahkan kata

    // Memisahkan kalimat menjadi kata-kata dan menyimpannya ke dalam stack
    while (iss >> word) {
        words.push(word);
    }

    // Membalikkan urutan kata-kata
    string reversedSentence;
    while (!words.empty()) {
        reversedSentence += words.top() + " "; // Mengambil kata teratas dari stack
        words.pop(); // Menghapus kata teratas dari stack
    }

    // Menghapus spasi ekstra di akhir
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back(); // Menghapus spasi terakhir
    }

    return reversedSentence; // Mengembalikan kalimat yang telah dibalik
}

// Fungsi utama
int main() {
    string input;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, input); // Mengambil input kalimat dari pengguna

    // Menghitung jumlah kata
    istringstream iss(input);
    int wordCount = 0;
    string word;
    while (iss >> word) {
        wordCount++;
    }

    // Memeriksa apakah jumlah kata minimal 3
    if (wordCount < 3) {
        cout << "Kalimat harus terdiri dari minimal 3 kata." << endl;
        return 1; // Menghentikan program dengan kode kesalahan
    }

    // Membalikkan kalimat dan menampilkan hasil
    string reversed = reverseSentence(input);
    cout << "Kalimat setelah dibalik: " << reversed << endl;

    return 0;
}