#include <bits/stdc++.h>
#define ii pair<int, int>
#define pb push_back
#define MOD 1000000007
#define E9 1000000000
using namespace std;
vector< vector<int> > adj;
vector<int> match;
int n, m, k; 
int match_count = 0;
struct qi {
	int i, t, p, pt;
};
vector<int> get_augmenting(){
	ii visited[n+1][2];
	for (int i=1; i<=n; ++i)
		visited[i][0] = visited[i][1] = make_pair(0, 0);
	vector<int> path;
	bool found = 0;
	for (int i=1; i<=n && !found; ++i){
		// cout << "MATCH " << i << " = " << match[i] << endl;
		if (match[i]!=0) continue;
		// cout << "STARTING BFS FROM " << i << endl;
		queue<qi> bfs;
		// cout << "Start from " << i << endl;
		qi first = {i, 0, 0, 1};
		// 0 type means searchable, 1 type means moves on
		bfs.push(first);
		int terminal, terminal_prev;
		while (!bfs.empty()){
			qi front = bfs.front();
			bfs.pop();
			ii null = make_pair(0, 0);
			if (visited[front.i][front.t] != null)
				continue;
			// cout << "REACHED " << front.i << " WITH STATUS " << front.t << endl;
			
			visited[front.i][front.t] = make_pair(front.p, front.pt);
			if (front.t == 1){
				// cout << "ADDING PARTNER " << match[front.i] << endl;
				qi to = {match[front.i], 0, front.i, front.t};
				bfs.push(to);
			}
			else {
				for (int j: adj[front.i]){
					if (match[j] == 0 && j != i){
						found = 1; terminal = j; terminal_prev = front.i;
						// cout << "FOUND FINAL EXPOSED " << j << endl;
						break;
					}
					if (visited[j][1] != null) continue;
					qi to = {j, 1, front.i, front.t};
					// cout << "ADDING NON PARTNER " << j << endl;
					bfs.push(to);

				}
				if (found)
					break;
			}
		}
		if (found){
			path.push_back(terminal); terminal = terminal_prev;
			int state = 0;
			while (terminal != i){
				path.push_back(terminal);
				terminal = visited[terminal][state].first;
				state = 1 - state;
			}
			path.push_back(i);
			break;
		}
		
	}

	return path;
}
signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> m >> k;
	adj.resize(n+1);
	match.assign(n+1, 0);
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	// 0 is for even parity of unexposed vertices, 1 is for odd parity
	// we will find augmenting paths until none exist
	// for (int i=1; i<=n; ++i){

	// 	cin >> match[i];
	// 	cout << "matched " << i << " to " << match[i] << endl;
	// }
	vector<int> path = get_augmenting();
	// cout << "PATH IS " << endl;
	// for (int node: path){
	// 	cout << node << " ";
	// }
	// cout << endl;
	while (path.size()!=0){
		// cout << "path is: ";
		// for (int to: path){
		// 	cout << to << " ";
		// }
		// cout << endl;
		match_count++;
		for (int i=0; i<path.size(); ++i){
			if (i%2)
				match[path[i]] = path[i-1];
			else
				match[path[i]] = path[i+1];
		}
		path = get_augmenting();
	}

	cout << match_count << endl;

}