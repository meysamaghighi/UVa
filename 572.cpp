// Meysam Aghighi
// Comments: Make graph + find components (dfs)
#include <bits/stdc++.h>
using namespace std;

struct node{
	int i,j;
	node(int ii, int jj):i(ii),j(jj){}
};

const int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool valid(int i, int j, int n, int m){
	return i>=0 && i<n && j>=0 && j<m;
}

int main(){
	int n,m;
	while (cin >> n >> m && n){
		char a[n][m];
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
		int comps = 0;
		stack<node> s;
		int mark[n][m]; memset(mark,0,sizeof(mark));
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (a[i][j] == '@' && !mark[i][j]){
					comps++;
					mark[i][j] = comps;
					s.push(node(i,j));
				}
				while (!s.empty()){
					node t = s.top(); s.pop();		
					for (int i=0;i<8;i++){
						int ii = t.i+dir[i][0], jj = t.j+dir[i][1];
						if (valid(ii,jj,n,m)) if (a[ii][jj]=='@' && !mark[ii][jj]){
							mark[ii][jj] = comps;
							s.push(node(ii,jj));
						}
					}
				}
			}
		}
		cout << comps << endl;
	}
	return 0;
}