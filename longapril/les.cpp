#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int n, m, q; 
vector< vector<int> > paths;
void dfs(int cur, vector<int> adj[], vector<int> path){
	path.push_back(cur);
	if (cur == n){
		paths.push_back(path); return;
	}
	for (int to: adj[cur])
		dfs(to, adj, path);
}
vector< vector<int> > mul(vector< vector<int> > &a, vector< vector<int> > &b, int k){
	vector< vector<int> > fin(k, vector<int>(k, 0));
	for (int i=0; i<k; ++i){
		for (int j=i; j<k; ++j){
			for(int l=i;l<=j; ++l)
				fin[i][j] = (fin[i][j] + (a[i][l]*b[l][j])%MOD)%MOD;
		}
	}
	return fin;
}
vector< vector<int> > fast_expo(vector< vector<int> > &matrix, int exp, int k){
	vector< vector<int> > base(k, vector<int>(k, 0));
	for (int i=0; i<k; ++i) base[i][i] = 1;

	while (exp > 0){
		if (exp%2){
			base = mul(base, matrix, k);
		}
		matrix = mul(matrix, matrix, k);
		exp /= 2;
	}

	return base;
}
signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	int l[n+1];
	for (int i=1; i<=n; ++i) cin >> l[i];
	vector<int> adj[n+1];
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	if (n<=10){
		vector<int> emp;
		dfs(1, adj, emp);
		while (q--){
			int d; cin >> d;
			int ans = 0;
			for (vector<int> path: paths){
				int dis = path.size()-1;
				if (dis > d) continue;
				if (dis == d) {
					ans = (ans+1)%MOD; continue;
				}
				int exp = d - dis;
				int k = path.size();
				vector< vector<int> > matrix(k, vector<int>(k, 0)); // k by k matrix
				for (int i=0; i<k; ++i){
					for (int j=i; j<k; ++j)
						matrix[i][j] = l[path[j]];
				}
				vector< vector<int> > final = fast_expo(matrix, exp, k);
				for (int i=0; i<k; ++i){
					ans = (ans + final[0][i])%MOD;
				}
			}
			coutm << ans << endl;
		}
	}
	else {
		int queries[q];
		for (int i=0; i<q; ++i) cin >> queries[i];
		int ma = queries[0]; for (int i=1; i<q; ++i) ma = max(queries[i], ma);
		int **dp = new int*[n+1];
		
		
		for (int f=n; f>=1; --f){
			dp[f] = new int[ma+1];
			if (f==n)
				dp[f][0] = 1;
			else
				dp[f][0] = 0;
			for (int d=1; d<=ma; ++d){
				dp[f][d] = (l[f]*dp[f][d-1])%MOD ;
				for (int to: adj[f]){
					dp[f][d] = (dp[f][d] + dp[to][d-1])%MOD;
				}
			}
		}	
		
		
		for (int i=0; i<q; ++i){
			int d = queries[i];
			int ans = dp[1][d];
			cout << ans << endl;
		}
	}
	
	return 0;
}