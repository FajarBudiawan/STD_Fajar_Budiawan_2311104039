#include <iostream>
#include <stack>
#include <cctype> // Untuk fungsi isalpha dan tolower
#include <string>

using namespace std;

// Fungsi untuk memeriksa apakah sebuah kalimat adalah palindrom
bool isPalindrome(const string& str) {
    stack<char> s;
    string filteredStr;

    // Menghapus spasi dan tanda baca, serta mengubah huruf menjadi kecil
    for (char ch : str) {
        if (isalpha(ch)) { // Memeriksa apakah karakter adalah huruf
            filteredStr += tolower(ch); // Menambahkan huruf kecil ke filteredStr
            s.push(tolower(ch)); // Menyimpan huruf kecil ke stack
        }
    }

    // Membandingkan karakter dari stack dengan filteredStr
    for (char ch : filteredStr) {
        if (ch != s.top()) { // Jika karakter tidak sama dengan karakter teratas stack
            return false; // Bukan palindrom
        }
        s.pop(); // Menghapus karakter teratas stack
    }

    return true; // Jika semua karakter cocok, maka palindrom
}

// Fungsi untuk memeriksa apakah input valid
bool isValidInput(const string& str) {
    return str == "ini" || str == "telkom"; // Memeriksa apakah input adalah "ini" atau "telkom"
}

// Fungsi utama
int main() {
    string input;

    cout << "Masukkan kalimat: ";
    getline(cin, input); // Mengambil input kalimat dari pengguna

    // Memeriksa apakah input valid
    if (!isValidInput(input)) {
        cout << "Input tidak valid." << endl;
        return 1; // Menghentikan program dengan kode kesalahan
    }

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}