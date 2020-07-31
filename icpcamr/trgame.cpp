#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

int dfs(int cur, vector<bool> &ans, vector<int> adj[], int p, int n){

	int ret = 1;
	vector<int> others;

	for (int to: adj[cur]){
		if (to == p) continue;
		int value = dfs(to, ans, adj, cur, n);
		ret += value;
		others.pb(value);
	}
	if (ret != n)
		others.pb(n - ret);
	ans[cur] = 0;
	sort(others.begin(), others.end());
	for (int i=0; i<others.size()-1; ++i){
		if(others[i]+1 == others[i+1]){
			ans[cur] = 1;
			break;
		}
	}

	return ret;
}

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> adj[n+1];
		for (int i=0; i<n-1; ++i){
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		if (n%2){
			for (int i=0; i<n; ++i){
				cout << "0";
			}
			cout << endl;
		}
		else {
			vector<bool> ans(n+1);
			if (n == 2){
				cout << 11 << endl;
			}
			else {
				dfs(1, ans, adj, 1, n);
				for (int i=1; i<=n; ++i){
					cout << ans[i];
				}
				cout << endl;
			}
			
		}
	}
}