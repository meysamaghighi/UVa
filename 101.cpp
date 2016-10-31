// Meysam Aghighi
// Comments: Straight-forward simulation - using an array of lists
#include <bits/stdc++.h>
using namespace std;

int find(list<int> block[], int n, int a){
	for (int i=0;i<n;i++) for (auto aa: block[i]) if (a == aa) return i;
}

void print(list<int> block[], int n){
	for (int i=0;i<n;i++){
		cout << i << ":";
		for (auto p: block[i]) cout << " " << p;
		cout << endl;
	}
}

int main(){
	int n; cin >> n;
	list<int> block[n];
	list<int>::iterator ita,itb;
	for (int i=0;i<n;i++) block[i].push_back(i);
	string s,t;
	while (cin >> s && s[0]!='q'){
		int a,b,i,j;
		cin >> a >> t >> b;
		// print(block,n); cout << "==============" << endl;
		// cout << s << " " << a << " " << t << " " << b << endl;
		if (a == b) continue;
		i = find(block,n,a), j = find(block,n,b);
		if (i == j) continue;
		if (s == "move"){
			if (t == "onto"){
				for (ita=block[i].begin();ita!=block[i].end();ita++) if (*ita == a) break;
				for (itb=block[j].begin();itb!=block[j].end();itb++) if (*itb == b) break;
				itb++;
				itb = block[j].insert(itb,a); itb++;
				ita = block[i].erase(ita);
				while (ita!=block[i].end()){
					block[*ita].push_back(*ita); // move to initial place
					ita = block[i].erase(ita);
				}
				while (itb!=block[j].end()){
					block[*itb].push_back(*itb);
					itb = block[j].erase(itb);
				}
				
			}
			else { // over				
				for (ita=block[i].begin();ita!=block[i].end();ita++) if (*ita == a) break;				
				block[j].push_back(a);
				ita = block[i].erase(ita);
				while (ita!=block[i].end()){
					block[*ita].push_back(*ita); // move to initial place
					ita = block[i].erase(ita);
				}
			}
		}
		else { // pile
			if (t == "onto"){
				// remove pile over a from block[i] and move onto b in block[j]
				for (ita=block[i].begin();ita!=block[i].end();ita++) if (*ita == a) break;
				for (itb=block[j].begin();itb!=block[j].end();itb++) if (*itb == b) break;
				itb++;
				while (ita!=block[i].end()){
					itb = block[j].insert(itb,*ita);
					itb++;
					ita = block[i].erase(ita);
				}
				while (itb!=block[j].end()){
					block[*itb].push_back(*itb);
					itb = block[j].erase(itb);
				}		
			}
			else { // over
				// remove pile over a from block[i] and move over block[j]
				for (ita=block[i].begin();ita!=block[i].end();ita++) if (*ita == a) break;				
				while (ita!=block[i].end()){
					block[j].push_back(*ita);
					ita = block[i].erase(ita);
				}
			}
		}
	}
	print(block,n);
	return 0;
}