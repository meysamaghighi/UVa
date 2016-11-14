// Meysam Aghighi
// Comments: You need to find out that the answer is the number of odd divisors of N. Then you'll need a prime sieve, etc.
#include <bits/stdc++.h>
using namespace std;

#define N 10000000
bitset<N> p;
vector<int> prime;

// Prime Sieve
void init(){
	p.flip();
	for (int i=2;i<sqrt(N);i++){
		if (p[i]){
			int x = 2*i;
			while (x < N){
				p[x] = 0;
				x += i;
			}
		}
	}
	p[1] = 0;
	for (int i=2;i<N;i++){
		if (p[i]) prime.push_back(i);
	}
}

int main(){	
	init();	
	long long n;
	while (cin >> n){
		if (!n){ cout << "0" << endl; continue; }
		int ans = 1;
		while (!(n&1)) n>>=1;
		for (int i=0;i<prime.size()&&prime[i]<=sqrt(n);i++){
			int t = 1;
			while (!(n%prime[i])){
				t++;
				n/=prime[i];
			}
			ans *= t;
		}
		if (n>1) ans<<=1;
		cout << ans << endl;
	}
    return 0;
}
