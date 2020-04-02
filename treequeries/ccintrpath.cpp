#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, q;

void dfs(int cur, vector<int> adj[], vector<int>& count, vector<int> &parent, vector<int> &taketwo){
	count[cur] = 1;
	int val1 = 0;
	val2 = 0;
	for (auto i: adj[cur]){
		if (count[i]==0){
			dfs(i, adj, count, parent, taketwo);
			count[cur] += count[i];
			val2 += val1*count[i]; val1 += count[i];
			parent[i] = cur;
		}
	}
	val2 += val1*(n-1-val1);
	taketwo[cur] = val2;
}
void solve(){
	vector<int> adj[n+1];
	for (int i=0; i<n-1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> parent(n+1, 0);
	vector<int> taketwo(n+1, 0);
	vector<int> count(n+1, 0); // no of nodes in subtree rooted at i
	dfs(1, adj, count, parent, taketwo);
	int bound = log2(n) + 2;
	vector< vector<int> > jump(n+1, vector<int>(bound, 0));
	for (int i=1; i<=n; ++i) jump[i][0] = parent[i];
	for (int i=1; i<=n; ++i){
		for (int j=1; j<bound; ++j)
			jump[i][j] = jump[jump[i][j-1]][j-1];
	}
	vector< vector<int> > ans(n+1, vector<int>(bound, 0));
	// ans to (u, u) and (u, parent(u)) is always n
	for (int i=1; i<=n; ++i) ans[i][0] = n;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<bound; ++j){


	
}


signed main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> q;
		solve();
	}
	return 0;
}
