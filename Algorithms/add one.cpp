#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> A;
    A.push_back(2);
    A.push_back(5);
    A.push_back(6);
    A.push_back(8);
    A.push_back(6);
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    A.push_back(5);
    int n = A.size()-1;
    int carry = 1;
    for (int i = n; i >= 0; i--) {
        if(carry > 0) {
            int result = A[i] + carry;
            cout << carry << "\ncarry";
            A[i] = result % 10;
            carry = result / 10;
        }
    }
    for (int i = 0; i <n; i++) {
            cout << A[i] << ",";
    }
}
