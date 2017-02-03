// Meysam Aghighi

#include <bits/stdc++.h>
using namespace std;

void solve(int * a, int n, int base){
    if (n == 1){
        cout << "0\n";
        return;
    }
    int max_loc = 0, maxx = -1;
    for (int i=0;i<n;i++) if (a[i]>maxx) max_loc = i, maxx = a[i];
    max_loc++;
    if (max_loc == n) solve(a,n-1,base+1);
    else if (max_loc == 1){
        cout << base+1 << " ";
        for (int i=0;i<n-i-1;i++) swap(a[i],a[n-i-1]);
        solve(a,n-1,base+1);
    }
    else { // 2 <= max_loc <= n-1
        cout << n-max_loc+1+base << " ";
        for (int i=0;i<max_loc-i-1;i++) swap(a[i],a[max_loc-i-1]);
        cout << base+1 << " ";
        for (int i=0;i<n-i-1;i++) swap(a[i],a[n-i-1]);
        solve(a,n-1,base+1);
    }
}


int main(){
    string s;
    while (getline(cin,s)){
        cout << s << endl;
        stringstream ss(s);
        vector<int> b;
        int x;
        while (ss >> x) b.push_back(x);
        int n = b.size();
        int a[n];
        for (int i=0;i<n;i++) a[i] = b[i];
        solve(a,n,0);
    }

    return 0;
}
