// Meysam Aghighi
// shortest path - BFS
#include <bits/stdc++.h>
using namespace std;

const int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

bool valid(int i, int j, int k, int I, int J, int K){
	return i>=0 && i<I && j>=0 && j<J && k>=0 && k<K;
}

struct point{
	int i,j,k;
	point(){}
	point(int _i, int _j, int _k): i(_i), j(_j), k(_k) {}
};

int main(){
	int l,r,c;
	while (cin >> l >> r >> c && l){
		char a[l][r][c];
		point S,E;
		for (int i=0;i<l;i++) for (int j=0;j<r;j++) for (int k=0;k<c;k++){
			cin >> a[i][j][k];
			if (a[i][j][k] == 'S') S = point(i,j,k);
			else if (a[i][j][k] == 'E'){
				E = point(i,j,k);
				a[i][j][k] = '.'; // to fix if in BFS
			}
		}

		// BFS
		int dist[l][r][c];
		bool mark[l][r][c];
		memset(mark,false,sizeof(mark));
		memset(dist,-1,sizeof(dist));
		list<point> s;
		dist[S.i][S.j][S.k] = 0;
		mark[S.i][S.j][S.k] = true;
		s.push_back(S);
		while (!s.empty()){
			point top = s.front();
			s.pop_front();
			for (int i=0;i<6;i++){
				int ii = top.i + dir[i][0], jj = top.j + dir[i][1], kk = top.k + dir[i][2];
				if (valid(ii,jj,kk,l,r,c) && !mark[ii][jj][kk] && a[ii][jj][kk]=='.'){
					dist[ii][jj][kk] = dist[top.i][top.j][top.k] + 1;
					mark[ii][jj][kk] = true;
					s.push_back(point(ii,jj,kk));
				}
			}
		}
		if (dist[E.i][E.j][E.k] == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << dist[E.i][E.j][E.k] << " minute(s)." << endl;

	}

	return 0;
}