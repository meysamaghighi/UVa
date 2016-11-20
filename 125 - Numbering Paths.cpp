// Meysam Aghighi
// Comments: Finding number of paths with a modified BFS. For loops, note that for every loop there will be a node i with paths[i][i]>1.
#include <bits/stdc++.h>
using namespace std;

int main(){
	int e,casen=0;
	while (cin >> e){
		int a[e][2],n=0;
		for (int i=0;i<e;i++){
			cin >> a[i][0] >> a[i][1];
			n = max(n,max(a[i][0],a[i][1]));
		}
		n++;
		// make graph - adj list
		vector<int> g[n];
		for (int i=0;i<e;i++) g[a[i][0]].push_back(a[i][1]);
		int paths[n][n]; memset(paths,0,sizeof(paths));
		for (int i=0;i<n;i++){ // BFS
			list<int> s; s.push_back(i);
			bool mark[n]; memset(mark,false,sizeof(mark)); mark[i] = true;
			while (!s.empty()){
				int u = s.front(); s.pop_front();
				if (!paths[i][u]) paths[i][u] = 1;
				for (int j=0;j<g[u].size();j++){
					int v = g[u][j];
					paths[i][v] += paths[i][u];
					if (!mark[v]){
						s.push_back(v);
						mark[v] = true;						
					}
				}
			}
		}
		// Taking care of loops
		for (int i=0;i<n;i++){
			if (paths[i][i]==1) paths[i][i] = 0;
			else {
				paths[i][i] = -1;
				for (int j=0;j<n;j++){
					if (i==j) continue;
					if (paths[i][j]) paths[i][j] = -1;
					if (paths[j][i]) paths[j][i] = -1;
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					if (paths[i][j] && paths[j][k]==-1) paths[i][k] = -1;
				}
			}
		}
		// Output
		cout << "matrix for city " << casen++ << endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){				
				cout << paths[i][j] << (j==n-1?"":" ");
			}
			cout << endl;
		}
	}	
    return 0;
}
