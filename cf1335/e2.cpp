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
	vector<int> positions[201];
	int n; cin >> n; int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
		positions[a[i]].pb(i);
	}
	int cur_val = 1;
	for (int i=1; i<=200; ++i){
		int max_freq = 0;
		int best = 0;
		vector<int> counter(201, 0);
		if (positions[i].size()<2) continue;
		// cout << "I " << i << endl;
		int siz = positions[i].size()/2;
		int l_i = positions[i][siz-1]+1, r_i = positions[i][positions[i].size()-siz]-1;
		// cout << "INITIAL l " << l_i << " r " << r_i << endl; 
		for (int j=l_i; j<=r_i; ++j){
			counter[a[j]]++;
			if (counter[a[j]] > max_freq)
				max_freq = counter[a[j]];
		}
		// cout << "max " << max_freq << endl;
		while (siz>=1){
			best = max(max_freq + 2*siz, best);
			// cout << "best " << best << " for siz " << siz <<  endl;
			siz--;
			int to_l, to_r;
			if (siz == 0){
				to_l = 0; to_r = n-1;
			}
			else {
			 to_l = positions[i][siz-1]+1, to_r = positions[i][positions[i].size()-siz]-1;
			}
			// cout << "SIZ " << siz << " to_l " << to_l << " to_r " << to_r << endl;
			while (l_i > to_l){
				l_i--;
				counter[a[l_i]]++;
				if (counter[a[l_i]] > max_freq)
					max_freq = counter[a[l_i]];
			}
			while (r_i < to_r){
				r_i++;
				counter[a[r_i]]++;
				if (counter[a[r_i]] > max_freq)
					max_freq = counter[a[r_i]];
			}
		}
		cur_val = max(cur_val, best);
	}

	cout << cur_val << endl;
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