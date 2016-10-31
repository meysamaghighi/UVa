// Meysam Aghighi
// Comments: ez!
#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char,int> m;
	m['B'] = 1;
	m['F'] = 1;
	m['P'] = 1;
	m['V'] = 1;
		
	m['C'] = 2;
	m['G'] = 2;
	m['J'] = 2;
	m['K'] = 2;
	m['Q'] = 2;
	m['S'] = 2;
	m['X'] = 2;
	m['Z'] = 2;
	
	m['D'] = 3;
	m['T'] = 3;
	
	m['L'] = 4;
	
	m['M'] = 5;
	m['N'] = 5;
	
	m['R'] = 6;
	
	string s;
	while (cin >> s){
		int last = -1;
		for (int i=0;i<s.size();i++){
			if (m.count(s[i])){
				if (m[s[i]] != last) cout << m[s[i]];
				last = m[s[i]];
			}
			else last = -1;
		}
		cout << endl;
	}
	
	
	return 0;
}



