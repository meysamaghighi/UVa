// Meysam Aghighi
// Comments: DP
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,m,k;
	cin >> t;
	while (t--){
		cin >> m >> k;
		long long a[m+1],s[m+1]; memset(s,0,sizeof(s));
		cin >> a[1]; s[1] = a[1];
		for (int i=2;i<=m;i++){
			cin >> a[i];
			s[i] = s[i-1] + a[i];
		}
		long long ** f = new long long *[m+1];
		for (int i=0;i<m+1;i++) f[i] = new long long [m+1];
		for (int i=1;i<=m;i++) f[i][1] = s[i]; // init
		for (int j=2;j<=k;j++){
			for (int i=1;i<=m;i++){
				long long cur = s[m]+1;
				for (int l=i-1;l>=1;l--){
					long long temp = max(f[l][j-1],s[i]-s[l]);
					cur = min(temp,cur);
				}
				f[i][j] = cur;
			}
		}
		stack<int> sol;
		long long sum = 0;
		int rem = k-1;
		for (int i=m;i>=1;i--){
			if (sum+a[i]<=f[m][k] && i>rem) sum += a[i];
			else {
				rem--;
				sum = 0;
				i++;
				sol.push(i);
			}
		}
		int it = sol.top(); sol.pop();
		for (int i=1;i<=m;i++){
			if (i==it){
				cout << "/ ";
				cout << a[i];
				if (sol.size()){
					it = sol.top(); sol.pop();
				}
				else it = -1;
			}
			else cout << a[i];
			if (i!=m) cout << " ";
		}
		cout << endl;
	}	
    return 0;
}
