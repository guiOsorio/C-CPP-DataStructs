// this program asks the user for a string and outputs its reverse, it uses a stack to do so
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack> // stack from standard template library (STL)
using namespace std;

void Reverse(char C[], int n)
{
    stack<char> S;
    // loop for push
    for(int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    // loop for pop
    for(int i = 0; i < n; i++) {
        C[i] = S.top(); // overwrite the character at index i
        S.pop(); //perform pop
    }
}

int main() {
    char C[51];
    printf("Enter a string: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
}