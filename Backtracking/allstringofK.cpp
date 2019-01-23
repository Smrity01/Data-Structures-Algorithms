/*
All string of length N drawn from 0...K-1
Written By : Smrity Chaudhary
Dated : 21/01/19
*/
#include<iostream>
using namespace std;

void testFunction();
int getLength();
int getNumber();
void allPossibleString(int*, int, int, int);
int main() {
    testFunction();
    return 0;
}
void testFunction() {
    int arrlen = getLength();
    int basenumber = getNumber();
    int kstring[arrlen];
    allPossibleString(kstring,arrlen,arrlen,basenumber);
}
int getLength() {
    int wholenumber;
    cout << "Enter the length of the string:  ";
    cin >> wholenumber;
    return wholenumber;
}
int getNumber() {
    int wholenumber;
    cout << "Enter the base(k) of your string[0...k]: ";
    cin >> wholenumber;
    return wholenumber;
}
void allPossibleString(int *kstring, int arrlen, int stringlen, int basenumber) {
    /*
    Approach: Putting every possible number at each bit position.
    */
    if (stringlen < 1) {
        for (int itr = 0; itr < arrlen; itr++ ) {
            cout << kstring[itr];
        }
        cout << "\n";
    }
    else {
        for (int itr = 0; itr < basenumber; itr++) {
            kstring[stringlen-1] = itr;
            allPossibleString(kstring,arrlen,stringlen-1,basenumber);
        }
    }
}
