// Meysam Aghighi
// Comments: Recursively create strings, the repeated subsequences must end at cur. 
#include <bits/stdc++.h>
using namespace std;

int n,m,L,s[100];

bool solve(int cur){
	if (m++ == n){ // output
		for (int i=0;i<cur;i++){
			if (i%64==0 && i) cout << endl;
			else if (i%4==0 && i) cout << " ";
			cout << (char)('A'+s[i]);
		}
		cout << "\n" << cur << endl;
		return true;
	}
	for (int i=0;i<L;i++){
		s[cur] = i;
		bool cont = true;
		for (int j=1;2*j<=cur+1;j++){
			bool check = true;
			for (int k=0;k<j&&check;k++) if (s[cur-k] != s[cur-k-j]) check = false;
			if (check) {
				cont = false;
				break;
			}
		}
		if (cont) if (solve(cur+1)) return true;
	}
	return false;
}

int main(){	
	while (cin >> n >> L && n){
		m = 0;
		solve(0);
	}
    return 0;
}
