// Meysam Aghighi
// The idea is to simulate the operations of checking every reachable state with BFS shortest path.
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int sol[MAX];
bool mark[MAX];

int main(){
    int L, U, R, t = 1;
    while (cin >> L >> U >> R && (L || U || R)) {
        int steps[R];
        for (int i = 0; i < R; i++)
            cin >> steps[i];
        memset(sol, -1, sizeof(sol));
        memset(mark, false, sizeof(mark));

        list<int> s; // change to bfs
        sol[L] = 0;
        s.push_back(L);
        mark[L] = true;

        while (!s.empty()) {
            int top = s.front();
            s.pop_front();
            for (int i = 0; i < R; i++) {
                int cur = (top + steps[i]) % MAX;
                if (!mark[cur]){
                    sol[cur] = sol[top] + 1;
                    s.push_back(cur);
                    mark[cur] = true;
                }
            }
        }

        cout << "Case " << t++ << ": ";
        if (sol[U] == -1) cout << "Permanently Locked" << endl;
        else cout << sol[U] << endl;
    }

    return 0;
}
