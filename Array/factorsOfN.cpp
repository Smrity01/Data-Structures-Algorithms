#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> allFactors(int A);
int main(){
    int A = 24;
    allFactors(A);
}
vector<int> allFactors(int A) {
    vector<int> factors;
    //factors.push_back(1);
    for (int i = 1; i <= sqrt(A); i++){
        if (A % i == 0){
            factors.push_back(i);
            if( A/i != i){
                factors.push_back(A/i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    for (int i = 1; i < factors.size(); i++){
        cout << factors[i] << ",";
    }
    return factors;
}