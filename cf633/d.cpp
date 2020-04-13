#include <bits/stdc++.h>
using namespace std;
int mi, ma;

int dfs(int cur, int parent, vector<int> adj[]){
	int ones = 0;
	int child_val = -1;
	for (int to: adj[cur]){
		if (to == parent)
			continue;
		if (adj[to].size()==1)
			ones++;
		int temp = (dfs(to, cur, adj))%2;
		if (child_val == -1)
			child_val = (temp)%2;
		else if (child_val%2 != temp%2){
			child_val = 1;
			mi = 3;
		}
	}

	if (ones>1){
		ma = ma - (ones-1);
	}

	if (adj[cur].size()==1)
		return 1;
	return (1 + child_val)%2;
}

signed main(){
	int n; cin >> n;
	vector<int> adj[n+1];
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ma = n-1; mi = 1;
	int i = 1;
	if (n!=2){
		while (adj[i].size()==1){
			i++;
		}
		dfs(i, 0, adj);
	}
	cout << mi << " " <<  ma << endl;
}