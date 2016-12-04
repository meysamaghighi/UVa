// Meysam Aghighi
// Comments: Brute force
#include <bits/stdc++.h>
using namespace std;

const double INF = sqrt(255*255*3);

struct point{
	int x,y,z;
	point(int _x, int _y, int _z): x(_x), y(_y), z(_z){}	
};

double dist(point p, point q){
	int dx = p.x-q.x, dy = p.y-q.y, dz = p.z-q.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(){
	int x,y,z;
	vector<int> a(10,0);
	vector<point> p;
	while (cin >> x >> y >> z && (x || y || z)){
		p.push_back(point(x,y,z));
	}
	int n = p.size();
	for (int i=0;i<n;i++){
		double temp_dist = INF; 
		for (int j=0;j<n;j++){
			if (j == i) continue;
			temp_dist = min(temp_dist , dist(p[i],p[j]));
		}
		if (temp_dist < 10) a[floor(temp_dist)]++;
	}
	for (int i=0;i<10;i++) cout << setw(4) << setiosflags(ios::right) << a[i];
	cout << endl;
	
    return 0;
}
