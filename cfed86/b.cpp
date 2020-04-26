#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
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

void solve(){
	string t; cin >> t;
	char b = t[0];
	bool same = 1;
	for (int i=1; i<t.size(); ++i){
		if (t[i]!=b){
			same = 0; break;
		}
	}
	if (same){
		cout << t << endl; return;
	}
	else {
		char s = t[0];
		cout << s;
		for (int i=1; i<t.size(); ++i){
			if (t[i]==s){
				int val = t[i] - '0';
				// cout << "i " << i << " val " << val << endl;
				int other = 1 - val;
				char z = (other + '0');
				cout << z;
			}
			cout << t[i];
			s = t[i];
		}
		cout << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}