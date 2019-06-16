/*
A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms. Bookings contain an arrival date and a departure date. 
He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
Write a program that solves this problem in time O(N log N).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K);
int main(){
    vector<int> arrive;
    vector<int> depart;
    int K = 1;
    arrive.push_back(1);
    arrive.push_back(3);
    arrive.push_back(5);
    depart.push_back(2);
    depart.push_back(6);
    depart.push_back(8);
    cout << hotel(arrive, depart, K);
}
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(),depart.end());
    int i = 0, j = 0;
    int cumulativeCount = 0;
    int minimumRooms = -1;
    while (i < arrive.size() && j < depart.size()){
        if(arrive[i] < depart[j]){
            cumulativeCount += 1;
            i++;
        }
        else{
            cumulativeCount -= 1;
            j++;
        }
        if (cumulativeCount > minimumRooms){
            minimumRooms = cumulativeCount;
        }
    }
    while( i < depart.size() && j >= depart.size()){
        cumulativeCount += 1;
        i++;
        if (cumulativeCount > minimumRooms){
            minimumRooms = cumulativeCount;
        }
    }
    if (minimumRooms > K){
        return false;
    }
    return true;
}