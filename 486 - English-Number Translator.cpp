// Meysam Aghighi
// Comments: ez
#include <bits/stdc++.h>
using namespace std;

string nums[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
					"fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

string tens[7] = {"thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int number(string s){
	for (int i=0;i<21;i++) if (s == nums[i]) return i;
	for (int i=0;i<7;i++) if (s == tens[i]) return 10*(i+3);
	return -1;	
}

int main(){
	string s;
	while (getline(cin,s)){
		stringstream ss(s);
		long long n = 0, b = 1;
		bool flag = true;
		stack<string> st;
		while (ss >> s) st.push(s);
		while (!st.empty()){
			s = st.top(); st.pop();
			if (s == "negative") n = -n;
			else if (s == "hundred") b *= 100, flag = false;
			else if (s == "thousand") b = flag?1000:b*1000, flag = false;
			else if (s == "million") b = flag?1000000:b*1000000, flag = false;
			else if (number(s) >= 0) n += number(s)*b, flag = true;
		}
		cout << n << endl;
	}
	
	return 0;
}