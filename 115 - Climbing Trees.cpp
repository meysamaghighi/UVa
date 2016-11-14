// Meysam Aghighi
// Comments: --
#include <bits/stdc++.h>
using namespace std;

int main(){	
	string s1,s2;
	map <string,string> dad;
	while (cin >> s1 >> s2 && (s1!="no.child" || s2!="no.parent")){
		dad[s1] = s2;
	}
	while (cin >> s1 >> s2){
		bool found = false;
		if (dad.count(s2) && dad[s2] == s1) cout << "parent";
		else if (dad.count(s1) && dad[s1] == s2) cout << "child";
		else if (dad.count(s1) && dad.count(s2) && dad[s1] == dad[s2]) cout << "sibling";
		else { // great ... great grand parent
			int level = 0;
			string s = s2;
			while (dad.count(s)) {
				level++;
				s = dad[s];
				if (s == s1) {
					found = true;
					break;
				}
			}
			if (found){
				for (int i=0;i<level-2;i++) cout << "great ";
				cout << "grand parent";
			}
			if (!found){ // great grand child
				level = 0;
				s = s1;
				while (dad.count(s)) {
					level++;
					s = dad[s];
					if (s == s2) {
						found = true;
						break;
					}
				}
				if (found){
					for (int i=0;i<level-2;i++) cout << "great ";
					cout << "grand child";
				}
			}
			if (!found){ // cousin
				vector <string> dads1, dads2;
				string s = s1;
				while (dad.count(s)){				
					s = dad[s];
					dads1.push_back(s);
				}
				s = s2;
				while (dad.count(s)){
					s = dad[s];
					dads2.push_back(s);
				}
				if (dads1.size() || dads2.size()){
					int i,j;
					for (i=0;i<dads1.size();i++){
						for (j=0;j<dads2.size();j++){
							if (i==0 && j==0) continue;
							if (dads1[i] == dads2[j]){
								found = true;
								break;
							}
						}
						if (found) break;
					}
					if (found) {
						if (i!=j) cout << min(i,j) << " cousin removed " << abs(i-j);
						else cout << min(i,j) << " cousin";
					}
				}
			}
			if (!found) cout << "no relation";		
		}		
		cout << endl;
	}
    return 0;
}
