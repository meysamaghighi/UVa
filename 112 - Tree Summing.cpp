// Meysam Aghighi

#include <bits/stdc++.h>
using namespace std;

int count_par (string s){
    int left = 0, right = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;
    }
    return left-right;
}

string remove_spaces(string s){
    string ss;
    for (int i=0;i<s.size();i++) if (s[i]!=' ') ss.push_back(s[i]);
    return ss;
}

int main(){
    int n;
    while (cin >> n){
        string s,t;
        int count = 0;
        while (getline(cin,t)){
            s.append(t);
            count += count_par(t);
            if (count == 0) break;
        }
        s = remove_spaces(s);
        // dfs part - on the string directly
        bool ans = false;
        stack<int> st;
        long long sum = 0;
        int open = 0, pair = 0; // open: left par, close: right par, pair: to check leaves
        for (int i=0;i<s.size();i++){
            if (s[i] == '(') open++;
            else if (s[i] == ')'){                
                if (open > st.size()){
                    pair++;
                    if (pair == 2){ // leaf detected
                        pair = 0;
                        if (sum == n) ans = true;
                    }
                }
                else { // leaf ended, one step go high
                    sum -= st.top();
                    st.pop();
                    pair = 0;
                }
                open--;
            }
            else { // push number, pain in the ass with this implementation, because of 2 and more digit numbers
                pair = 0;
                string t;
                t += s[i++];
                while (isdigit(s[i])) t+=s[i++];
                i--;
                int temp = stoi(t,nullptr,10);                
                st.push(temp);
                sum += temp;                
            }
        }
        if (ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }   
    return 0;
}