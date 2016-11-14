// Meysam Aghighi
// Comments: can be solved in O(n) but this solution is in O(n+C), where n is the number of buildings and C is the range.
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[10010]; memset(a,0,sizeof(a));
	int l,r,h;
	while (cin >> l >> h >> r) for (int i=l;i<r;i++) a[i] = max(a[i],h); // a[i] covers between i and i+1
	bool flag = false;
	for (int i=0;i<10010;i++){
		if (i && a[i] == a[i-1]) continue;
		else if (a[i]>0){
			if (flag) cout << " ";
			flag = true;
			cout << i << " " << a[i];
		}
		else if (flag){
			cout << " " << i << " " << a[i];
		}
	}
	cout << endl;
    return 0;
}