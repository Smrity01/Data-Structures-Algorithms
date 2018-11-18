/*
Algorithm that takes the n rates of price growth and computes an order in which
to buy the license so that the total amount of spent is minimized.
Written By : Smrity Chaudhary
Dated      : 18/11/2018
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> input();
void company();
void sorting(vector<int> &);
int main(){
    /*
    Objective       : To call the function with main algorithm.
    Input Parameter : None
    Description     : Driver function of the program.
    */
    company();
}

void company(){
    /*
    Objective       : To Find order for Minimizing the amount spent.
    Input Parameter : None
    Output value    : Print the rates in the correct order to minimize amount.
    Description     : Simply sort the list of rates using STL stable sort.
    */
    vector<int> rates;
    rates = input();
    stable_sort(rates.begin(),rates.end());
    cout << "\nIn the following Order to buy the license...\n";
    int counter = 1;
    for(int i=rates.size()-1;i>=0;i--){
        cout <<"\n r" << counter << ":  "<< rates[i] << ",";
        counter++;
    }
}

vector<int> input(){
    /*
    Objective       : To Take input from user.
    Input Parameter : None
    Description     : Take input from user and return data to calling function.
    */
    vector< int > rates;
    int price;
    int license;
    cout << "How many Licenses...: ";
    cin >> license;
    int counter = 1;
    while (license!=0){
        cout << "Enter rate of "<< counter << ": ";
        cin >> price;
        rates.push_back(price);
        counter++;
        license--;
    }
    return rates;
}
