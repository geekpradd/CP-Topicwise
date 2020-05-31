#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int timer;
void dfs(int cur, int par, vector<int> adj[], int tin[], int tout[], int parent[]){
	parent[cur] = par;
	tin[cur] = ++timer;
	for (int to: adj[cur]){
		if (to != par)
			dfs(to, cur, adj, tin, tout, parent);
	}
	tout[cur] = ++timer;
}
bool is_ancestor(int u, int v, int tin[], int tout[]){
	return (tin[u]<=tin[v] && tout[u] >= tout[v]);
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		timer = 0;
		int n, q;
		cin >> n >> q;
		int a[n];
		for (int i=0; i<n; ++i){
			cin >> a[i];
		}
		vector<int> adj[n];
		for (int i=0; i<n-1; ++i){
			int u, v; cin >> u >> v; u--; v--;
			adj[u].pb(v); adj[v].pb(u);
		}
		int tin[n];
		int tout[n];
		int parent[n];
		dfs(0, 0, adj, tin, tout, parent);
		while (q--){
			int x, y; cin >> x >> y; x--; y--;
			int cop = x;
			int num = 1;
			vector<int> values(101, 0);
			values[a[x]] += 1;
			while (!is_ancestor(cop, y, tin, tout) && num<105){
				// cout << "At " << cop << endl;
				cop = parent[cop];
				values[a[cop]] += 1;
				num++;
			}
			int cop2 = y;
			while (cop2 != cop && num < 105){
				// cout << "Att " << cop2 << endl;
				values[a[cop2]] += 1;
				cop2 = parent[cop2];
				num++;
			}
			if (num>=100){
				cout << 0 << endl;
				continue;
			}
			int best = 10000;
			int prev = -1;
			for (int i=1; i<=100; ++i){
				if (values[i] > 1){
					best = 0; break;
				}
				if (values[i] == 0) continue;
				// cout << "i " << i << " values " << values[i] << endl;
				if (prev == -1)
					prev = i;
				else {
					best = min(best, i - prev);
					prev = i;
				}
			}
			cout << best << endl;

		}
	}
}