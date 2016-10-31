#include<bits/stdc++.h>
using namespace std;

void print (int a[][7]){
	for (int i=0;i<7;i++){
		for (int j=0;j<7;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

}


void play(int a[][7]){
	// print(a);
	int candid[7][7]; // 0 1 2 3 up left right down
	memset(candid,-1,sizeof(candid));
	for (int i=0;i<7;i++){
		for (int j=0;j<7;j++){
			if (i>=2 && a[i][j]==-1 && a[i-1][j]==1 && a[i-2][j]==1 && candid[i][j]<0) candid[i][j]=0; // up
			if (j>=2 && a[i][j]==-1 && a[i][j-1]==1 && a[i][j-2]==1 && candid[i][j]<1) candid[i][j]=1; // left
			if (j<=4 && a[i][j]==-1 && a[i][j+1]==1 && a[i][j+2]==1 && candid[i][j]<2) candid[i][j]=2; // right		
			if (i<=4 && a[i][j]==-1 && a[i+1][j]==1 && a[i+2][j]==1 && candid[i][j]<3) candid[i][j]=3; // down
		}
	}
	// find best move
	int last_i = -1, last_j = -1;
	for (int i=0;i<7;i++) for (int j=0;j<7;j++) if (candid[i][j] != -1) last_i=i, last_j=j;
	// if there is a move, move and call play again,
	int i=last_i, j=last_j;
	if (i != -1){
		switch(candid[i][j]){
			case 0: a[i][j]=1, a[i-1][j]=-1, a[i-2][j]=-1; break;
			case 1: a[i][j]=1, a[i][j-1]=-1, a[i][j-2]=-1; break;
			case 2: a[i][j]=1, a[i][j+1]=-1, a[i][j+2]=-1; break;
			case 3: a[i][j]=1, a[i+1][j]=-1, a[i+2][j]=-1; break;
		}
		play(a);
	}
	// otherwise return
}

int main(){

	int b[7][7], v[7][7];
	memset(b,-1,sizeof(b));
	memset(v,0,sizeof(v));
	int ii=0,jj=0; for (int i=ii;i<ii+2;i++) for (int j=jj;j<jj+2;j++) b[i][j] = 0;
	ii=0,jj=5; for (int i=ii;i<ii+2;i++) for (int j=jj;j<jj+2;j++) b[i][j] = 0;
	ii=5,jj=0; for (int i=ii;i<ii+2;i++) for (int j=jj;j<jj+2;j++) b[i][j] = 0;
	ii=5,jj=5; for (int i=ii;i<ii+2;i++) for (int j=jj;j<jj+2;j++) b[i][j] = 0;
	
	int value = 1;
	for (int i=0;i<7;i++)
		for (int j=0;j<7;j++)
			if (b[i][j] != 0) v[i][j] = value++;

	// print(v,7,7);

	cout << "HI Q OUTPUT" << endl;

	int t; cin >> t;
	while (t--){
		vector<int> a;
		int n;
		while (cin >> n && n!=0) a.push_back(n);
		int board[7][7];
		for (int i=0;i<7;i++) for (int j=0;j<7;j++) board[i][j] = b[i][j];
		for (int k=0;k<a.size();k++){
			for (int i=0;i<7;i++){
				for (int j=0;j<7;j++){
					if (a[k] == v[i][j]) board[i][j] = 1;
				}
			}
		}
		// print(board);
		play(board);
		// print(board);
		int sum = 0;
		for (int i=0;i<7;i++) for (int j=0;j<7;j++) if (board[i][j]==1) sum+=v[i][j];
		cout << sum << endl;
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}