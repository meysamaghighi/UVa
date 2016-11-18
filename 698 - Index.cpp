// Meysam Aghighi
// The challenges for me were to take care of the special cases correctly: character C, debugging contains function, etc.
#include<bits/stdc++.h>
using namespace std;

const char C = '\0';

bool contains(string text, string s){
	int t = text.size(), n = s.size();
	if (text == s) return true;
	if (text.find(C+s+C)!=string::npos) return true;
	if (n<t && s+C == text.substr(0,n+1)) return true;
	if (n<t && C+s == text.substr(t-n-1,n+1)) return true;
	return false;
}

int main(){
	string s;
	int mode = 0;
	vector<string> index;
	vector<string> lines;
	int T = 1;
	while (getline(cin,s)){
		while (!s.empty()){ // get index terms
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			index.push_back(s);
			getline(cin,s);
		}
		while (s.empty()) getline(cin,s);
		while (!s.empty()){ // get text
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			for (int i=0;i<s.size();i++){
				if ((s[i]<'A' || s[i]>'Z') && (s[i]<'0' || s[i]>'9')) s[i] = C;
			}
			lines.push_back(s);
			getline(cin,s);
		}
		sort(index.begin(),index.end());
		vector<int> count[index.size()];
		for (int i=0;i<index.size();i++){
			for (int j=0;j<lines.size();j++){
				if (contains(lines[j],index[i])) count[i].push_back(j);
			}
		}
		cout << "Case " << T++ << endl;
		for (int i=0;i<index.size();i++){
			if (!count[i].empty()) cout << index[i] << " " << count[i][0]+1;
			for (int j=1;j<count[i].size();j++){
				int temp = 0;
				while (j<count[i].size() && count[i][j] == count[i][j-1]+1){
					j++; temp++;
				}						
				if (temp) cout << "-" << count[i][--j]+1;
				else cout << ", " << count[i][j]+1; 
			}
			if (!count[i].empty()) cout << endl;
		}
		cout << endl;
		lines.clear(); index.clear();		
	}
	return 0;
}



