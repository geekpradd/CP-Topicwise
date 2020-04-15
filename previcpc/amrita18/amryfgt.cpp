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
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];
	int low, up; cin >> low >> up;
	int lcm = a[0];

	bool pos = 1;
	for (int i=1; i<n; ++i){
		int gc = __gcd(lcm, a[i]);
		double log_c = log10(lcm) + log10(a[i]) - log10(gc);
		if (log_c > 18){
			pos = 0;
			break;
		}
		lcm = (lcm*a[i])/gc;
	}
	int count = 0;
	if (pos){
		count = (up)/lcm - (low-1)/lcm;
	}
	count = (up-low+1) - count;

	// cout << "lcm " << lcm << endl;
	cout << count << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	while (t--){
		solve();
	}
}