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
int powe(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res);
	if (exp % 2)
		return (res*base);
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}

void solve(){
	int n, p; cin >> n >> p;
	vector<int> vals(n);
	for (int i=0; i<n; ++i){
		cin >> vals[i];
	}
	if (p == 1){
		if (n%2){
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
		return;
	}
	sort(vals.begin(), vals.end());
	int prev = -1;
	int count = 0;
	int thres = 10000000;
	vector<ii> pairs;
	for (int i=0; i<n; ++i){
		if (prev == vals[i]) 
			count++;
		else {
			if (prev != -1){
				pairs.push_back(mp(prev, count));
			}
			prev = vals[i]; count = 1;
		}
	}
	if (prev != -1){
		pairs.push_back(mp(prev, count));
	}
	int m = pairs.size();
	int ans = 0;
	for (int i=m-1; i>=0; --i){
		if (pairs[i].second % 2 == 0){
			continue;
		}
		else {
			// cout << "At i " << i << " power " << pairs[i].first << endl;
			int requirement = 1;
			bool pos = 1;
			int j;
			for (j = i-1; j>=0; --j){
				// cout << "J now " << j << endl;
				// cout << "req " << requirement << endl;
				int delta = (pairs[j+1].first - pairs[j].first);
				if (delta*log(p) + log(requirement) > log(thres)){
					pos = 0; break;
				}
				requirement = requirement*powe(p, delta);
				if (requirement < pairs[j].second){
					pairs[j].second -= requirement;
					break;
				}
				else{
					requirement -= pairs[j].second;
				}
				// cout << "requirement became " << requirement << endl;
				if (j == 0){
					pos = 0; break;
				}
			}
			if (i == 0){
				ans = power(p, pairs[i].first);
			}
			else if (pos != 0){
				i = j + 1;
			}
			else {
				int base = power(p, pairs[i].first);
				int others = 0;
				for (int j=0; j<i; ++j){
					others = (others + (pairs[j].second*power(p, pairs[j].first))%MOD)%MOD;
				}
				ans = base - others;
				if (ans < 0)
					ans += MOD;
				break;
			}
		}
	}
	cout << ans << endl;
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