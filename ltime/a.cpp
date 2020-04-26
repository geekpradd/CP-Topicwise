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
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];

	vector<int> freq(n+2, 0);
	for (int i=0;i<n;++i){
		if (a[i]<=n)
			freq[a[i]]++;
	}
	int acum = 1;
	int tot = 0;
	int cum = 0;
	int c = 0;
	for (int i=1; i<=n+1; ++i){
		int cur = freq[i];
		cum += cur;
		// cout << "Cur " << cur << " for i " << i << endl;
		// cout << "acum " << acum << endl;
		

		tot = ((acum*((power(2, n-cum)%MOD)*(i))%MOD)%MOD + tot)%MOD;
		// cout << "tot " << tot << endl;
		int z = (power(2, cur) + MOD - 1)%MOD;
		if (z < 0) z +=MOD;
		acum = (acum*(z))%MOD;
		if (cur == 0) break;
	}
	if (tot < 0) tot += MOD;
	cout << tot << endl;
	
	// cout << power(2, 565) - 1 << endl;
		
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}	