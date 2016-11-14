// Meysam Aghighi
// Comments: Best solution: Longest Increasing Subsequence O(nlgn), Easy solution: LCS O(n^2) 
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	n++;
	int b[n],x,a[n];
	for (int i=1;i<n;i++){
		cin >> x;
		b[x] = i;
	}
	for (int i=1;i<n;i++) cout << b[i] << " "; cout << endl;
    while(cin >> x){
		a[x] = 1;
        for (int i=2;i<n;i++) {
			cin >> x;
			a[x] = i;
		}
		// check mapping
		for (int i=1;i<n;i++) cout << a[i] << " "; cout << endl;
		int f[n][n];
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==0 || j==0) f[i][j] = 0;
			}
		}
        for (int i=1;i<n;i++){
			for (int j=1;j<n;j++){
				if (a[i]==b[j]) f[i][j] = 1 + f[i-1][j-1];
				else f[i][j] = max(f[i-1][j] , f[i][j-1]);
			}
        }
		cout << f[n-1][n-1] << endl;
    }
    return 0;
}