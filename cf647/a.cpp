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
	vector<int> adj[n+1];
	vector<ii> edges(m);
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
		ii ed = mp(u, v);
		edges[i] = ed;
	}
	vector<int> vals(n+1);
	vector<bool> hit(n+1, 0);
	vector<ii> info(n);
	for (int i=1; i<=n; ++i){
		cin >> vals[i];
		info[i-1] = mp(vals[i], i);
	} 
	bool pos = 1;
	for (ii ed: edges){
		if (vals[ed.first] == vals[ed.second]) pos = 0;
	}
	if (pos == 0){
		cout << -1 << endl;
		return;
	}
	vector<ii> vl(n+1, mp(0, -1));
	sort(info.begin(), info.end());
	for (int i=0; i<n; ++i){
		int k = info[i].first;
		int node = info[i].second;
		hit[node] = 1;
		int max_got = 0;
		int count = 0;
		if (adj[node].size() < (k-1)){
			pos = 0; break;
		}
		
		for (int to: adj[node]){
			if (hit[to]) {
				if (vl[vals[to]].second != i){
					vl[vals[to]] = mp(0, i);
				}
				if (vl[vals[to]].first == 0){
					count++;
					vl[vals[to]].first = 1;
				}
			}
		}
		// cout << "node is " << node << endl;
		// cout << "count " << count << endl;
		// cout << "k " << k << endl;
		if (count != k-1){
			 pos = 0;
			 break;
		}
	}
	if (pos == 0){
		cout << -1 << endl;
		return;
	}
	for (int i=0; i<n; ++i){
		cout << info[i].second << " ";
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}