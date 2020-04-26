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
	int index[n+1];
	int a[n+1];
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		index[a[i]] = i;
	}
	int cur_r = n;
	bool pos = 1; 
	for (int i=1; i<=n; ++i){
		int j = index[i];
		for (int k=j; k<=cur_r; ++k){
			if (a[k] != i) {
				pos = 0; break;
			}
			if (k!=cur_r)
				i++;
		}
		cur_r = j - 1;
	}
	cout << (pos ? "Yes" : "No") << endl;
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