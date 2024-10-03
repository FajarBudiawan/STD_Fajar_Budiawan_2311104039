#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int maks3(int a, int b, int c);

int main() {
    system("cls");
    
    int x, y, z;

    cout << "Masukkan nilai bilangan ke-1 = ";
    cin >> x;

    cout << "Masukkan nilai bilangan ke-2 = ";
    cin >> y;

    cout << "Masukkan nilai bilangan ke-3 = ";
    cin >> z;

    cout << endl << "Nilai maksimumnya adalah = " << maks3(x, y, z);

    // getch();

    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    
    if (b > temp_max) {
        temp_max = b;
    }
    
    if (c > temp_max) {
        temp_max = c;
    }

    return (temp_max);
}