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
vector<int> deps;
int n, k;

int dfs(int cur, vector<int> adj[], vector<int> &visited, int d){
	visited[cur] = 1;
	int children = 0;

	for (int to: adj[cur]){
		if (visited[to]) continue;
		children += dfs(to, adj, visited, d+1);
	}

	deps[cur-1] = d - children;
	
	return 1 + children;

}

void solve(){
	cin >> n >> k;
	vector<int> adj[n+1];
	deps.resize(n);
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<int> visited(n+1, 0);
	dfs(1, adj, visited, 0);
	int cost = 0;
	sort(deps.begin(), deps.end(), greater<int>());
	for (int i=0; i<k; ++i)
		cost += deps[i];
	cout << cost << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}