// Meysam Aghighi
// Comments: 
#include <bits/stdc++.h>
using namespace std;

int ones(int t){
	int b1 = 0;
	while (t){
			b1 += t%2;
			t /= 2;
	}
	return b1;
}

int main(){
	int n,x,b1,b2,t,b; cin >> n;
	while (n--){
		cin >> x;
		b1 = ones(x);
		t = 0, b = 1;
		while (x){
			t += (x%10)*b;
			b *= 16;
			x /= 10;
		}
		b2 = ones(t);
		cout << b1 << " " << b2 << endl;
	}
	return 0;
}