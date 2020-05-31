#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 100000
using namespace std;

int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp % 2)
		return (res*base)%MOD;
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}
int l;
int timer;
void dfs(int v, int p,  vector<int> adj[], int a[], vector< vector<int> >& vals, vector< vector<int> > &up, vector<int>& tin, vector<int> &tout)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=0; i<=100;++i){
    	vals[v][i] = vals[p][i];
    }
    vals[v][a[v]]++;

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, adj, a, vals, up, tin, tout);
    }
    
    tout[v] = ++timer;
}

bool ancestor(int u, int v, vector<int>&tin, vector<int>&tout)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v, vector<int>&tin, vector<int>&tout, vector<vector<int>> &up)
{
    if (ancestor(u, v, tin, tout))
        return u;
    if (ancestor(v, u, tin, tout))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!ancestor(up[u][i], v, tin, tout))
            u = up[u][i];
    }
    return up[u][0];
}

void solve(){
	int n, q; cin >> n >> q;
	timer = 0;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	vector<int> adj[n];
	vector< vector<int> > vals(n, vector<int>(101, 0));
	int l = (log2(n)) + 3;
	vector< vector<int> > up(n, vector<int>(l+1));
	vector<int> tout(n); vector<int> tin(n);
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0, 0, adj, a, vals, up, tin, tout);
	vector< vector<int> > r(n, vector<int>(n));
	for (int x=0; x<n; ++x){
		for (int b=0; b<n; ++b){
			int baap = lca(x, b, tin, tout, up);
			// cout << "baap is " << baap + 1<< endl;
			vector<int> total(101, 0);
			for (int i=1; i<=100; ++i){
				total[i] = vals[x][i] + vals[b][i] - vals[baap][i] - vals[baap][i];
			}
			total[a[baap]] += 1;
			int best = E9;
			int prev = -1;
			for (int i=1; i<=100; ++i){
				if (total[i] == 0) continue;
				// cout << "got i " << i << " " << total[i] << " times " << endl;
				if (total[i] > 1){
					best = 0; 
				}
				
				if (prev == -1){
					prev = i;
				}
				else {
					best = min(best, i - prev);
					prev = i;
				}
			}
			r[x][b] = best;
		}
	} 

	for (int x=0; x<n; ++x){
		for (int b=0; b<n; ++b){
			if (r[x][b] != r[b][x]){
				cout << "oh" << endl;
			}
		}
	}
		

		
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}