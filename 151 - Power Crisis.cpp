// Meysam Aghighi

#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a, int step, int start){
	if (a.size() == 1) return a[0];
	a.erase(a.begin()+start);
	start = (start + step - 1) % a.size();
	return f(a,step,start);
}


int main(){
	int n;
	while (cin >> n && n){
		int ans = 0;
		for (int t=1;t<n;t++){
			vector<int> a(n);
			for (int i=0;i<n;i++) a[i] = i+1;
			if (f(a,t,0) == 13){
				ans = t;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
