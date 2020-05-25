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
	int n; cin >> n;
	if (n == 1){
		cout << 0 << endl;
		return;
	}
	int digs = log2(n) + 1;
	int pooww = 1LL << (digs - 1);
	if (pooww == n){
		cout << -1 << endl;
	}
	else {
		int ans = 0;
		for (int c = 1; c <= pooww; c = c << 1){
			int md = c << 1;
			int left = n/md;
			int tot = left + 1;
			if (left*md + c > n){
				tot--;
			}
			// cout << "md " << md << endl;
			// cout << "tot " << tot << endl;
			// cout << "c " << c << endl;
			ans += c*tot;
		}
		cout << ans - 1 << endl;
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