#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
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

int ans(vector<int> &a, int n, int bit){
	if (bit<=0)
		return 0;
	int itr = 1 << (bit-1);
	vector<int> activ, nonactiv;
	for (int i=0; i<n; ++i){
		if (itr & a[i])
			activ.pb(a[i]);
		else
			nonactiv.pb(a[i]);
	}
	if (activ.size()==0)
		return ans(nonactiv, nonactiv.size(), bit-1);
	else if (nonactiv.size()==0)
		return ans(activ, activ.size(), bit-1);
	else
		return itr + min(ans(nonactiv, nonactiv.size(), bit-1), ans(activ, activ.size(), bit-1));

}

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	cout << ans(a, n, 30) << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}