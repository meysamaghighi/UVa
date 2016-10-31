// Meysam Aghighi
// Comments: Build the graph and then bfs.
#include<bits/stdc++.h>
using namespace std;

struct cell {
	int x,y;
	cell(){}
	cell(int _x, int _y):x(_x), y(_y){}
};

const int INF = 1e9;
const int dir[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
const int mov[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool inside(int i, int j, int m, int n){ return i>=0 && j>=0 && i<=m && j<=n; }

void update(string a[], int m, int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j] == 'Z'){
				for (int k=0;k<8;k++){
					int ii = i + dir[k][0], jj = j + dir[k][1];
					if (inside(ii,jj,m,n) && a[ii][jj] == '.') a[ii][jj] = 'X'; 
				}
			}
		}
	}
}

// void print(string a[], int m, int n){
// 	for (int i=0;i<m;i++) cout << a[i] << endl;
// }

int main(){
	int T; cin >> T;
	while (T--){
		int m,n,it; cin >> m >> n;
		string a[m]; 
		cell A,B;
		for (int i=0;i<m;i++){
			cin >> a[i];
			it = a[i].find('A');
			if (it != string::npos) A = cell(i,it);
			it = a[i].find('B');
			if (it != string::npos) B = cell(i,it);
		}
		update(a,m,n);
		// ready for bfs
		int dist[m][n];
		bool mark[m][n]; memset(mark,false,sizeof(mark));
		for (int i=0;i<m;i++) for (int j=0;j<n;j++) dist[i][j] = INF;
		dist[A.x][A.y] = 0;
		queue<cell> q;
		q.push(A);
		mark[A.x][A.y] = true;
		while (!q.empty()){
			cell c = q.front(); q.pop();
			for (int k=0;k<8;k++){
				int i = c.x + mov[k][0], j = c.y + mov[k][1];
				if (inside(i,j,m,n) && !mark[i][j] && (a[i][j]=='.' || a[i][j]=='B')){
					dist[i][j] = dist[c.x][c.y] + 1;
					mark[i][j] = true;
					q.push(cell(i,j));
				}
			}
		}

		int ans = dist[B.x][B.y];
		if (ans == INF) cout << "King Peter, you can't go now!" << endl;
		else cout << "Minimal possible length of a trip is " << ans << endl;		

	}
	return 0;
}



