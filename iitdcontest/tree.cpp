#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

int dfs(int cur, vector<int> adj[], vector<bool> &visited, bool status[], vector<int>& v){
	visited[cur] = 1;
	int here = 1 - status[cur];
	for (int to: adj[cur]){
		if (visited[to]) continue;
		int val = dfs(to, adj, visited, status, v);
		if (!status[cur]) {
			if (val == 0){
				here = 0;
			}
			if (here != 0){
				here = here + val;
			}
		}
	}
	v[cur] = here;
	return here;
}

signed main(){
	vector<int> sieve(1000001, 0);
	sieve[0] = sieve[1] = 1;
	for (int i=2; i<=1000000; ++i){
		if (sieve[i]) continue;
		for (int j=2*i; j<=1000000; j+=i)
			sieve[j] = 1;
	}
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		int n; cin >> n;
		vector<int> adj[n];
		int vals[n];
		for (int i=0; i<n; ++i) vals[i] = 0;
		for (int i=0; i<n-1; ++i){
			int a, b; cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
			vals[a] += b; vals[b] += a;
		}
		bool status[n];
		for (int i=0; i<n; ++i){
			int cur = vals[i];
			if (cur<=1000000){
				status[i] = 1 - sieve[cur];
			}
			else {
				bool p = 1;
				for (int j=2; j*j<=cur; ++j){
					if (cur%j==0){
						p = 0;
						break;
					}
				}
				status[i] = p;
			}
			// cout << "stat " << i << " : " << status[i] << endl;
		}
		vector<bool> visited(n, 0);
		vector<int> v(n, 0);
		dfs(0, adj, visited, status, v);
		int ans = 0;
		for (int i=0; i<n; ++i) ans = max(ans, v[i]);


		cout << "Case #" << w << ": ";
		if (ans == 0)
			cout << "BAD TREE!" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}