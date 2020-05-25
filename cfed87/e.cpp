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
int inverse(int n){
	return power(n, MOD-2);
}
int dfs(int cur, vector<int> adj[], vector<ii>&comps, int comp, int parity, vector<ii> &compp){
	int count = 1;
	comps[cur].first = comp;
	for (int to: adj[cur]){
		if (comps[to].first == -1){
			count += dfs(to, adj, comps, comp, 1-parity, compp);
		}
	}

	if (parity)
		compp[comp].second++;
	else
		compp[comp].first++;
	comps[cur].second = parity; 
	return count;
}

void solve(){
	int n,m; cin >> n >> m;
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	vector<int> adj[n+1];
	vector<ii> edges(m);
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
		edges[i] = mp(u, v);
	}
	vector<ii> comps(n+1, make_pair(-1, 0));
	int blue = 0;
	vector<ii> compp;
	int comp = 0;
	for (int i=1; i<=n; ++i){
		if (comps[i].first==-1){
			compp.push_back(mp(0, 0));
			int c = dfs(i, adj, comps, comp, 0, compp);
			blue += c/2;
			comp++;
		}
	}
	if (blue != n2){
		cout << "NO" << endl;
		return;
	}
	int a = n1;
	int c = n3;
	
	vector<int> cols(n+1);
	for (int i=1; i<=n; ++i){
		int comp = comps[i].first;
		int min_p = 1;
		if (compp[comp].first < compp[comp].second)
			min_p = 0;
		if (comps[i].second == min_p){
			cols[i] = 2;
		}	
		else {
			if (a > 0){
				cols[i] = 1;
				a--;
			}
			else if (c > 0){
				cols[i] = 3;
				c--;
			}
			
		}
	}
	bool pos = 1;
	for (int i=0; i<m; ++i){
		int col1 = cols[edges[i].first];
		int col2 = cols[edges[i].second];
		if (abs(col1-col2) != 1){
			pos = 0;
		}
	}
	if (pos){
		cout << "YES" << endl;
		for (int i=1; i<=n; ++i){
			cout << cols[i];
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}