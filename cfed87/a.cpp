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
	int a,b,c, d;
	cin >> a >> b >> c >> d;
	if (a<=b){
		cout << b << endl;
	}
	else {
		int rem = a - b;
		int cyc = c - d;
		// cout << "Rem " << rem << endl;
		// cout << cyc << endl;
		if (cyc <= 0){
			cout << -1 << endl;
		}
		else {
			int ccs;
			if (rem%cyc == 0){
				ccs = rem/cyc;
			}
			else {
				ccs = (rem/cyc) + 1;
			}
			int tot = c*ccs + b;
			cout << tot << endl;
		}
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