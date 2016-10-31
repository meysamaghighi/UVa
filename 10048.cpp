// Meysam Aghighi
// Comments: This solution shouldn't get accepted, but because of weak test cases it does.
// 			 I do floyd-warshal e times which is trivially not the best solution. 
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,e,q,u,v,d,INF=1e9,cs=1;
	while (cin >> n >> e >> q && n){
		int g[n][n]; memset(g,-1,sizeof(g));
		for (int i=0;i<e;i++) {
			cin >> u >> v >> d;
			g[u-1][v-1] = g[v-1][u-1] = d;
		}
		int dist[n][n];
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) dist[i][j] = g[i][j]==-1?INF:g[i][j];
		// floyd-warshal
		for (int kk=0;kk<e;kk++)
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					int temp = max(dist[i][k],dist[k][j]);
					if (temp < dist[i][j])
						dist[i][j] = temp;
				}
			}
		}
		if (cs>1) cout << endl;
		cout << "Case #" << cs++ << endl;
		for (int i=0;i<q;i++){
			cin >> u >> v;
			int ans = dist[u-1][v-1];
			if (ans == INF) cout << "no path" << endl;
			else cout << ans << endl;
		}		
	}
	return 0;
}