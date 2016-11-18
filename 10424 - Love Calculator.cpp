// Meysam Aghighi
// Comments: ez! (pay attention to use getline not cin!)
#include<bits/stdc++.h>
using namespace std;

int g(int n){
	if (n<10) return n;
	int ans = 0;
	while (n){
		ans += n%10;
		n /= 10;
	}
	return g(ans);
}

int f(string s){
	int sum = 0;
	for (int i=0;i<s.size();i++){
		if (s[i]>='a' && s[i]<='z') sum += s[i]-'a'+1;
		else if (s[i]>='A' && s[i]<='Z') sum += s[i]-'A'+1;
	}
	return g(sum);
}

int main(){
	string s,t;
	while (getline(cin,s) && getline(cin,t)){
		int n = f(s), m = f(t);
		double ans = (double)min(n,m)*100/max(n,m);
		printf("%.2f \%\n",ans);
	}
	return 0;
}



