#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, m, q;

void dfs(int cur, vector<int> adj[], vector<int>& depth, vector<int> &parent, int d){
	depth[cur] = d;
	for (auto i: adj[cur]){
		if (depth[i]==0){
			dfs(i, adj, depth, parent, d+1);
			parent[i] = cur;
		}
	}
}
void combine(vector<int> &fir, vector<int>&sec, vector<int> &result){
	int c = 0;
	int first = 0, second = 0;
	while (c<10){
		if(first == fir.size() && second == sec.size())
			break;
		else if (first == fir.size()){
			result.push_back(sec[second]); second++;}
		else if (second == sec.size()){
			result.push_back(fir[first]); first++;}
		else if (fir[first] < sec[second]){
			result.push_back(fir[first]); first++;}
		else {
			result.push_back(sec[second]); 
			if (sec[second]==fir[first]) first++;
			second++;
		}
		c++;
	}
}
void solve(){
	vector<int> adj[n+1];
	for (int i=0; i<n-1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> cvec[n+1];
	int c[m+1];
	for (int i=1; i<=m; ++i){
		cin >> c[i];
		cvec[c[i]].push_back(i);
	}

	vector<int> depth(n+1, 0);
	vector<int> parent(n+1, 0);
	dfs(1, adj, depth,  parent, 1);
	
	int bound = log2(n) + 3;
	vector< vector<int> > jump(n+1, vector<int>(bound, 0));
	for (int i=1; i<=n; ++i){ jump[i][0]  = parent[i];}
	for (int i=1; i<=n; ++i){
		for (int j=1; j<bound; ++j)
			jump[i][j] = jump[jump[i][j-1]][j-1];
	}
	vector< vector< vector<int> > > ans(n+1, vector< vector<int> >(bound));
	
	for (int i=1; i<=n; ++i){
		if (parent[i]==0) continue;
		combine(cvec[i], cvec[parent[i]], ans[i][0]);
	}
	for (int i=1; i<=n; ++i){
		for (int j=1; j<bound; ++j){
			int cur = jump[i][j-1];
			combine(ans[i][j-1], ans[cur][j-1], ans[i][j]);	
		}
	}
				
			
	while (q--){
		int v, u, a;
		cin >> v >> u >> a;
		if (depth[v] > depth[u]) swap(u, v);
		int b1 = log2(depth[v]), b2 = log2(depth[u]);
		int cur_u = u;
		while (depth[cur_u] > depth[v]){
			int to = jump[cur_u][b2];
			if (to != 0){
				if (depth[to]>= depth[v])
					cur_u = to; 
			}
			b2--;
		}
		int cur_v = v;
		while (b1 >= 0){
			int to1 = jump[cur_u][b1], to2 = jump[cur_v][b1];
			if (to1 != to2){
				cur_u = to1; cur_v= to2;
			}
			b1--;
		}
		int lca = (cur_u == cur_v ? cur_u : parent[cur_u]);
		bool got = 0;
		vector<int> res;
		int logjump = log2(depth[v]);
		while (v != lca){
			int to = jump[v][logjump];
			if (to == 0 || depth[to] < depth[lca]){ logjump--; continue;}
			if (!got){
				res = ans[v][logjump]; got = 1;	
			}
			else {
				vector<int> result;
				combine(res, ans[v][logjump], result);
				res = result;
			}
			v = to;
			logjump--;
		}
		got = 0;
                vector<int> res2;
                logjump = log2(depth[u]);
                while (u != lca){
                        int to = jump[u][logjump];
                        if (to == 0 || depth[to] < depth[lca]){
				logjump--;
				continue;
			}
                        if (!got){
                                res2 = ans[u][logjump]; got = 1;
                        }
                        else {
                                vector<int> result;
                                combine(res2, ans[u][logjump], result);
                                res2 = result;
                        }       
			u = to;
                        logjump--;
                }       

		vector<int> finalres;
		combine(res, res2, finalres);
		cout << min( (int) finalres.size(), a) << " ";
		for (int i=0; i<min( (int) finalres.size(), a); ++i){
			cout << finalres[i] << " ";
		}
		cout << "\n";

	}

	
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	solve();
	return 0;
}

