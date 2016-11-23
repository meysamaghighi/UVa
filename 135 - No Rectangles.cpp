// Meysam Aghighi
// Comments: You need to find a pattern that occupies k elements in each row, while every two rows intersect on exactly one place.
#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,n;
	bool cs = false;
	while (cin >> k){
		if (cs) cout << endl;
		cs = true;
		n = k*k-k+1;
		char a[n][n];
		memset(a,'0',sizeof(a));
		for (int i=0;i<k;i++){
			a[i][0] = '1';
			for (int j=1;j<k;j++) a[i][i*(k-1)+j] = '1';
		}
		for (int i=0;i<k-1;i++){
			for (int j=0;j<k-1;j++){
				int row = k+i*(k-1)+j; 
				a[row][i+1] = '1';
				for (int l=0;l<k-1;l++){
					a[row][(j+l*i)%(k-1)+l*(k-1)+k] = '1';
				}
			}
		}
		for (int i=0;i<n;i++){
			bool first = false;
			for (int j=0;j<n;j++){
				if (a[i][j]=='1'){
					if (first) cout << " " << j+1;
					else cout << j+1;
					first = true;
				}
			}
			cout << endl;
		}
	}
    return 0;
}
