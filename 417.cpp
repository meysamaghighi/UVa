// Meysam Aghighi
// Comments: not the best way to do it ofc... but it worked anyway! A better implementation would be doing it recursively.
#include<bits/stdc++.h>
using namespace std;

int main(){
	map<string,int> dic;
	int top = 1;
	string s;
	for (int i=0;i<26;i++){
		s = 'a'+i;
		dic[s] = top++;
	}
	s = string(2,'a');
	for (int i=0;i<26;i++){
		for (int j=i+1;j<26;j++){
			s[0] = 'a'+i, s[1] = 'a'+j;
			dic[s] = top++;
		}
	}
	s = string(3,'a');
	for (int i1=0;i1<26;i1++){
		for (int i2=i1+1;i2<26;i2++){
			for (int i3=i2+1;i3<26;i3++){
				s[0] = 'a'+i1, s[1] = 'a'+i2, s[2] = 'a'+i3;
				dic[s] = top++;
			}
		}
	}
	s = string(4,'a');
	for (int i1=0;i1<26;i1++)
		for (int i2=i1+1;i2<26;i2++)
			for (int i3=i2+1;i3<26;i3++)
				for (int i4=i3+1;i4<26;i4++){
					s[0] = 'a'+i1, s[1] = 'a'+i2, s[2] = 'a'+i3, s[3] = 'a'+i4;
					dic[s] = top++;
				}
	s = string(5,'a');
	for (int i1=0;i1<26;i1++)
		for (int i2=i1+1;i2<26;i2++)
			for (int i3=i2+1;i3<26;i3++)
				for (int i4=i3+1;i4<26;i4++)
					for (int i5=i4+1;i5<26;i5++){
						s[0] = 'a'+i1, s[1] = 'a'+i2, s[2] = 'a'+i3, s[3] = 'a'+i4, s[4] = 'a'+i5;
						// cout << s << endl;
						dic[s] = top++;
					}

	while (cin >> s){
		if (dic.count(s)) cout << dic[s] << endl;
		else cout << "0\n";
	}
	

	return 0;
}



