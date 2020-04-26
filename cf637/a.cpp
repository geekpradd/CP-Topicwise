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
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	bool pos = 0;
	for (int i=c-d; i<=c+d; ++i){
		if (i >= n*(a-b) && i<=n*(a+b)){
			pos = 1;
			break;
		}
	}
	if (pos){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
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