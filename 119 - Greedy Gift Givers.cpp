// Meysam Aghighi
// Comments: EZ!
#include <bits/stdc++.h>
using namespace std;

int main(){	
	int n; bool flag = false;
	while (cin >> n){
		if (flag) cout << endl;
		flag = true;
		string s[n];
		int a[n]; memset(a,0,sizeof(a));
		map<string,int> mp;
		for (int i=0;i<n;i++){
			cin >> s[i];
			mp[s[i]] = i;
		}
		for (int i=0;i<n;i++){
			string ss; cin >> ss;
			int k = mp[ss], v, t;
			cin >> v >> t; // value and number of recievers
			if (t) { v -= v%t; a[k] -= v; v/=t; }
			for (int j=0;j<t;j++){
				cin >> ss;
				k = mp[ss];
				a[k] += v;
			}		
		}
		// output
		for (int i=0;i<n;i++){
			cout << s[i] << " " << a[i] << endl;
		}		
	}
    return 0;
}
