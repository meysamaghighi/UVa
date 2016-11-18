// Meysam Aghighi
// Comments: EZ, just solve the equation.
#include <bits/stdc++.h>
using namespace std;

int main(){	
	long long n=2, prints=0;
	while (prints<10){
		long long s = n*n + n;
		s/=2;
		double r = sqrt(s);		
		if (round(r) == r){
			cout << setw(10) << (long long)r << setw(10) << n << endl;
			prints++;
		}
		n++;
	}
    return 0;
}
