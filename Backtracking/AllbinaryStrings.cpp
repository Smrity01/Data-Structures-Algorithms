/*
Print all possible Binary string of length 'n'
Written By  : Smrity Chaudhary
Dated       : 18/01/19
*/
#include<iostream>
using namespace std;

void binary(int*,int,int);
void binary_strings();
int main() {
    binary_strings();
}
void binary_strings() {
    int n;
    cout << "Enter Length of binary string('n'): ";
    cin >> n;
    int bstring[n];
    binary(bstring,n,n);
}
void binary(int* bstring,int n,int len) {
    if (n < 1) {
        for (int i = 0; i < len ; i++) {
            cout << bstring[i];
        }
        cout << "\n";
    }
    else {
            // For every bit put both possible value 0 or 1
        bstring[n-1] = 0;
        binary(bstring,n-1,len);
        bstring[n-1] = 1;
        binary(bstring,n-1,len);
    }

}
