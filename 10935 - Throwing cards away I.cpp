// Meysam Aghighi
// Comments: list exercise
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	while (cin >> n && n){
		list<int> a;
		for (int i=0;i<n;i++) a.push_back(i+1);
		cout << "Discarded cards:";
		while (a.size()>1){
			x = a.front(); a.pop_front();
			cout << " " << x;
			if (a.size()>1) cout << ",";
			x = a.front(); a.pop_front();
			a.push_back(x);
		}
		cout << endl;
		cout << "Remaining card: " << a.front() << endl;
	}
    return 0;
}