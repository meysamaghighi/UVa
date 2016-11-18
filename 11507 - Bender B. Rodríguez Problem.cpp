// Meysam Aghighi
// Comments: remeber rotation matrix [cosx -sinx; sinx cosx]
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (cin >> n && n){
		string s;
		int x=1,y=0,z=0;
		for (int i=0;i<n-1;i++){
			cin >> s;
			if (s[0]=='N') continue;
			else if (s=="+y") swap(x,y), x=-x; // x=-y, y=x;
			else if (s=="-y") swap(x,y), y=-y; // x=y, y=-x;
			else if (s=="+z") swap(x,z), x=-x; // x=-z, z=x;
			else swap(x,z), z=-z; // x=z, z=-x; 
		}
		// cout << x << " " << y << " " << z << endl;
		if (x+y+z<0) cout << "-";
		else cout << "+";
		if (x) cout << "x";
		else if (y) cout << "y";
		else cout << "z";
		cout << endl;
	}
    return 0;
}
