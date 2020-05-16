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
	int res[n];
	for (int i=0; i<n; ++i){
		cin >> res[i];
		res[i] = (i + res[i])%n;
		if (res[i]<0) res[i] += n;
	}
	sort(res, res+n);
	bool tr = 1;
	for (int i=0; i<n; ++i){
		if (res[i]!=i)
			tr = 0;
	}
	cout << (tr ? "YES" :"NO") << endl;
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