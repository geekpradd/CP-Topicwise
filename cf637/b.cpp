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
	int a[n+1];
	int pref[n+1]; pref[0] = 0;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=n; ++i){
		pref[i] = pref[i-1];
		if (i == 1 || i == n) continue;
		if (a[i] > a[i-1] && a[i] > a[i+1]) pref[i] += 1;
	}
	int p = 0;
	int max_l = 1;
	for (int l = 1; l<=n-k+1; ++l){
		if (pref[l+k-2] - pref[l] > p){
			p = pref[l+k-2] - pref[l];
			max_l = l;
		}
	}
	cout << p+1 << " " << max_l << endl;
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