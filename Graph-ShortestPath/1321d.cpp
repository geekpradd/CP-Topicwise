#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	vector<int> rev_adj[n+1]; // this is the original adj
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[v].push_back(u);
		rev_adj[u].push_back(v);
	}
	vector<int> dist(n+1, -1);
	int k; cin >> k;
	int path[k];
	for(int i=0; i<k; ++i) cin >> path[i];
	queue<ii> bfs;
	bfs.push(make_pair(path[k-1], 0));
	while (!bfs.empty()){
		ii cur = bfs.front();
		bfs.pop();
		if (dist[cur.first]!=-1) continue;
		dist[cur.first] = cur.second;
		for (auto val: adj[cur.first]){
			if (dist[val]==-1)
				bfs.push(make_pair(val, cur.second+1));
		}
	}
	int min_change = 0, max_change = 0;
	int prev = path[0];
	for (int i=1; i<k-1; ++i){
		if (dist[prev]-dist[path[i]]!=1) {
			min_change++; max_change++;
		}
		else {
			int pos = 0;
			for (auto val: rev_adj[prev]){
				if (val==path[i]) continue;
				if (dist[val]==dist[prev]-1){
					pos = 1;
					break;
				}
			}
			max_change += pos;
		}
		prev = path[i];
	}
	cout << min_change << " " << max_change << endl;
	return 0;
}
