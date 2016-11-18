// Meysam Aghighi
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (cin >> n && n){
		long long sum = 0;
		for (int i=1;i<=n;i++) sum+=i*i;
		cout << sum << endl;
	}
	return 0;
}



