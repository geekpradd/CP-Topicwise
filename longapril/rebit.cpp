#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;

int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp % 2)
		return (res*base)%MOD;
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}
void get_prob(int l, int r, int counter[], string &s, int closing_index[]){
	if (s[l] != '(') {
		for (int i = 0; i<4; ++i)
			counter[i] = 1;
		return;
	}
	int operator_index;
	if (s[l+1]!='('){
		operator_index = l+2;
	}
	else {
		operator_index = closing_index[l+1] + 1;
	}

	int counter_l[4];
	int counter_r[4];
	for (int i=0; i<4; ++i)
		counter_l[i] = counter_r[i] = 0;
	get_prob(l+1, operator_index-1, counter_l, s, closing_index);
	get_prob(operator_index+1, r-1, counter_r, s, closing_index);
 
	if (s[operator_index]=='&'){
		counter[0] = (counter_l[0]*counter_r[0])%MOD;
		for (int j=1; j<4; ++j)
			counter[0] = (counter[0] + (counter_l[0]*counter_r[j])%MOD + (counter_l[j]*counter_r[0])%MOD)%MOD;
		counter[0] = (counter[0] + (counter_l[2]*counter_r[3])%MOD + (counter_l[3]*counter_r[2])%MOD); 
		counter[1] = (counter_l[1]*counter_r[1])%MOD;
		counter[2] = ((counter_l[1]*counter_r[2])%MOD + (counter_l[2]*counter_r[2])%MOD + (counter_l[2]*counter_r[1])%MOD)%MOD;
		counter[3] = ((counter_l[1]*counter_r[3])%MOD + (counter_l[3]*counter_r[1])%MOD + (counter_l[3]*counter_r[3])%MOD)%MOD;
	}
	else if (s[operator_index]=='|'){
		counter[1] = ((counter_l[1]*counter_r[1])%MOD + (counter_l[0]*counter_r[1])%MOD + (counter_l[1]*counter_r[0])%MOD)%MOD;
        for (int j=2; j<4; ++j) 
                counter[1] = (counter[1] + (counter_l[1]*counter_r[j])%MOD + (counter_l[j]*counter_r[1])%MOD)%MOD;
        counter[1] = (counter[1] + (counter_l[2]*counter_r[3])%MOD + (counter_l[3]*counter_r[2])%MOD)%MOD; 
        counter[0] = (counter_l[0]*counter_r[0])%MOD;
        counter[2] = ((counter_l[0]*counter_r[2])%MOD + (counter_l[2]*counter_r[2])%MOD + (counter_l[2]*counter_r[0])%MOD)%MOD;
        counter[3] = ((counter_l[0]*counter_r[3])%MOD + (counter_l[3]*counter_r[0])%MOD + (counter_l[3]*counter_r[3])%MOD)%MOD;
	}
	else {
		counter[0] = (counter_l[0]*counter_r[0])%MOD;
        for (int j=1; j<4; ++j) 
                counter[0] = (counter[0] + (counter_l[j]*counter_r[j])%MOD)%MOD;
        counter[1] = ((counter_l[0]*counter_r[1])%MOD + (counter_l[1]*counter_r[0])%MOD + (counter_l[2]*counter_r[3])%MOD + (counter_r[3]*counter_l[2])%MOD)%MOD;
        counter[2] = ((counter_l[2]*counter_r[0])%MOD + (counter_l[0]*counter_r[2])%MOD + (counter_l[3]*counter_r[1])%MOD + (counter_l[1]*counter_r[3])%MOD)%MOD;
        counter[3] = ((counter_l[3]*counter_r[0])%MOD + (counter_l[0]*counter_r[3])%MOD + (counter_l[2]*counter_r[1])%MOD + (counter_l[1]*counter_r[2])%MOD)%MOD;
    }
}

signed main(){
	int t; cin >> t;
	while (t--){
		int counter[4];
		for (int i=0; i<4; ++i)
			counter[i] = 0;
		string l; cin >> l;
		int closing_index[l.size()];
		stack<int> positions;

		int blanks = 0;
		for (int i=0; i<l.size(); ++i){
			if (l[i]=='('){
				positions.push(i);
			}
			else if (l[i]==')'){
				int index = positions.top();
				positions.pop();
				closing_index[index] = i;
			}
			else if (l[i]=='#'){
				blanks++;
			}
		}
		get_prob(0, l.size()-1, counter, l, closing_index);

		int denom = power(4, blanks);
		for (int i=0; i<4; ++i){
			cout << (counter[i]*inverse(denom))%MOD << " "; 
		} 
		cout << endl;
	}
	return 0;
}
