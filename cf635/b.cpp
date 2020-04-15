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
	int x, n, m; 
	cin >> x >> n >> m;
	while (n>0){
		int y = x/2 + 10;
		if (y < x){
			x = y;
		}
		n--;
	}
	while (m > 0){
		x = x - 10;
		m--;
	}
	if (x<=0){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
	}
}