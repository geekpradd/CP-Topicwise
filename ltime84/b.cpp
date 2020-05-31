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
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	vector<ii> collapsed;
	int prev = a[0];
	int prev_count = 1;
	for (int i=1; i<n; ++i){
		if (a[i] != prev){
			collapsed.pb(mp(prev, prev_count));
			prev = a[i];
			prev_count = 1;
		}
		else {
			prev_count++;
		}
	}
	collapsed.pb(mp(prev, prev_count));
	// for (ii x: collapsed){
	// 	cout << x.first << " " << x.second << endl;
	// }
	if (collapsed.size()==1){
		ii prev = collapsed[0];
		int ans = (prev.second*(prev.second+1))/2;
		cout << ans << endl;
		return;
	}
	int ans = (collapsed[0].second*(collapsed[0].second+1))/2;
	ans += collapsed[1].second*collapsed[0].second;
	ans += (collapsed[1].second*(collapsed[1].second+1))/2;
	int total = collapsed[0].second + collapsed[1].second;
	bool incr = (collapsed[1].first > collapsed[0].first);
	for (int i=2; i<collapsed.size(); ++i){
		ans += (collapsed[i].second*(collapsed[i].second+1))/2;
		bool ic = (collapsed[i].first > collapsed[i-1].first);
		if (ic != incr) {
			incr = ic;
			total = collapsed[i-1].second;
		}
		ans += collapsed[i].second*total;
		total += collapsed[i].second;
	}

	cout << ans << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}