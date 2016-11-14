// Meysam Aghighi
// Comments: Straight-forward simulation
#include <bits/stdc++.h>
using namespace std;

bool match(string s1, string s2){
	assert(s1.size()==2 && s2.size()==2);
	return s1[0]==s2[0] || s1[1]==s2[1];
}

void inner_move(vector<stack<string> > &pile, int i, int j){
	string s = pile[j].top(); pile[j].pop();
	pile[i].push(s);
	if (pile[j].empty()) pile.erase(pile.begin()+j);
}

bool move(vector<stack<string> > &pile){
	for (int i=0;i<pile.size();i++){
		if (i>2 && match(pile[i-3].top(),pile[i].top())){ // move
			inner_move(pile,i-3,i);
			return true;
		}
		if (i>0 && match(pile[i-1].top(),pile[i].top())){ // move
			inner_move(pile,i-1,i);
			return true;
		}
	}
	return false;
}

stack<string> f(string s){
	stack<string> ss;
	ss.push(s);
	return ss;
}

int main(){
	vector<stack<string> > pile;
	string s;
	while (cin >> s && s[0]!='#'){
		pile.push_back(f(s));
		for (int i=0;i<51;i++){
			cin >> s;
			pile.push_back(f(s));
		}
		while(move(pile)){}
		cout << pile.size() << " pile" << (pile.size()==1?"":"s") << " remaining:";
		for (auto p: pile) cout << " " << p.size();
		cout << endl;
		pile.clear();
	}
	return 0;
}