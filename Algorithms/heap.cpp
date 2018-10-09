/*
Implementation of Heap Sort
Written By : Smrity Chaudhary
Dated      : 09/10/2018
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void max_heapify(vector<int> &elist,int index,int length);
void build_heap(vector<int> &elist);
void heapsort(vector<int> &elist);
int main(){
    /*
    Objective       : Take input in vector and call other functions
    Input Parameter : None
    Output Value    : Sorted Array
    Description     : Driver function
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
    heapsort(element_list);
    cout << " Sorted array: ";
    for ( int i=0;i<element_list.size();i++){
        cout << element_list[i]<< " ";
    }
    return 0;
}
void heapsort(vector<int> &elist){
    /*
    Objective       : To sort given list of numbers
    Input Parameter : List of numbers
    Output Value    : None
    Approach        : First it will build the heap of given list of numbers, then
                      place the root element(maximum) at its right position and
                      repeat the process until second element.
    */
    build_heap(elist);
    int length = elist.size()-1;
    for(int i=length;i>=1;i--){
        int temp = elist[0];
        elist[0] = elist[i];
        elist[i] = temp;
        length--;//Because last element in list is maximum so,we will find maximum
                 // in rest of the list
        max_heapify(elist,0,length);
    }
}
void build_heap(vector<int> &elist){
    /*
    Objective       : Build the max heap of numbers
    Input Parameter : List of numbers
    Output Value    : None
    Approach        : It will follow the bottom up approach to convert list into
                      max heap. It means the order is from leaf to root.
    */
    int length = elist.size()-1;
    for(int i = floor(length/2);i>=0;i--){
        max_heapify(elist,i,elist.size()-1);
    }
}
void max_heapify(vector<int> &elist,int index,int length){
    /*
    Objective       : To maintain max heap property
    Input Parameter : List of numbers, index from where to float down,size of list
    Output Value    : None
    Approach        : Check children of current node following heap property, if
                        if not then exchange node with max-child. Now,float down
                        so that the subtree also follow max heap property.
    */
    int left = 2*index+1;
    int right = 2*index+2;
    int largest;
    //check if left child is largest
    if(left <= length && elist[left]>elist[index]){
        largest = left;
    }
    else{
        largest = index;
    }
    //check for right child
    if(right <= length &&  elist[right]>elist[largest]){
        largest = right;
    }
    //if root is not largest then exchange it with its largest child
    if(largest!=index){
        int temp = elist[largest];
        elist[largest] = elist[index];
        elist[index] = temp;
        //float down
        max_heapify(elist,largest,length);
    }
}
