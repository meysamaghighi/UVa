// Meysam Aghighi
// Comments: The problem is to find the shortest length of an Eulerian cycle. Just need to take care of the case with two odd vertices.
#include <bits/stdc++.h>
using namespace std;

#define N 30 // limit is english alphabet
#define INF 1000000

int main(){
	string s;
	while (cin >> s){
		// build graph, deg, total weights
		int dist[N][N],u,v,w,total=0;
		for (int i=0;i<N;i++) for (int j=0;j<N;j++) dist[i][j] = (i==j?0:INF);
		int deg[N]; memset(deg,0,sizeof(deg));
		while (s!="deadend"){
			u = s[0]-'a', v = s[s.size()-1]-'a', w = s.size();
			dist[u][v] = (w < dist[u][v]?w:dist[u][v]);
			dist[v][u] = dist[u][v];
			deg[u]++; deg[v]++;
			total += w;
			cin >> s;
		}
		int odds = 0;
		bool odd[N]; memset(odd,false,sizeof(odd));
		for (int i=0;i<N;i++){			
			if (deg[i]%2) {
				odd[i]=true;
				odds++;
			}
		}
		if (odds<2) cout << total << endl;
		else {
			int s[2], it=0;
			for (int i=0;i<N;i++) if (odd[i]) s[it++] = i;
			// floyd-warshall
			for (int k=0;k<N;k++){
				for (int i=0;i<N;i++)
					for (int j=0;j<N;j++)
						if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF)
							dist[i][j] = dist[i][k] + dist[k][j];
			}
			cout << total+dist[s[0]][s[1]] << endl;
		}
	}
    return 0;
}
