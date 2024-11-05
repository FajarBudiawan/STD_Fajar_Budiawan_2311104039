#include <iostream>

using namespace std;

#define MAX_SIZE 15 

struct stack {
    char info[MAX_SIZE];
    int top;
};

void createStack(stack &S) {
    S.top = -1;
}

bool isFull(stack S) {
    return S.top == MAX_SIZE - 1;
}

void push(stack &S, char x) {
    if (isFull(S)) {
        cout << "Stack overflow" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

bool isEmpty(stack S) {
    return S.top == -1;
}

void pop(stack &S) {
    if (!isEmpty(S)) {
        S.top--;
    }
}

void printStack(stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        for (int i = 0; i <= S.top; i++) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void popMultiple(stack &S, int count) {
    for (int i = 0; i < count; i++) {
        if (!isEmpty(S)) {
            pop(S);
        }
    }
}

int main() {
    stack S;
    createStack(S);

    string NIM = "12345678";
    int lastDigit = NIM[NIM.length() - 1] - '0';
    
    cout << "Digit terakhir NIM MOD 4 sisa " << lastDigit % 4 << " :" << endl;
    if (lastDigit % 4 == 0) {
        // I F L A B J A Y A
        push(S, 'I');
        push(S, 'F');
        push(S, 'L');
        push(S, 'A');
        push(S, 'B');
        push(S, 'J');
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');
        
        cout << "Output:" << endl;
        printStack(S);

        popMultiple(S, 5);
        printStack(S);

    } else if (lastDigit % 4 == 1) {        
        push(S, 'H');
        push(S, 'A');
        push(S, 'L');
        push(S, 'O');
        push(S, 'B');
        push(S, 'A');
        push(S, 'N');
        push(S, 'D');
        push(S, 'U');
        push(S, 'N');
        push(S, 'G');

        cout << "Output:" << endl;
        printStack(S);
        
        popMultiple(S, 4);
        printStack(S);

    } else if (lastDigit % 4 == 2) {
        push(S, 'P');
        push(S, 'E');
        push(S, 'R');
        push(S, 'C');
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');
        push(S, 'D');
        push(S, 'I');
        push(S, 'R');
        push(S, 'I');
        
        cout << "Output:" << endl;
        printStack(S);

        popMultiple(S, 7);
        printStack(S);

    } else if (lastDigit % 4 == 3) {
        push(S, 'S');
        push(S, 'T');
        push(S, 'R');
        push(S, 'U');
        push(S, 'K');
        push(S, 'T');
        push(S, 'U');
        push(S, 'R');
        push(S, 'D');
        push(S, 'A');
        push(S, 'T');
        push(S, 'A');

        cout << "Output:" << endl;
        printStack(S);
        
        popMultiple(S, 8);
        printStack(S);
    }
    return 0;
}