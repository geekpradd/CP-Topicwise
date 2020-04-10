#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int dfs(int cur, vector<bool> &visited, vector<int> adj[]){
	visited[cur] = 1;
	int tot = 1;
	for (int to: adj[cur]){
		if (!visited[to])
			tot += dfs(to, visited, adj);
	}
	return tot;
}

signed main(){
	int t; cin >> t;
	int fact[100001]; fact[1] = 1;
	fact[0] = 0;
	for (int i=2; i<=100000; ++i)
		fact[i] = (fact[i-1]*i)%MOD;
	while (t--){
		int n, k; cin >> n >> k;
		vector<int> adj[n+1];
		int a[n], b[n];
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cin >> b[i];
		for (int i=0; i<n; ++i){
			if (a[i]==b[i]) continue;
			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}
		vector<bool> visited(n+1, 0);
		int w = 0, prod = 1;
		int sum = 0;
		for (int i=1; i<=n; ++i){
			if (adj[i].size()==0) continue;
			if (visited[i]) continue;
			w++;
			int n_i = dfs(i, visited, adj);
			int val = (fact[n_i])%MOD;
			prod = (prod*val)%MOD;
			sum = (sum + n_i)%MOD;
		}
		sum = sum - w;
		if (sum < 0) sum += MOD;
		int ways = (fact[sum]*prod)%MOD;
		cout << sum << " ";
		if (k==2)
			cout << ways << endl;
		else
			cout << endl;
	}
	return 0;
}
