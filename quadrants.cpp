/* Determine the quadrant for user entered angle
   Written by: Smrity Chaudhary
   Date : 28/12/2017
*/
#include<iostream>
using namespace std;

float read_angle();
int validate(float);
int main(){
   float angle;
   angle = read_angle();
   validate(angle);

}
float read_angle(){
   float angle;
   cout << "Enter an angle: ";
   cin >> angle;
   return angle;
}
int validate(float angle){
   if (angle == 90)
    cout << "\nNot a quadrant...It is lies on positive Y-axis ";
   else if (angle >0 && angle <90 )
    cout << "\nIt is First Quadrant... ";
   else if (angle >90 && angle <180)
    cout << "\nIt is second Quadrant...";
   else if (angle == 180)
    cout << "\nNot a quadrant...It is lies on Negative X-axis ";
   else if (angle >180 && angle <270)
    cout << "\nIt is Third Quadrant...";
   else if (angle == 270)
    cout << "\nNot a quadrant...It is lies on Negative Y-axis ";
   else if (angle >270 && angle <360)
    cout << "\nIt is fourth Quadrant...";
   else
    cout << "\nNot a quadrant...It is lies positive X-axis ";
}
