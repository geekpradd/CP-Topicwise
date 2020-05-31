#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 10000000000
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
	int count = 0;
	int a[n]; 
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	for (int i=0; i<n; ++i){
		int mi = E9;
		int ma = -E9;
		for (int j=i; j<n; ++j){
			ma = max(ma, a[j]);
			mi = min(mi, a[j]);
			if (abs(a[j]-a[i]) == ma - mi){
				count++;
				cout << "got at " << j << "  and " << i << endl;
			}
		}
	}

	cout << count << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}