#include <iostream>

using namespace std;

void tampil_array(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukar_array(int arr1[3][3], int arr2[3][3], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukar_pointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int array2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    
    cout << "Array 1 sebelum ditukar: " << endl;
    tampil_array(array1);
    
    cout << "Array 2 sebelum ditukar: " << endl;
    tampil_array(array2);
    
    tukar_array(array1, array2, 0, 0);
    
    cout << "Array 1 setelah ditukar: " << endl;
    tampil_array(array1);
    
    cout << "Array 2 setelah ditukar: " << endl;
    tampil_array(array2);
    
    cout << "Nilai sebelum pointer ditukar pada posisi [0][0]: " << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;
    
    tukar_pointer(ptr1, ptr2);
    
    cout << "Nilai setelah pointer ditukar pada posisi [0][0]: " << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;
    
    return 0;
}