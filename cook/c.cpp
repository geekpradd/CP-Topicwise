#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
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
int n, l, q;

int timer;

int inverse(int n){
	return power(n, MOD-2);
}


void dfs(int v, int p, int a[], vector<int> adj[], vector<ii>&typs, vector< vector<int> > &up, vector<int>& tin, vector<int> &tout)
{
    tin[v] = ++timer;
    up[v][0] = p;
    if (a[v] < a[p]){
    	ii bap = typs[p];
    	if (bap.second == 1){
    		typs[v] = mp(bap.first, 1);
    	}
    	else {
    		typs[v] = mp(p, 1);
    	}
    }
    else if (a[v] > a[p]){
    	ii bap = typs[p];
    	if (bap.second == -1){
    		typs[v] = mp(bap.first, -1);
    	}
    	else {
    		typs[v] = mp(p, -1);
    	}
    }

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, adj,typs, up, tin, tout);
    }
    
    tout[v] = ++timer;
    
    // cout << "for v " << v << endl;
    // cout << "Typ " << typs[v].first << " " << typs[v].second << endl;
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

	cin >> n >> q;
	vector<int> a(n+1);
vector<int> adj[n+1];
vector<ii> typs(n+1, mp(0, 0));
vector<int> tin(n+1);
vector<int> tout(n+1);
	
    tin[0] = E9;
    timer = 0;
    l = ceil(log2(n));
   
    vector<vector<int> > up(n+1, vector<int>(l + 1));
    
    for (int i=0; i<n-1; ++i){
    	int u, v; cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    
    a.clear();
    a.resize(n+1);
    for (int i=1; i<=n; ++i){
    	cin >> a[i];
    }
    dfs(1,1, adj,typs, up, tin, tout);
    // cout << "ok"<< endl;
    bool pos[q];
    for (int i=0; i<q; ++i) pos[i] = 0;
    for (int i=0; i<q; ++i){
    	int a, b; cin >> a >> b;
    	int lc = lca(a, b, tin, tout, up);
    	if (a == b){
    		pos[i] = 1;
    		continue;
    	}
    	bool rev = false;
    	if (lc == a){
    		swap(a, b);
    		// rev = true;
    	}
    	bool pp = 1;
    	int so_f;
    	bool swit;
    	// cout << "A " << a << endl;
    	// cout << "B " << b << endl;
    	// cout << "got lc " << lc << endl;
    	if (lc != a){
    		
    		// cout << "got " << typs[a].second << endl;
    		if (typs[a].second == -1){
    			if (tin[typs[a].first] <= tin[lc]){
    				so_f = typs[a].second;
    				swit = 0;
    			}
    			else {
    				continue;
    			}
    		}
    		else if (typs[a].second == 1){
    			// cout << "baap " << typs[a].first << endl;
	    		// cout << "time " << tin[typs[a].first] << endl;
	    		if (tin[typs[a].first] <= tin[lc]){
	    			so_f = typs[a].second;
	    			swit = 1;
	    		}
	    		else {
	    			swit = 0;
	    			int mid = typs[a].first;
	    			if (tin[typs[mid].first] > tin[lc]){
	    				continue;
	    			}
	    			so_f = typs[mid].second;
	    		}
    		}
    		else {
    			continue;
    		}
    		
    	}
    	// cout << "so_F " << so_f << endl;
    	cout << swit << endl;
    	if (lc != b){
    		int other = -so_f;
    		if (typs[b].second == 0)
    			continue;
    		if (swit == 0){
    			if (typs[b].second == other && tin[typs[b].first] <= tin[lc]){

    			}
    			else {
    				continue;
    			}
    		}
    		else {
    			if (tin[typs[b].first] <= tin[lc]){

    			}
    			else {
    				if (typs[b].second != other){
    					int mid = typs[b].first;
		    			if (tin[typs[mid].first] > tin[lc]){
		    				continue;
		    			}
    				}
    				else {
    					continue;
    				}
    			}
    		}
    		
    	}

    	pos[i] = 1;
    }
    for (int i=0; i<q; ++i){
    	cout << pos[i];
    }
    cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("x.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}