// Meysam Aghighi

#include <bits/stdc++.h>
using namespace std;

string mes[3] = {"Killed by the impact." , "Stuck in the air." , "James Bond survives."};

int main(){
		double k,l,s,w;
		while (cin >> k >> l >> s >> w && (k!=0.0 || l!=0.0 || s!=0.0 || w!=0.0)){
			double g = 9.81;
			double a = k/2, b = -w*g, c = 50*w-w*g*l, cc = -w*g*l;
			double x = 0.0;
			if (b*b-4*a*c >= 0.0) x = (-b+sqrt(b*b-4*a*c))/2.0/a;
			double y = (-b+sqrt(b*b-4*a*cc))/2.0/a;
			int ans = 0; // bad
			if (s > l+y) ans = 1; // ugly
			else if (s >= l+x || s <= 50/g) ans = 2; // good
			cout << mes[ans] << endl;
		}
    return 0;
}
