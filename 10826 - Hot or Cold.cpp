// Meysam Aghighi
// Comments: DP, or backtrack with memo.
#include <bits/stdc++.h>
using namespace std;

#define N 310
#define INF 20
int dp[N][N];

int f(int lo, int hi, int last){
	if (lo == hi) return (last==lo)?1:2;
	int d = (last>=lo)?(last-lo):(hi-last);
	if (dp[hi-lo][d]<INF) return dp[hi-lo][d];
	int ans = INF;
	for (int x=lo;x<=hi;x++){
		int t1 = 0, t2 = 0, mi1 = (x+last)/2, mi2 = (x+last+1)/2;
		if (x == last) continue;
		if (x < last) {
			if (mi2 <= hi) t1 = f(max(lo,mi2),hi,x);
			t2 = f(lo,min(hi,mi1),x);
		}
		else {
			if (mi1 >= lo) t1 = f(lo,min(hi,mi1),x);
			t2 = f(max(lo,mi2),hi,x);
		}
		ans = min(ans,max(t1,t2)+1);
	}
	return dp[hi-lo][d] = ans;
}

int main(){
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) dp[i][j] = INF;
	int n;
	while (cin >> n && n){
		int ans = INF;
		for (int i=1;i<=n;i++) ans = min(ans,f(1,n,i));
		cout << ans << " guess(es) required." << endl;
	}
    return 0;
}
