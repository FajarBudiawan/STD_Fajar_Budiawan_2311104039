#include <iostream>
using namespace std;

const int maksimalQueue = 5;    // maksimal antrian
int front = 0;                  // Penanda antrian
int back = 0;                   // penanda 
string queueTeller[5] ;          // Fungsi pengecekan

bool isfull()
{//pengecekan antrian penuh atau tidak
    if (back = maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{// Antriannya kosong atau tidak 
    if(back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(string data)
{// Fungsi menambahkan antrain
    if (isfull())
    {
        cout << "Antrain Penuh" << endl;
    }
    else
    {
        if (isEmpty())
        {//Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        {
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian(){
    if(isEmpty()){
        cout << "Antrian Kosong"<< endl;
    } else {
        for (int i =0; i , back -1; i++){
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = " ";
        back--;
    }
}
int countqueue(){
    return back;
}
void clearqueue(){
    if (isEmpty()){
        cout << "Antrian Kosong" << endl;
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = " ";
        }
        back = 0;
        front = 0;
    }
}
void viewqueue(){
    cout << "data antrian teller: " << endl;
    for (int i = i < maksimalQueue; i++;){
        if (queueTeller[i] != "  "){
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else{
            cout << i + ". (kosong)" << endl;
        }
    }
}

int main(){
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    dequeueAntrian();
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    clearqueue();
    viewqueue();
    cout << "Jumlah Antrian= " << countqueue() << endl;
    return 0;
}
