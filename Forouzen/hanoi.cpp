/* Demonstrate the tower of hanoi
    Written by : smrity chaudhary
        Dated  : 14/01/2018
*/
#include<iostream>
using namespace std;

void tower_hanoi(int disks,char source,char auxiliary,char destination);
int main(){
    tower_hanoi(3,'A','B','C');
}
void tower_hanoi(int disks,char source,char auxiliary,char destination){
    if(disks==1){
        cout << "\nMove from "<< source << " to "<< destination;
        }
    else{
        tower_hanoi(disks-1,source,destination,auxiliary);
        cout << "\nMove from "<< source << " to "<< destination;
        tower_hanoi(disks-1,auxiliary,source,destination);
    }
    return;
}
