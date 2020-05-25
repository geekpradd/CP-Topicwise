#include <bits/stdc++.h>
#include <cmath>
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
	long double pp = 3.14159265358979;
	long double angle = pp/(2*n);
	long double aa = 2*angle;
	long double ab = 3*pp/4 - aa;
	long double den = sin(angle);
	long double num = sin(ab);
	long double fin = num/den;
	cout << fixed;
	cout << setprecision(9) << fin << endl;
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