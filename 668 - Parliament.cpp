// Meysam Aghighi
// Comments: The idea is simple: the numbers must be consecutive except in one place. You have to take care of 1 separately. Also note that
// 			 (1,n)->(n+1) and (x,y)->(x+1,y-1) if (x<y).
//			 In function init(), d is derived by solving x(x+1)/2 = n, we're after the smallest x that x(x+1)/2 > n. 
#include <bits/stdc++.h>
using namespace std;

int f[1001];
void init(){
	double d;
	int dl,du;
	f[1] = 1;
	for (int i=2;i<=1000;i++){
		d = (-1+sqrt(1+8*i))/2;
		dl = floor(d), du = ceil(d);
		f[i] = (dl==du)?du+1:du;
	}
}

int main(){
	init();
	int n,t; cin >> t;
	while (t--){
		cin >> n;
		vector<int> a;
		while (n){
			if (n==1) {
				a[0]++;
				n--;
				break;
			}
			a.push_back(f[n]);
			n -= f[n];
		}
		cout << a[a.size()-1];
		for (int i=a.size()-2;i>=0;i--) cout << " " << a[i];
		cout << endl;
		if (t) cout << endl;
	}
    return 0;
}
