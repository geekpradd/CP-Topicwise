#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 998244353
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
	int upper = max(n, k);
	int fact[upper+1];
	fact[0] = 1; 
	fact[1] = 1;
	for (int i=2; i<=n; ++i){
		fact[i] = (i*fact[i-1])%MOD;
	}
	int val = 0;
	int common = inverse(fact[k-1]);
	for (int i=1;i<=n; ++i){
		int num = (n/i);
		num = num - 1;
		if (num < k-1) break;
		int nume = fact[num];
		int other = inverse(fact[num-k+1]);
		int value = (nume*common)%MOD;
		value = (value*other)%MOD;
		val = (val + value)%MOD;
	}

	cout << val << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	solve();
	return 0;
}