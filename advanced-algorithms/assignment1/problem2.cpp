#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair 

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}

pair<vector<int>, int > get_path(vector< vector<int> > &adj, int src, int target){
	queue<ii> bfs;
	bfs.push(mp(src, 0));
	vector<ii> visited(target+1, mp(0, -1));

	bool got = 0;
	while (!bfs.empty()){
		ii top = bfs.front();
		bfs.pop();
		
		if (visited[top.first].first) continue;
		visited[top.first].first = 1;
		visited[top.first].second = top.second;

		// cout << "visitinf " << top.first << " from " << top.second<< endl;
		// cout << "target " << target << endl;
		if (top.first == target){
			got = 1; break;
		}

		for (int i=1; i<=target; ++i){
			if (visited[i].first) continue;
			if (adj[top.first][i] == 0) continue;

			bfs.push(mp(i, top.first));
		}
	}
	vector<int> path;
	if (!got){
		return mp(path, 0);
	}
	int cur = target;
	int f = 1000000;
	while (cur != src){
		path.push_back(cur);
		f = min(f, adj[visited[cur].second][cur]);
		cur = visited[cur].second;
	}
	path.push_back(src);

	return mp(path,f);
}


signed main(){
	int n, m; cin >> n >> m;
	vector< vector<int> >  adj(n+m+2, vector<int>(n+m+2, 0));
	vector< vector<int> > copied(n+m+2, vector<int>(n+m+2, 0));
	for (int i=1; i<=n; ++i){
		adj[0][i] = 1;
		for (int j=n+1; j<=n+m; ++j){
			cin >> adj[i][j];
			copied[i][j] = adj[i][j];
			if (i==1) adj[j][n+m+1] = 1;
		}
	}
	int source = 0, target = n + m + 1;

	int flow = 0;
	pair<vector<int>, int> path = get_path(adj, source, target);

	while (path.first.size()){
		flow += path.second;
		// cout << path.first << endl;
		for (int i=path.first.size()-1; i>0; --i){
			adj[path.first[i]][path.first[i-1]] -= path.second;
			adj[path.first[i-1]][path.first[i]] += path.second;
		}


		path = get_path(adj, source, target);

	}

	vector<int> ans(n+1, -1);
	for (int i=1; i<=n; ++i){
		for (int j=n+1; j<=n+m; ++j){
			if (adj[i][j] != copied[i][j]){
				ans[i] = j - n; break;
			}
		}
	}
	for (int i=1; i<=n; ++i){
		cout << ans[i] << " ";
	}

	cout << endl;
	// cout << flow << endl;
	return 0;

}