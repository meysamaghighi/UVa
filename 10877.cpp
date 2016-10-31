// Meysam Aghighi
// Comments: Not the smartest way... but brute force every rotation.
#include <bits/stdc++.h>
using namespace std;

const int A=0,B=1,C=2,D=3,E=4,F=5;

int rot[24][6] = {
				{A,B,C,D,E,F},
				{A,E,B,D,F,C},
				{A,F,E,D,C,B},
				{A,C,F,D,B,E},
				{B,C,A,F,D,E},
				{B,A,E,F,C,D},
				{B,E,D,F,A,C},
				{B,D,C,F,E,A},
				{C,A,B,E,F,D},
				{C,B,D,E,A,F},
				{C,D,F,E,B,A},
				{C,F,A,E,D,B},
				{D,E,F,A,B,C},
				{D,F,C,A,E,B},
				{D,C,B,A,F,E},
				{D,B,E,A,C,F},
				{E,F,D,C,A,B},
				{E,D,B,C,F,A},
				{E,B,A,C,D,F},
				{E,A,F,C,B,D},
				{F,D,E,B,C,A},
				{F,E,A,B,D,C},
				{F,A,C,B,E,D},
				{F,C,D,B,A,E}
};

bool equal(int a[], int b[]){
	for (int k=0;k<24;k++){
		bool flag = true;
		for (int i=0;i<6;i++) if (a[i] != b[rot[k][i]]) flag = false;
		if (flag) return true;
	}
	return false;
}

int main(){
	int n;
	while (cin >> n && n){
		int a[n][6], sum = 0;
		for (int i=0;i<n;i++){
			for (int j=0;j<6;j++) cin >> a[i][j];
			bool flag = true;
			for (int k=0;k<i&&flag;k++) if (equal(a[k],a[i])) flag = false;
			if (flag) sum++; 
		}
		cout << sum << endl;
	}

	return 0;
}