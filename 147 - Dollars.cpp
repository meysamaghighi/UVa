// Meysam Aghighi
// Comments: DP
#include <bits/stdc++.h>
using namespace std;

const int coin[11] = {1,2,4,10,20,40,100,200,400,1000,2000};
long long dp[6001][11]; // dp[s][i] = in how many ways can make s s.t. no coins greater than coin[i] are used. 

void solve(){	
	for (int s=0;s<6001;s++){
		dp[s][0] = 1;
		for (int i=1;i<11;i++){
			// dp[s][i]
			if (s < coin[i]) dp[s][i] = dp[s][i-1];
			else {
				for (int t=0;t<=s/coin[i];t++){
					dp[s][i] += dp[s-t*coin[i]][i-1];
				}
			}
		}
	}
}

int main(){
	solve();
	dp[0][10] = 0;
	double d;
	while (cin >> d && d!=0.0){
		int x = (int)(d*20);
		cout << setw(6) << fixed << setprecision(2) << d;
		cout << setw(17) << dp[x][10] << endl;
	}
    return 0;
}
