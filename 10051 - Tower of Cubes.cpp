// Meysam Aghighi
// Dynamic programming
#include <bits/stdc++.h>
using namespace std;

int f(int n){ // gives the other face
    if (n%2==0) return n+1;
    return n-1;
}

string text[6] = {"front" , "back" , "left" , "right" , "top" , "bottom"};

int main(){
    int n,t=1;
    while (cin >> n && n){
        if (t>1) cout << endl;
        int a[n][6];
        for (int i=0;i<n;i++){
            for (int j=0;j<6;j++) cin >> a[i][j];
        }


        int ans = 1;
        int sol[2];
        sol[0] = n-1;
        sol[1] = 0;

        int best[n][6];
        int next[n][6][2];
        for (int i=0;i<n;i++) for (int j=0;j<6;j++) best[i][j] = 1;

        for (int i=1;i<n;i++){
            for (int ik=0;ik<6;ik++){
                for (int j=i-1;j>=0;j--){
                    for (int jk=0;jk<6;jk++){
                        if (a[i][ik] == a[j][f(jk)]){
                            if (best[i][ik] < 1 + best[j][jk]){ // check if we can improve the highest tower with base [i][ik]
                                best[i][ik] = best[j][jk] + 1;
                                next[i][ik][0] = j;
                                next[i][ik][1] = jk;
                                // update global best
                                if (best[i][ik] > ans){
				                            ans = best[i][ik];
                                    sol[0] = i;
                                    sol[1] = ik;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << t++ << endl;
        cout << ans << endl;
        // build back the tower
        stack<pair<int,int> > s;
        pair<int,int> cur(sol[0],sol[1]);
				s.push(cur);
				for (int i=0;i<ans-1;i++){
            cur = make_pair(next[cur.first][cur.second][0] , next[cur.first][cur.second][1]);
            s.push(cur);
        }
        while (!s.empty()){
            int a = s.top().first, b = s.top().second;
            s.pop();
            cout << a+1 << " ";
            cout << text[b] << endl;
        }



    }


    return 0;
}
