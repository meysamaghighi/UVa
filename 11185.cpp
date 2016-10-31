// Meysam Aghighi
// Comments: ez!
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	while (cin >> n && n >= 0){
		vector<int> base3;
		if (n == 0) cout << "0";
		while (n){
			int b = n%3;
			// cout << n << " " << b << endl;
			base3.push_back(b);
			n = (n-b)/3;
		}
		for (int i=base3.size()-1;i>=0;i--) cout << base3[i];
		cout << endl;
	}

	return 0;
}