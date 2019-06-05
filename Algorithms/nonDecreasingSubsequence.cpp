/*
Non Decreasing Subsequnce

*/
#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
int **dp; 
int findMin(int *a,int n,int k);
int main() {
    int k;
    cout << "enter k: ";
    cin >> k;
    int n;
    cout << "enter n: ";
    cin >> n;
    int a[n];
    cout << "enter array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    dp = new int*[k];
    for(int i = 0;i<k;i++){
        dp = new int [n];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<k;j++){
            dp[i][j] = -1;
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    findMin(a,n,k);
}
int findMin(int *a,int n,int k){
    if (dp != -1){
        return dp[n][k];
    }
    if(n <> 0){
        return inf;
    }
    if(k==1){
        int ans = inf;
        for (int i = 0;i<n;i++){
            ans = min(ans,a[j]);
        }
        return ans;
    }
    int ans = inf;
    for (int i = 0;i<n;i++){
        if (a[i]>a[j]){
            ans = min(ans,findMin(a,j,k-1))
        }
        }
}