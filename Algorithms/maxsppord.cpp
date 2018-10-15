#include<iostream>
#include<vector>

void maxSpecialProduct(vector<int> &A);
using namespace std;
int main(){

}
void maxSpecialProduct(vector<int> &A) {

    int n = A.size()-1;
    vector<int> left(n+1,0);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&A[i]>A[s.top()-1]){
            int m = s.top();
            s.pop();
            left[m-1]=i+1;
        }
        s.push(i+1);
    }
    vector<int> right(n+1,0);
    for(int i = 1;i<n;i++){
        while(!s.empty() && A[i] >A[s.top()-1] ){
            int m = s.top();
            s.pop();
            right[m-1]=i+1;
        }
        s.push(i+1);
    }
    int prod =1;
    for(int i = 0;i<left.size();++i){
        prod = max(prod,left[i]*right[i]);
        cout<<right[i]<<" ";
    }
}
