// Meysam Aghighi
// Comments: basically no ideas, just had to do it straightforward.
#include<bits/stdc++.h>
using namespace std;

string board[8];
char c;
bool can_move;

bool fit(int i, int j){
	return i>=0 && i<8 && j>=0 && j<8;
}

void print(int i, int j, int ii, int jj){
	can_move = true;
	char c1='A'+i, c2='1'+j, c3='A'+ii, c4='1'+jj;
	cout << c1 << c2 << "-" << c3 << c4 << endl;
}

void moves(int i, int j){
	// print moves and set can_move
	int hor = 0, ver = 0, dia1 = 0, dia2 = 0;
	for (int k=0;k<8;k++){
		if (board[i][k] != '.') hor++;
		if (board[k][j] != '.') ver++;
		if (fit(i+k,j+k) && board[i+k][j+k] != '.') dia1++;
		if (fit(i-k-1,j-k-1) && board[i-k-1][j-k-1] != '.') dia1++;
		if (fit(i-k,j+k) && board[i-k][j+k] != '.') dia2++;
		if (fit(i+k+1,j-k-1) && board[i+k+1][j-k-1] != '.') dia2++;		
	}
	for (int ii=0;ii<8;ii++){
		for (int jj=0;jj<8;jj++){
			if (i == ii && j == jj) continue;
			bool can = true;
			// horizontal move
			if (ii == i && abs(jj-j) == hor){				
				if (j < jj){
					if (board[i][jj] == c) can = false;
					for (int k=j+1;k<jj;k++) if (board[i][k] != c && board[i][k] != '.') can = false;
					if (can) print(i,j,i,jj);
				}
				else {
					if (board[i][jj] == c) can = false;
					for (int k=jj+1;k<j;k++) if (board[i][k] != c && board[i][k] != '.') can = false;
					if (can) print(i,j,i,jj);
				}	
			}
			// vertical move
			if (jj == j && abs(ii-i) == ver){
				if (i < ii){
					if (board[ii][j] == c) can = false;
					for (int k=i+1;k<ii;k++) if (board[k][j] != c && board[k][j] != '.') can = false;
					if (can) print(i,j,ii,j);
				}
				else {
					if (board[ii][j] == c) can = false;
					for (int k=ii+1;k<i;k++) if (board[k][j] != c && board[k][j] != '.') can = false;
					if (can) print(i,j,ii,j);
				}
			}
			// dia1 move
			if (jj-j == ii-i && abs(jj-j) == dia1){
				if (i < ii){
					if (board[ii][jj] == c) can = false;
					for (int k=1;k<ii-i;k++) if (board[i+k][j+k] != c && board[i+k][j+k] != '.') can = false;
					if (can) print(i,j,ii,jj);
				}
				else {
					if (board[ii][jj] == c) can = false;
					for (int k=1;k<i-ii;k++) if (board[ii+k][jj+k] != c && board[ii+k][jj+k] != '.') can = false;
					if (can) print(i,j,ii,jj);
				}
			}
			// dia2 move
			if (jj-j == i-ii && abs(jj-j) == dia2){
				if (i < ii){
					if (board[ii][jj] == c) can = false;
					for (int k=1;k<ii-i;k++) if (board[i+k][j-k] !=c && board[i+k][j-k] != '.') can = false;
					if (can) print (i,j,ii,jj);
				}
				else {
					if (board[ii][jj] == c) can = false;
					for (int k=1;k<i-ii;k++) if (board[i-k][j+k] !=c && board[i-k][j+k] != '.') can = false;
					if (can) print (i,j,ii,jj);
				}
			}
		}
	}
}

int main(){
	bool first = true;
	while (cin >> board[0]){
		if (!first) cout << endl; first = false;
		for (int i=1;i<8;i++) cin >> board[i];
		cin >> c;
		can_move = false;
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (board[i][j]==c) moves(i,j);
			}
		}
		if (!can_move) cout << "No moves are possible" << endl;
	}
	return 0;
}



