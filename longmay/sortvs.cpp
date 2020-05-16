#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

void dfs(int i, vector<int>& push, vector<int>& component, vector<int> adj[], int id){
	if (component[i] != -1) return;
	push.push_back(i);
	component[i] = id;
	for (int to: adj[i]){
		if (component[to] != -1) continue;
		dfs(to, push, component, adj, id);
	}
}

int counter(int cur, int start, vector<ii> cadj[], vector<int> visited, vector<int> saturated, int id){
	int val = 0;
	bool achiev = 0;
	for (ii to: cadj[cur]){
		if (visited[to.second]) continue;
		achiev = 1;
		vector<int> modif = visited;
		modif[to.second] = 1;
		if (to.first == start){
			val = max(val, 1 + counter(start, start, cadj, modif,saturated, id));
		}
		else {
			val = max(val, counter(to.first, start, cadj, modif, saturated, id));
		}
	}
	if (!achiev){
		saturated[cur] = 1;
		int j = -1;
		for (int i=0; i<id; ++i){
			if (saturated[i] != 1){
				j = i; break;
			}
		}
		if (j != -1)
			val = counter(j, j, cadj, visited, saturated, id);
	}

	return val;
}

void solve(){
	int n, m; cin >> n >> m;
	int orig[n+1];
	for (int i=1; i<=n; ++i){
		int cur; cin >> cur;
		orig[cur] = i;
	}
	vector<int> adj[n+1];
	for (int i=0; i<m; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> component(n+1, -1);
	vector< vector<int> >components;
	int id = 0;
	for (int i=1; i<=n; ++i){
		if (component[i] != -1) continue;
		vector<int> cur;
		dfs(i, cur, component, adj, id);
		components.push_back(cur);
		id++;
	}

	vector<ii> cadj[id];
	int count = 0;
	vector<ii> edges;
	for (int i=1; i<=n; ++i){
		if (component[i] == component[orig[i]]) continue;
		cadj[component[i]].push_back(make_pair(component[orig[i]], count));
		ii cur = make_pair(component[i], component[orig[i]]);
		edges.push_back(cur);
		// cout << "Edge between " << component[i] << " and " << component[orig[i]] << " with id " << count << endl;
		count++;
	}
	int excess = 0;
	if (edges.size()!=0){
		int start = edges[0].first;
		vector<int> visited(count, 0); 
		vector<int> saturated(id, 0);
		excess = counter(start, start, cadj, visited, saturated, id);
	}
	// cout << "count " << count << endl;
	cout << count - excess << endl;
}

signed main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
}