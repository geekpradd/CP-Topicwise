#include <bits/stdc++.h>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;


void dfs(int to, vector<int> adj[], vector<int>& visited){
	visited[to] = 1;
	for (int z: adj[to]){
		if (visited[z]) continue;
		dfs(z, adj, visited);
	}
} 

signed main(){
	int n, m, d; cin >> n >> m >> d;	
	vector<int> adj[n+1];
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<int> visited(n+1, false);
	visited[1] = true;
	vector<int> marked(adj[1].size(), false);

	int count = 0;
	for (int i=0; i<adj[1].size(); ++i){
		int to = adj[1][i];
		if (!visited[to]){
			marked[i] = 1;
			count++;
			dfs(to, adj, visited);
		}
	}
	// cout << "count " << count << endl;
	if (count > d || marked.size() < d){
		cout << "NO" << endl;
	}
	else {
		int rem = d - count;
		for (int i=0; i<marked.size(); ++i){
			if (rem == 0) break;
			if (!marked[i]){
				marked[i] = 1;
				rem--;
			}
		}
		cout << "YES" << endl;
		vector<ii> outs;
		queue<ii> bfs;
		vector<int> visited(n+1, false);
		bfs.push(make_pair(1, 0));
		while (!bfs.empty()){
			ii top = bfs.front();
			bfs.pop();
			if (visited[top.first]) continue;

			visited[top.first] = 1;
			if (top.second != 0){
				outs.push_back(top);
			}
			for (int i= 0; i< adj[top.first].size(); ++i){
				int to = adj[top.first][i];
				if (visited[to]) continue;
				if (top.first == 1 ){
					if (!marked[i]) continue;
				}
				bfs.push(mp(to, top.first));
			}
		}
		for (ii x: outs){
			cout << x.first<< " " << x.second << endl;
		}
	}
}