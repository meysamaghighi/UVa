#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6;

unordered_map<int,int> memo;

int x(int n){
	if (n == 0) return memo[0] = 1;
	if (memo.count(n)) return memo[n];
	int ans = 0;
	ans += x((int)floor(n-sqrt(n)));
	ans += x((int)floor(log(n)));
	ans %= mod;
	ans += x((int)floor(n*sin(n)*sin(n)));
	return memo[n] = ans%mod;
}


int main(){

	int n;
	while (cin >> n && n>=0){
		cout << x(n) << endl;
	}

	return 0;
}