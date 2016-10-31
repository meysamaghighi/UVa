// Meysam Aghighi
// Comments: 
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a[12];
	for (int i=5;i<16;i++) a[0].push_back(i);
	for (int i=16;i<25;i++) a[1].push_back(i);
	for (int i=25;i<34;i++) a[2].push_back(i);
	for (int i=34;i<45;i++) a[3].push_back(i);
	
	int temp1[] = {1,2,3,8,9,17,18,25,26,34,35};
	a[4] = vector<int>(temp1 , temp1+sizeof(temp1)/sizeof(int));
	int temp2[] = {4,10,11,19,20,27,28,36,37};
	a[5] = vector<int>(temp2 , temp2+sizeof(temp2)/sizeof(int));
	int temp3[] = {12,13,21,22,29,30,38,39,45};
	a[6] = vector<int>(temp3 , temp3+sizeof(temp3)/sizeof(int));
	int temp4[] = {14,15,23,24,31,32,40,41,46,47,48};
	a[7] = vector<int>(temp4 , temp4+sizeof(temp4)/sizeof(int));

	int t1[] = {5,6,16,17,26,27,37,38,45,46,48};
	a[8] = vector<int>(t1 , t1+sizeof(t1)/sizeof(int));
	int t2[] = {7,8,18,19,28,29,39,40,47};
	a[9] = vector<int>(t2 , t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,9,10,20,21,30,31,41,42};
	a[10] = vector<int>(t3 , t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,3,4,11,12,22,23,32,33,43,44};
	a[11] = vector<int>(t4 , t4+sizeof(t4)/sizeof(int));
	

	int hi[12];
	for (int i=0;i<12;i++) cin >> hi[i];
	vector<int> s(49,9); s[0] = 0;
	for (int i=0;i<12;i++){
		for (int j=0;j<a[i].size();j++){
			s[a[i][j]] = min(s[a[i][j]] , hi[i]);
		}
	}
	int most = 0;
	for (int i=0;i<49;i++) most+=s[i];
	cout << most << endl;
	
	
	return 0;
}



