#include <iostream>
using namespace std;

int main() {
	int a[5];
	cout << "enter : ";
	for(int i=0;i<5;i++){
        cin >> a[i];
	}
	cout << a[0] <<" " << a[1] <<" "<<a[2] <<" " << a[3] <<" "<<a[4];
	return 0;
}
