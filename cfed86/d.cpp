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
	int n, k; cin >> n >> k;
	vector<int> vals(n);
	for (int i=0; i<n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());
	int mx = 0;
	int caps[k+1];
	for (int i=1; i<=k;++i) cin >> caps[i];

	for (int i=1; i<=k; ++i){
		int count = vals.end() - lower_bound(vals.begin(),vals.end(), i);
		// cout << " i " << i << " c " << count << endl;
		int res = count/caps[i];
		if (count % caps[i])
			res++;
		mx = max(mx,res);
	}
	vector<int> groups[mx];
	int cur = -1;
	int cap;
	int j = 0;
	for (int i=n-1; i>=0; --i){
		if (cur != vals[i]){
			cur = vals[i];
			cap = caps[cur];
		}
		while (groups[j].size()>=caps[cur]){
			j++;
			if (j==mx)
				j = 0;
		}
		groups[j].pb(vals[i]);
	}
	cout << mx << endl;
	for (int i=0; i<mx; ++i){
		cout << groups[i].size() << " ";
		for (int j: groups[i]){
			cout << j << " ";
		}
		cout << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}