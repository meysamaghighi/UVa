// Meysam Aghighi
// Comments: EZ
#include <bits/stdc++.h>
using namespace std;

pair<int,int> cross(string a, string b){
	int i,j;
	bool found = false;
	for (i=0;i<a.size();i++){
		for (j=0;j<b.size();j++){
			if (a[i]==b[j]){
				found = true;
				break;
			}
		}
		if (found) break;
	}
	if (found) return make_pair(i,j);
	return make_pair(-1,-1);
}

int main(){
	string a,b,A,B;
	bool check = false;
	while (cin >> a >> b >> A >> B && a!="#"){
		if (check) cout << endl;
		else check = true;
		pair<int,int> x = cross(a,b), y = cross(A,B);
		if (x.first>=0 && y.first>=0){
			int X = max(x.second,y.second)+max(b.size()-x.second,B.size()-y.second), Y = a.size()+3+A.size();
			string s[X];
			for (int i=0;i<X;i++) s[i] = string(Y,' ');
			for (int i=0;i<b.size();i++) s[i+max(x.second,y.second)-x.second][x.first] = b[i];
			for (int i=0;i<B.size();i++) s[i+max(x.second,y.second)-y.second][a.size()+3+y.first] = B[i];
			for (int i=0;i<a.size();i++) s[max(x.second,y.second)][i] = a[i];
			for (int i=0;i<A.size();i++) s[max(x.second,y.second)][i+a.size()+3] = A[i];
			// clean the trailing spaces
			for (int i=0;i<X;i++){
				for (int j=0;j<Y;j++){
					if (s[i].substr(j)==string(Y-j,' ')){
						s[i].erase(j,Y-j);
						break;
					}
				}
			}
			for (int i=0;i<X;i++) cout << s[i] << endl;
		}
		else cout << "Unable to make two crosses" << endl;		
	}
    return 0;
}
