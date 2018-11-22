
// Write your code here
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int anagram(string ,string );
int main() {
	int t;
	cout << "enter t: ";
	cin>>t;
	string a,b;
	while (t!=0) {
        cout << "enter a: ";
	    cin>>a;
	    cout << "enter b: ";
	    cin>>b;
	    anagram(a,b);
	    t--;
	}
	return 0;
}
int anagram(string a,string b) {
    int counta[26];
    int countb[26];
    for (int i=0;i<26;i++) {
        counta[i] = countb[i] = 0;
    }
    for (int i = 0;i<a.length();i++) {
        counta[(int)(a[i]-'a')]++;
    }
    for (int i = 0;i<a.length();i++) {
        countb[(int)(b[i]-'a')]++;
    }
    int delete_letter = 0;
    for(int i=0;i<26;i++){
        delete_letter = delete_letter + abs(counta[i] - countb[i]);
    }
    cout << delete_letter <<endl;
}
