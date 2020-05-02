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
vector<int> vals(100001);
void solve(){
	int n; cin >> n;
	if (n==2){
		cout << 1 << endl;
		cout << 0 << endl;
		return;
	}
	if (n==3){
		cout << 1 << endl;
		cout << 1 << endl;
		return;
	}
	int req = log2(n) + 1;
	int ans = req - 1;
	int up = (1 << req ) -  1;
	int low = (1 << (ans)) - 1;
	int g_1 = n - low;
	int max_c = 1 << (req - 3);
	int g_2 = g_1/2;
	vector<int> vals;
	int va;
	for (int i=0; i<=(req-3); ++i){
		va = 1 << i;
		vals.pb(va);
	}
	vals.pb(va);
	vals.pb(va);
	if (g_2 > max_c){
		vals[vals.size()-2] += max_c;
		vals[vals.size()-1] += max_c;
		int diff = g_1 - 2*max_c;
		vals[vals.size()-1] += diff;
	}
	else {
		vals[vals.size()-2] += g_2;
		vals[vals.size()-1] += g_2;
		if (g_1%2)
			vals[vals.size()-1]++;
	}
	cout << ans << endl;
	for (int i=0; i<vals.size()-1; ++i){
		cout << vals[i+1] - vals[i] << " ";
	}
	cout << endl;
 
}	


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	vals[0] = 1;
	for (int i=1; i<=100000; ++i){
		vals[i] = vals[i-1] + (i+1);
	}
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}