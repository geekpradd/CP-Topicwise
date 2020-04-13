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

void solve(){
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int b[n];
	int j = 0;
	int back = 1;
	for (int i=n-1; i>=0; --i){
		if (back){
			b[i] = a[n-1-j];
			back = 0;
		}
		else {
			b[i] = a[j];
			j++;
			back = 1;
		}
	}
	for (int i=0; i<n; ++i)
		cout << b[i] << " ";
	cout << endl;
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