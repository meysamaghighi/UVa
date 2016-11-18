// Meysam Aghighi
// Comments: Construct the graph + Dijkstra
#include <bits/stdc++.h>
using namespace std;

struct edge{
	int to;
	double weight;
	edge(){}
	edge(int _to, double _weight){
		to = _to;
		weight = _weight;
	}
	bool operator < (edge e) const {
		return weight > e.weight;
	}
};

double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int w,h,n,N;
	while (cin >> w >> h >> n){
		N = n+2;
		double x[N],y[N];
		vector<edge> adjlist[N]; // fix
		x[0] = y[0] = 0;
		x[1] = (double)w, y[1] = (double)h;
		for (int i=2;i<N;i++){
			cin >> x[i] >> y[i];
		}
		for (int i=0;i<N;i++){
			for (int j=0;j<i;j++){
				double d = distance(x[i],y[i],x[j],y[j]); 
				if (d <= 1.5){
					adjlist[i].push_back(edge(j,d));
					adjlist[j].push_back(edge(i,d));
				}
			}
		}
		double thres; cin >> thres;
		// dijkstra
		double INF = 1e10;
		vector <double> dist = vector<double>(N+1,INF);
		priority_queue <edge> q;
		q.push(edge(0,0));
		dist[0] = 0;
		while(!q.empty()){
			edge top = q.top(); q.pop();
			int u = top.to;
			for(int i=0;i<adjlist[u].size();i++){
				int v = adjlist[u][i].to;
				if(dist[u] + adjlist[u][i].weight < dist[v]){
					dist[v] = dist[u] + adjlist[u][i].weight;
					q.push(edge(v,dist[v]));
				}
			}
		}
		// cout << dist[1] << " " << thres << endl;
		if (dist[1]<=thres) cout << "I am lucky!" << endl;
		else cout << "Boom!" << endl;
	}
	return 0;
}