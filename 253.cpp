// Meysam Aghighi
// Comments: Recursively check different rotations and note that every two rotations can be achieved by at most 4 clockwise/counter-clockwise rotations.
#include <bits/stdc++.h>
using namespace std;

string r1(string s){
	string ss(s);
	ss[1] = s[2], ss[2] = s[4], ss[3] = s[1], ss[4] = s[3];
	return ss; 
}
string r2(string s){
	string ss(s);
	ss[0] = s[4], ss[1] = s[0], ss[4] = s[5], ss[5] = s[1];
	return ss; 
}

bool f(string s1, string s2, int moves){
	if (s1 == s2) return true;
	if (moves == 5) return false;
	if (f(s1,r1(s2),moves+1)) return true;
	if (f(s1,r2(s2),moves+1)) return true;
	return false;
}

int main(){
	string s;
	while (cin >> s){
		string s1 = s.substr(0,6), s2 = s.substr(6);
		if (f(s1,s2,0)) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;
	}
	return 0;
}