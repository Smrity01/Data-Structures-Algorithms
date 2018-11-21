/*
Implementation of fractional knapsack
written By : Smrity Chaudhary
Dated : 22/11/2018
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item_data{
    /*
    A User defined data type called structure, to store the price and weight of
    an item.
    */
    int price;
    int weight;
};
bool comparision(item_data, item_data);
vector< item_data > input();
void knapsack();
int main() {
    /*
    Objective       : Driver function of the program.
    Input parameter : None
    Output Value    : None
    knapsack();
}
void knapsack() {
    /*
    Objective       : Find Maximum possible value in the knapsack.
    Input parameter : None
    Output Value    : Maximum possible value in the knapsack.
    Description     : First, The array of weight and price of item is sorted in
                        descending order with respect to the price per pound.
                        Then the item in added into knapsack until its capacity
                        is full.
    */
    vector< item_data > item;
    item = input();
    sort(item.begin(),item.end(),comparision);
    int knapsack;
    cout << "\nEnter MAXIMUM Weight of KNAPSACK: ";
    cin >> knapsack;
    int current_weight = 0;
    int profit = 0;
    for (int i = 0;i<item.size();i++) {
        if(current_weight + item[i].weight < knapsack ){
            current_weight = current_weight + item[i].weight;
            profit = profit + item[i].price;
        }
        else{
            profit = profit + (knapsack-current_weight)*(item[i].price/item[i].weight);
            current_weight = knapsack;
            break;
        }
    }
    cout << "\n\nMaximum profit: " << profit;
}
vector< item_data > input() {
    /*
    Objective       : To take input from user.
    Input parameter : None
    Return value    : The array containing price and weight of item.
    Description     : The data of item is stored in the structure type vector.
                        The structure stores data for one item.
    */
    item_data obj;
    vector< item_data > item;
    int number_of_items;
    cout << "Number of item: ";
    cin >> number_of_items;
    while (number_of_items != 0) {
        cout << "\n\nEnter data for ITEM... ";
        cout <<  "\nPrice: ";
        cin >> obj.price;
        cout << "Weight: ";
        cin >> obj.weight;
        item.push_back(obj);
        number_of_items--;
    }
    return item;
}
bool comparision(item_data item1, item_data item2) {
    /*
    Objective       : To provide Sorting order to STL sort function.
    Input parameter : Two items
    Return Value    : True or false
    Description     : Calculate the price per weight for both given items and
                        return true if first items price per weight is greater
                        than another item.
    */
    double price_per_wgt1 = item1.price/item1.weight;
    double price_per_wgt2 = item2.price/item2.weight;
    return price_per_wgt1 > price_per_wgt2;
}
