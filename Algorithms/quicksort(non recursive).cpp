/*
Implementation of Quicksort (Iterative)
written By : Smrity Chaudhary
Dated      : 08/10/2018
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void quicksort(vector<int> &,int,int);
int quick_partition(vector<int> &,int,int);
int main(){
    /*
    Objective       : Take input in vector and call other functions
    Input Parameter : None
    Output Value    : Sorted Array
    */
    int element;
    vector<int> element_list;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an element: ";
        cin >> element;
        element_list.push_back(element);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }
    quicksort(element_list,0,element_list.size()-1);
    cout << " Sorted array: ";
    for ( int i=0;i<element_list.size();i++){
        cout << element_list[i]<< " ";
    }
    return 0;
}
void quicksort(vector<int> &elist, int p,int r){
    /*
    Objective       : Sort the given list of elements
    Input Parameter : List of elements in vector, first and last position
    Output Value    : None
    Approach        : one element(pivot) placed at its right position then
                      list is divided into two unsorted parts and further
                      call quick sort iteratively on both parts
                      positions at which list is divided are stored in the stack
    */
    stack<int> position;
    int q;
    position.push(p);
    position.push(r);
    while(!position.empty()){
        r = position.top();
        position.pop();
        p = position.top();
        position.pop();
        //right position of pivot element
        q = quick_partition(elist,p,r);
        //If elements left in right side,then push position(right unsorted) into stack
        if(q+1<r){
        position.push(q+1);
        position.push(r);
        }
        //If elements left in left side, then push positions(left unsorted) into stack
        if(p<q-1){
            position.push(p);
            position.push(q-1);
        }
    }
}
int quick_partition(vector<int> &elist,int p,int r){
    /*
    Objective       : Place pivot element at its right position
    Input Parameter : List of elements in vector, first and last position
    Return Value    : right position of pivot element
    Approach        : Pivot element will be compared with each element
                      all smaller elements placed at left side of pivot
                      and larger elements left at right side  of pivot
    */
    int pivot = r;// last element taken as pivot
    int j = p;
    int i = j-1;
    int temp;
    //comparing each element with pivot
    while(j<pivot){
        //looking for smaller elements
        if(elist[j] <= elist[pivot]){
            i++;
        //place smaller elements at the beginning
            temp = elist[i];
            elist[i] = elist[j];
            elist[j] = temp;
        }
        j++;
    }
    // place pivot at its right position
    temp = elist[i+1];
    elist[i+1] = elist[pivot];
    elist[pivot] = temp;
    return i+1;
}
