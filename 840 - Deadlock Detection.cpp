// Meysam Aghighi
// Comments: I got sooo many wrong answers on this problem... almost killed me...
// one idea was in solve() function instead of checking for any marked node, search for the head of the path
// the other problems were because of poor problem description and poor examples.
#include<bits/stdc++.h>
using namespace std;

const int maxn = 52;
int a[maxn][maxn];
int n,m,e,t,x,y;
vector <vector<int> > cycles;
vector <int> path;
bool mark[maxn];

void solve(int n){	
	for (int i=0;i<maxn;i++){
		if (a[n][i]){
			path.push_back(i);
			if (path.front() == path.back()){
				cycles.push_back(path);
			}
			else if (!mark[i]){
				mark[i] = true;
				solve(i);
				mark[i] = false;
			}
			path.pop_back();			
		}
	} 
}

inline int f(char c){
	if (c>='a' && c<='z') return 26+c-'a';
	return c-'A';
}

inline char g(int n){
	if (n<26) return (char)('A'+n);
	return (char)('a'+n-26);
}

bool comp(vector<int> &a, vector<int> &b){
	return a.size() < b.size();
}

bool cycle_equal(vector<int> &path1, vector<int> &path2){
	bool mark1[maxn], mark2[maxn];
	memset(mark1,false,sizeof(mark1));
	memset(mark2,false,sizeof(mark2));
	for (int i=0;i<path1.size();i++) mark1[path1[i]] = true;
	for (int i=0;i<path2.size();i++) mark2[path2[i]] = true;
	for (int i=0;i<maxn;i++) if (mark1[i] != mark2[i]) return false;
	return true;
}

int main(){

	cin >> t;
	while (t--){
		cin >> n >> m >> e;
		memset(a,0,sizeof(a));
		while(e--){
			char c1,c2,s[100];
			scanf("%s", s);
            sscanf(s, "%c-%c", &c1, &c2);
			x = f(c1), y = f(c2);
			a[x][y] = 1;

		}
		// print all cycles in a[i][j] in increasing length order
		memset(mark,false,sizeof(mark));
		cycles.clear();
		path.clear();
		for (int i=0;i<maxn/2;i++){
			mark[i] = true;
			path.push_back(i);
			solve(i);
			path.pop_back();
			mark[i] = false;
		}
		// refine cycles: a-b-c-b to b-c-b
		for (int i=0;i<cycles.size();i++){
			while (cycles[i].front() != cycles[i].back()) cycles[i].erase(cycles[i].begin());
		}
		// refine again
		for (int i=0;i<cycles.size();i++){
			bool flag[maxn]; memset(flag,false,sizeof(flag));
			for (int j=0;j<cycles[i].size();j++) flag[cycles[i][j]] = true;
			int first = -1;
			for (int j=0;j<maxn && first==-1;j++) if (flag[j]) first = j;
			if (cycles[i].front() != first){
				cycles[i].erase(cycles[i].begin());
				int temp = cycles[i].front();
				cycles[i].push_back(temp);
			}
		}
		// sort cycles!
		sort(cycles.begin(),cycles.end(),comp);				
		if (cycles.size()==0) cout << "NO" << endl;
		else {
			// chech duplicates
			// cout << "size: " << cycles.size() << endl;
			for (int i=0;i<cycles.size();i++){
				for (int j=i+1;j<cycles.size();j++){
					if (cycle_equal(cycles[i],cycles[j])){
						cycles.erase(cycles.begin()+j);
						j--;
					}
				}				
			}
			// cout << "size: " << cycles.size() << endl;
			cout << "YES" << endl;		
			// method1
			// for (int i=0;i<cycles.size();i++){ 
			// 	for (int j=0;j<cycles[i].size();j++){
			// 		cout << g(cycles[i][j]) << (j!=cycles[i].size()-1?"-":"");
			// 	}
			// 	cout << endl;
			// }
			// method2
			set<string> ans[200];
			for (int i=0;i<cycles.size();i++){
				string s="";
				for (int j=0;j<cycles[i].size();j++){
					s += g(cycles[i][j]);
					if (j!=cycles[i].size()-1) s += "-";
				}
				ans[s.size()].insert(s);
			}
			for (int i=0;i<200;i++)
			for (set<string>::iterator it=ans[i].begin();it!=ans[i].end();it++) cout << *it << endl;
		}
		if (t) cout << endl;
	}

	return 0;
}