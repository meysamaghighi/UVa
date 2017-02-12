// Meysam Aghighi
// DP
#include <bits/stdc++.h>
using namespace std;

vector<int> a(6); // remaining cards
int dp[5][5][5][5][5][5];

int solve(int n){ // 1: person with last move wins, 0: otherwise
	if (n == 31) return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = 1;
	if (n > 31) return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = 0;
	if (dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] != -1) return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];
	bool is_over = true;
	for (int i=0;i<6&&is_over;i++) if (a[i]>0 && i+1+n<=31) is_over = false;
	if (is_over) return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = 1;
	for (int i=0;i<6;i++){
		if (a[i]>0){
			a[i]--;
			if (solve(i+1+n)==1){
				a[i]++;
				return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = 0;
			}
			a[i]++;
		}
	}
	return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]] = 1;
}

int main(){
			memset(dp,-1,sizeof(dp));
			string s;
			while (cin >> s){
				cout << s << " ";
				a = vector <int> (6,4);
				int n = 0;
				for (int i=0;i<s.size();i++){
					int x = s[i]-'1';
					n += x+1;
					a[x]--;
				}
				int ans = (solve(n)+s.size())%2;
				cout << (char)('A'+ans) << endl;
			}
    return 0;
}
