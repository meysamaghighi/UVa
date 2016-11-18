// Meysam Aghighi
// Comments: You need to solve the geometry. 
#include <bits/stdc++.h>
using namespace std;

const double r = sqrt(3)/2;

int skew(double x, double y){
	if (y<1) return 0;
	int a = floor(x), b = floor((y-1)/r)+1;
	if (x>=a+0.5) return a*b;
	if (b%2==0) return a*b/2+(a-1)*b/2;
	return a*(b+1)/2+(a-1)*(b-1)/2;
}

int main(){
	double x,y;
	while (cin >> x >> y){
		int best = skew(x,y);
		best = max(best,skew(y,x));
		if (best <= floor(x)*floor(y)){
			cout << floor(x)*floor(y) << " grid" << endl;
		}
		else cout << best << " skew" << endl;
	}
    return 0;
}
