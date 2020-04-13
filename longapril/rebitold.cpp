#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
vector<int> non_bracks;
vector<int> closing_bracks;
vector<int> operators;
struct ii {
	int first, second;
};

ii mp(int f, int s){
	ii t = {f, s};
	return t;
}

ii normalise(ii inp){
	int gcd = __gcd(inp.first, inp.second);
	if (gcd==0)
		gcd = 1;
	return mp(inp.first/gcd, inp.second/gcd);
}

ii operator*(ii l, ii r){
    return normalise(mp(l.first * r.first, l.second*r.second));
}
ii operator+(ii l,  ii r){
	return normalise(mp(l.first*r.second + l.second*r.first, l.second*r.second));
}
void operator*=(ii &l, ii r){
    l = normalise(l*r);
}
void operator+=(ii &l,  ii r){
	l = normalise(l + r);
}

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
void get_prob(int l, int r, ii probs[], string &s){
	if (s[l] != '(') {
		for (int i = 0; i<4; ++i)
			probs[i].second *= 4;
		return;
	}
	auto first_operand_itr = lower_bound(non_bracks.begin(), non_bracks.end(), l);
	int no_of_bracks = *(first_operand_itr) - l - 1;
	int operator_index;
	if (no_of_bracks == 0)
		operator_index = l+2;
	else {
		auto nearest_closing = lower_bound(closing_bracks.begin(), closing_bracks.end(), l);
		for (int j=0; j<no_of_bracks-1; ++j) nearest_closing++;
		operator_index = *(nearest_closing) + 1;
	}
	ii probs_l[4];
	ii probs_r[4];
	for (int i=0; i<4; ++i)
		probs_l[i] = probs_r[i] = mp(1, 1);
	// cout << "operator ind is " << operator_index << endl;
	get_prob(l+1, operator_index-1, probs_l, s);
	get_prob(operator_index+1, r-1, probs_r, s);
	// for (int i=0; i<4; ++i){
	// 	cout << "probs_l " << i << " is " << probs_l[i].first << " " << probs_l[i].second << endl;
	// }

	if (s[operator_index]=='&'){
		ii temp = probs_l[0]*probs_r[0];
		for (int j=1; j<4; ++j)
			temp += probs_l[0]*probs_r[j] + probs_l[j]*probs_r[0];
		temp += probs_l[2]*probs_r[3] + probs_l[3]*probs_r[2]; 
		// cout << " temp is  " << temp.first << " " << temp.second << endl;

		probs[0] *= temp;
		// cout << "probs[0] " << probs[0].first << " and " << probs[0].second << endl;
		probs[1] *= probs_l[1]*probs_r[1];
		temp = probs_l[1]*probs_r[2] + probs_l[2]*probs_r[2] + probs_l[2]*probs_r[1];
		probs[2] *= temp;
		temp = probs_l[1]*probs_r[3] + probs_l[3]*probs_r[1] + probs_l[3]*probs_r[3];
		probs[3] *= temp;
	}
	else if (s[operator_index]=='|'){
		ii temp = probs_l[1]*probs_r[1] + probs_l[0]*probs_r[1] + probs_l[1]*probs_r[0];
        for (int j=2; j<4; ++j) 
                temp += probs_l[1]*probs_r[j] + probs_l[j]*probs_r[1];
        temp += probs_l[2]*probs_r[3] + probs_l[3]*probs_r[2]; probs[1] *= temp;
        probs[0] *= probs_l[0]*probs_r[0];
        temp = probs_l[0]*probs_r[2] + probs_l[2]*probs_r[2] + probs_l[2]*probs_r[0];
        probs[2] *= temp;
        temp = probs_l[0]*probs_r[3] + probs_l[3]*probs_r[0] + probs_l[3]*probs_r[3];
        probs[3] *= temp;
	}
	else {
		// cout << " got xor " << endl;
		// for (int i=0; i<4; ++i){
		// 	cout << "probs_l[" << i << "] =  " << probs_l[i].first << "  " << probs_l[i].second << endl;
		// 	cout << "probs_r[" << i << "] =  " << probs_r[i].first << "  " << probs_r[i].second << endl;
		// }
		ii temp = probs_l[0]*probs_r[0];
        for (int j=1; j<4; ++j) 
                temp += probs_l[j]*probs_r[j];
	// cout << " temp is " << temp.first << " " << temp.second << endl;
        probs[0] *= temp;
        probs[1] = probs[1]*(probs_l[0]*probs_r[1] + probs_l[1]*probs_r[0] + probs_l[2]*probs_r[3] + probs_r[3]*probs_l[2]);
        probs[2] = probs[2]*(probs_l[2]*probs_r[0] + probs_l[0]*probs_r[2] + probs_l[3]*probs_r[1] + probs_l[1]*probs_r[3]);
        probs[3] = probs[3]*(probs_l[3]*probs_r[0] + probs_l[0]*probs_r[3] + probs_l[2]*probs_r[1] + probs_l[1]*probs_r[2]);
        }
}

signed main(){
	int t; cin >> t;
	while (t--){
		ii probs[4];
		for (int i=0; i<4; ++i)
			probs[i] = mp(1, 1);
		string l; cin >> l;
		non_bracks.clear();
		closing_bracks.clear();
		operators.clear();

		for (int i=0; i<l.size(); ++i){
			if (l[i]==')')
				closing_bracks.push_back(i);
			else if (l[i] != '('){
				if (l[i] == '&' || l[i] == '|' || l[i] == '^')
					operators.push_back(i);
				else
					non_bracks.push_back(i);
			}
		}
		get_prob(0, l.size()-1, probs, l);
		for (int i=0; i<4; ++i){
			cout << (probs[i].first*inverse(probs[i].second))%MOD << " ";
		}
		cout << endl;
	}
	return 0;
}
