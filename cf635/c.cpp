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
struct q {
	int first, count, res_c;
};
vector<ii> deps;
int n, k;

void dfs(int cur, vector<int> adj[], vector<int> &visited, int d){
	visited[cur] = 1;
	deps[cur-1] = make_pair(d, cur);

	for (int to: adj[cur]){
		if (visited[to]) continue;
		dfs(to, adj, visited, d+1);
	}

}

void solve(){
	cin >> n >> k;
	vector<int> adj[n+1];
	deps.resize(n);
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector<int> visited(n+1, 0);
	dfs(1, adj, visited, 0);
	sort(deps.begin(), deps.end(), greater<ii>());
	vector<q> uniq;
	int prev = deps[0].first;
	int count = 0;
	int res_c = 0;
	for (int i=0; i<n; ++i){
		if (deps[i].first==prev){
			count++;
			int j = deps[i].second;
			if (adj[j].size()>1 || j == 1)
				res_c++;
		}
		else {
			q cur = {prev, count, res_c};
			uniq.pb(cur);
			count = 1;
			res_c = 0;
			prev = deps[i].first;
			int j = deps[i].second;
			if (adj[j].size()>1 || j == 1)
				res_c++;
		}
	}
	q cur = {prev, count, res_c};
	uniq.pb(cur);
	int cost = 0; int i = 0;
	while (k > 0){
		// cout << "k " << k << endl;
		int capacity = uniq[i].count;
		// cout << "VAL " << uniq[i].first << " cap " << capacity << endl;
		int c2 = capacity - uniq[i].res_c;
		int c3 = uniq[i].res_c;
		// cout << "c2 " << c2 << " c3 " << c3 << endl;
		if (k > c2){
			cost += uniq[i].first*c2;
			k -= c2;
		}
		else {
			cost += uniq[i].first*k;
			k = 0;
			break;
		}
		if (k > c3){
			cost += uniq[i].first*c3 - c3;
			k -= c3;
		}
		else {
			cost += uniq[i].first*k - k;
			k = 0;
		}
		i++;
	}
	cout << cost << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}