#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	int sieve[10001];
	memset(sieve, 0, sizeof(sieve));
	for (int i=2; i<=10000; ++i){
		if (sieve[i]!=0)
			continue;
		for (int j=i; j<=10000; j+=i){
			sieve[j] = i;
		}
	}
	vector< pair<int, int> > prime_fac[10001];
	prime_fac[1].push_back(make_pair(1,1));
	for (int i=2; i<=10000; ++i){
		int temp = i;
		prime_fac[i].push_back(make_pair(sieve[temp], 1));
		temp /= sieve[temp];
		int j = 0;
		while (temp > 1){
			if (sieve[temp]==prime_fac[i][j].first)
				prime_fac[i][j].second++;
			else{
				prime_fac[i].push_back(make_pair(sieve[temp], 1));
				j++;
			}
			temp /= sieve[temp];
		}
	}

	while (t--){
		int n, m; cin >> n >> m;
		int vals[n];
		for (int i=0; i<n; ++i){
			cin >> vals[i];
		}
		map<int, int> holder;
		for (int i=0; i<n; ++i){
			for (int j=0; j<prime_fac[vals[i]].size(); ++j){
				if (holder.count(prime_fac[vals[i]][j].first)){
					holder[prime_fac[vals[i]][j].first] = max(holder[prime_fac[vals[i]][j].first], prime_fac[vals[i]][j].second);
				}
				else {
					holder[prime_fac[vals[i]][j].first] = prime_fac[vals[i]][j].second;
				}
			}
		}
		int scale = 1;
		int ans = 1;
		int val = 1;
		while (val<=m){
			int gcd_val = 1;
			for (int i=0; i<prime_fac[val].size(); ++i){
				int prime = prime_fac[val][i].first; int exp = prime_fac[val][i].second;
				if (holder.count(prime)){
					gcd_val *= pow(prime, min(exp, holder[prime]));
				}
			}
			int cur_scale = val/gcd_val;
			if (cur_scale > scale){
				scale = cur_scale;
				ans = val;
			}
			val++;
		}
		cout << ans << endl;
		
	}
	return 0;
}
			


