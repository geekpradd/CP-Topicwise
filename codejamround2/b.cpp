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
	int n, m; cin >> n >> m;
	int step[n+1];
	vector<int> times(n+1, -1);
	vector<ii> vv;
	vector<int> stepers[n];
	step[1] = 0;
	stepers[0].push_back(1);
	for (int i=2; i<=n; ++i){
		int val; cin >> val;
		if (val < 0){
			step[i] = -val;
			stepers[-val].push_back(i);
		}
		else {
			times[i] = val;
			vv.push_back(mp(val, i));
		}
	}
	vector<ii> adj[n+1];
	int vals[m];
	times[1] = 0;
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
		vals[i] = 1000000;
	}
	sort(vv.begin(), vv.end());
	int j = 0;
	int so_far = 1;
	int prev = 1;
	for (int i=1; i<n; ++i){
		if (stepers[i].size()!=0){	
			int ind = prev-1;
			int pval = -1;
			while (so_far < i){
				if (vv[j].first != pval){
					ind++;	
				}
				stepers[ind].push_back(vv[j].second);
				step[vv[j].second] = ind;
				pval = vv[j].first;
				j++;
				so_far++;
			}
			prev = i;
		}
		so_far += stepers[i].size();
	}
	if (j < vv.size()){
		int ind = prev-1;
		int pval = -1;
		while (j < vv.size()){
			if (vv[j].first != pval){
				ind++;	
			}
			stepers[ind].push_back(vv[j].second);
			step[vv[j].second] = ind;
			pval = vv[j].first;
			j++;
		}
	}
	int prev_is = -1;
	// int prev_val = 0;
	// int so_far = 0;
	// for (int j=0; j<vv.size(); ++j){
	// 	if (vv[j].first == prev_val){
	// 		stepers[prev_is].push_back(vv[j].second);
	// 		step[vv[j].second] = prev_is;
	// 	}
	// 	else {

	// 		int start = prev_val + 1;
	// 	}

	// 	prev_val = vv[j].first;
	// 	prev_is = step[vv[j].second];
	// }
	int ttr = 0;
	for (int i=1; i<n; ++i){
		cout << "Step " << i << endl;
		for (int x: stepers[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	for (int i=1; i<n; ++i){
		if (stepers[i].size()==0) continue;
		bool has = 0;
		int val;
		for (int node:stepers[i]){
			if (times[node] != -1){
				has = 1;
				val = times[node];
			}
		}
		if(has){
			for (int node: stepers[i]){
				times[node] = val;
			}
			ttr = val;
		}
		else {
			for (int node: stepers[i]){
				times[node] = ttr+1;
			}
			ttr++;
		}
					// cout << "time at " << i << " " << ttr << endl;

		for (int node: stepers[i]){
			for (ii to: adj[node]){
				int x = to.first;
				if (step[x] < step[node]){
					vals[to.second] = times[node] - times[x];
					break;
				}
			}
		}
	}
	for (int i=0; i<m; ++i){
		cout << vals[i] << " ";
	}
	cout << endl;


}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		cout << "Case #"<< w << ": ";
		solve();
	}
	return 0;
}