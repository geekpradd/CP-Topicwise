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
	vector<int> count(101, 0);
	vector<int> dist;
	int dis = 0;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
		count[a[i]]++;
		if (count[a[i]]==1) {
			dis++;
			dist.pb(a[i]);
		}
	}
	if (dis > k){
		cout << -1 << endl;
	}
	else{
		int cycles = n;
		int m = cycles*k;
		cout << m << endl;
		for (int i=0; i<cycles; ++i){
			for (int x: dist)
				cout << x << " ";
			for (int i=0; i<k-dis; ++i){
				cout << dist[0] << " ";
			}
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