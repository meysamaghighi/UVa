// Meysam Aghighi
// Comments: Use Heron and check for triangle inequalities. 
#include <bits/stdc++.h>
using namespace std;

int main(){
	double ha,hb,hc,x,s;
	int n; cin >> n;
	while (cin >> ha >> hb >> hc){
		if (ha*hb*hc==0){
			cout << "These are invalid inputs!" << endl;
			continue;
		}
		ha=1/ha, hb=1/hb, hc=1/hc;
		if (ha<=0 || hb<=0 || hc<=0 || ha+hb-hc<=0 || ha+hc-hb<=0 || hb+hc-ha<=0){
			cout << "These are invalid inputs!" << endl;
			continue;
		}
		else {
			x = ha+hb+hc;
			ha*=2, hb*=2, hc*=2;
			s = sqrt(1/x/(x-ha)/(x-hb)/(x-hc));
			cout << fixed << setprecision(3) << s << endl;
		}
	}
    return 0;
}
