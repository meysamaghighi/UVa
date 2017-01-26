// Meysam Aghighi

#include <bits/stdc++.h>
using namespace std;

int f(int n){
    n *= n;
    n /= 100;
    if (n>9999){
        int t = n/10000;
        t *= 10000;
        n -= t;
    }
    return n;
}

int main(){
    int n;
    while (cin >> n && n){
        vector<bool> mark(10000,false);
        int sum = 0;
        while (!mark[n]){
            mark[n] = true;
            sum++;
            n = f(n);
        }
        cout << sum << endl;
    }
    return 0;
}