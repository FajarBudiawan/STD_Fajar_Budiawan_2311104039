#include <iostream>

using namespace std;

int main()
{
    int a, b, bilangan;
    cout << "Masukkan batas bawah: ";
    cin >> a;
    cout << "masukkan batas atas: ";
    cin >> b;
    for (bilangan = a; bilangan <= b; bilangan++) {
        cout << "bilangan " << bilangan << endl;
    }
    return 0;
}