#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#include <cmath>
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
	int a, b, q; cin >> a >> b >> q;
	vector<int> rs;
	for (int r=0; r<a*b; ++r){
		int f = (r%a)%b; int s = (r%b)%a;
		if (f != s)
			rs.pb(r);
	}
	// for (int rem: rs){
	// 	cout << rem << endl;
	// }
	// cout << (25/24) << endl;
	while (q--){
		int l, r; cin >> l >> r;
		int up = r%(a*b);
		int low = l%(a*b);
		int delta = (r-up)/(a*b) - (l-low)/(a*b);
		int c = delta*(rs.size());
		int low_v = rs.end() - lower_bound(rs.begin(), rs.end(), low);
		int up_v = rs.end() - upper_bound(rs.begin(), rs.end(), up);
		c += (low_v - up_v);
		cout << c << " ";
	}
	cout << endl;
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