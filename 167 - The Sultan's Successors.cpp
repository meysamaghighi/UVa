// Meysam Aghighi
// Comments: Backtracking
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pii> queens;
set<int> row, col, di1, di2;
int a[8][8], ans;

bool can(int i, int j){
	return !row.count(i) && !col.count(j) && !di1.count(i+j) && !di2.count(i-j);
}

void put(int i, int j){
	queens.push_back(make_pair(i,j));
	row.insert(i);
	col.insert(j);
	di1.insert(i+j);
	di2.insert(i-j);
}

void rem(int i, int j){
	queens.pop_back();
	row.erase(i);
	col.erase(j);
	di1.erase(i+j);
	di2.erase(i-j);
}

void solve(int i){
	if (i==8){
		if (queens.size() == 8){
			int sum = 0;
			for (auto &x:queens){
				sum += a[x.first][x.second];
			}
			ans = max(ans,sum);
		}
		return;
	}
	for (int j=0;j<8;j++){
		if (can(i,j)){
			put(i,j);
			solve(i+1);
			rem(i,j);
		}
	}
}

void init(){
	queens.clear();
	row.clear();
	col.clear();
	di1.clear();
	di2.clear();
}

int main(){
	int k;
	cin >> k;
	while (k--){
		for (int i=0;i<8;i++) for (int j=0;j<8;j++) cin >> a[i][j];
		init();
		ans = 0;
		solve(0);
		cout << setw(5) << setiosflags(ios::right) << ans << endl;	
	}
    return 0;
}
