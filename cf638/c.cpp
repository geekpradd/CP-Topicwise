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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	sort(s.begin(), s.end());
	char cur = s[0];
	bool same = 1;
	for (int i=0; i<k; ++i){
		if (s[i]!=cur){
			same = 0; break;
		}
	}
	if (!same || k == n){
		cout << s[k-1] << endl;
	}
	else if (k!=n) {
		cout << s[0];
		char cur  = s[k];
		bool same = 1;
		for (int i=k; i<n; ++i){
			if (s[i]!=cur){
				same = 0; break;
			}
		}
		if (!same){
			for (int i=k; i<n;++i)
				cout << s[i];
			cout << endl;
		}
		else {
			int cyc;
			int rem = n - k;
			if (rem % k == 0)
				cyc = rem/k;
			else {
				cyc = rem/k + 1;
			}
			for (int i=0; i<cyc; ++i)
				cout << cur;
			cout << endl;
		}
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