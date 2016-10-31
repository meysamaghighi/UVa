// Meysam Aghighi
// Comments: ...
#include <bits/stdc++.h>
using namespace std;

int main(){
	double up,d,l,b,p,down,v,pi=3.14159265358979323846;
	int sc = 1;
	while (cin >> up && up >= 1.0){
		cin >> d >> l >> b >> p >> down >> v;
		if (sc>1) printf("\n");
		printf("Scenario %d:\n", sc++);
        printf("     up hill         %10.2lf sec\n", up);
        printf("     well diameter   %10.2lf in\n", d);
        printf("     water level     %10.2lf in\n", l);
        printf("     bucket volume   %10.2lf cu ft\n", b);
        printf("     bucket ascent rate%8.2lf in/sec\n", p);
        printf("     down hill       %10.2lf sec\n", down);
        printf("     required volume %10.2lf cu ft\n", v);
        double time = 0;
		int runtime = (int)ceil(v/b - 0.000000000001);
        for(int i = 0; i < runtime; i++) {
            time += up + down + sqrt(2*l/(32.2*12)) + l/p;
            l += 4*b*12*12*12/(d*d*pi);
        }
        printf("     TIME REQUIRED   %10.2lf sec\n", time);
	}	
	return 0;
}