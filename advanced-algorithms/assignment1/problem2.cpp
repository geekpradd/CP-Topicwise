#include <bits/stdc++.h>
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;

signed main(){
	int n, m; cin >> n >> m;
	vector<ii> adj[n+m+2];
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=m; ++j){
			int yes; cin >> yes;
			if (yes){
				adj[j].pb(mp(m+i, 1));
				adj[m+i].pb(mp(j, 0));
			}
		}
	}
	for (int i=1; i<=m; ++i){
		adj[0].pb(mp(i, 1));
		adj[i].pb(mp(0, 0));
	}
	for (int i=1; i<=n; ++i){
		adj[m+i].pb(mp(m+n+1, 1));
		adj[m+n+1].pb(mp(m+i, 0));
	}
	int flow = 0;
	vector<int> path;
	bool got = false;
	int l = 0;
	do {
		vector<int> prev(n+m+2, 0);
		queue<ii> bfs; 
		got = false;
		bfs.push(mp(0, 0));
		while (!bfs.empty()){
			ii cur = bfs.front();
			bfs.pop();
			int v = cur.first; int p = cur.second;
			cout << "at " << v << endl;
			if (prev[v] == 0){
				prev[v] = p;
			}
			else {
				continue;
			}
			if (v == n+m+1) {
				got = true; break;
			}
			for (ii to: adj[v]){
				if (!to.second) continue;
				if (prev[to.first]) continue;
				// cout << "going to " << to.first << " from " << v << endl;
				bfs.push(mp(to.first, v));
			}
		}
		if (got){
			flow++;
			int cur = n+m+1;
			// cout << "starting reverse " << endl;
			while (cur != 0){
				// cout << "at " << cur << endl;
				for (int i = 0; i<adj[prev[cur]].size(); ++i){
					if (adj[prev[cur]][i].first == cur){
						adj[prev[cur]][i].second = 0;
					}
				}
				for (int i = 0; i<adj[cur].size(); ++i){
					if (adj[cur][i].first == prev[cur]){
						adj[cur][i].second = 0;
					}
				}
				cur = prev[cur];
			}
		}
		l++;

	}
	while (got);

	vector<int> ans(m+1, -1);
	for (int i=1;i<=n; ++i){
		for (ii to: adj[m+i]){
			if (to.second == 0 && to.first != m+n+1){
				ans[i] = to.first;
			}
		}
	}
	cout << flow << endl;
	for (int i=1; i<=n; ++i){
		cout << ans[i] << " ";
	}
	cout << endl;
}