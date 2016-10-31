// Meysam Aghighi
// Comments: ...
#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

struct region{
	int x[4];
	region(int a[]){ for (int i=0;i<4;i++) x[i] = a[i];	}
};

struct point{
	int x,y;
	point(int a, int b):x(a),y(b){}
};

bool inside(point p, region r){
	return p.x>=r.x[0] && p.x<=r.x[2] && p.y>=r.x[1] && p.y<=r.x[3];
}

int dist2(point a, point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void print(int n){ // icons <= 50
	if (n<10) cout << "  " << n;
	else cout << " " << n;
	// two ways, both accepted:
	// char buffer[8];
	// snprintf(buffer, sizeof(buffer), "%3d", n);
	// cout << buffer;
}

int main(){
	char c;
	vector<point> icon;
	vector<region> regions;
	bool mark[100]; memset(mark,true,sizeof(mark));
	while (cin >> c && c != '#'){
		if (c == 'I'){
			int x,y; cin >> x >> y; icon.push_back(point(x,y));
		}
		else if (c == 'R'){
			int a[4]; for (int i=0;i<4;i++) cin >> a[i]; regions.push_back(region(a));			
		}
		else if (c == 'M'){
			for (int i=0;i<icon.size();i++) for (int j=0;j<regions.size();j++) if (inside(icon[i],regions[j])) mark[i] = false;
			int x,y; cin >> x >> y; point p(x,y);
			// check regions
			int r = regions.size(), ans = -1;
			for (int i=0;i<r;i++){
				if (inside(p,regions[r-i-1])){
					ans = i;
					break;
				}
			}
			if (ans == -1){ // check icons
				// find min dist
				int min_dist = INF;
				for (int i=0;i<icon.size();i++){
					if (!mark[i]) continue;
					min_dist = min(min_dist,dist2(p,icon[i]));
				}
				vector<int> sol;
				for (int i=0;i<icon.size();i++){
					if (dist2(p,icon[i]) == min_dist && mark[i]) sol.push_back(i+1);
				}
				for (int i=0;i<sol.size();i++) print(sol[i]);
				cout << endl;
			}
			else cout << (char)('A' + (r-ans-1)) << endl;
		}
	}
	return 0;
}