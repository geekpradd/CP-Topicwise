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

bool dfs(int cur, vector<int> adj[], vector<int> &visited, int parent){
	visited[cur] = 1;
	bool res = 0;
	for(int x: adj[cur]){
		if (x==parent) continue;
		if (visited[x]) return 1;
		res = res | dfs(x, adj, visited, cur);
	}
	return res;
}
void solve(){
	int n, m; cin >> n >> m;
	vector<int> adj[n+1];
	vector<int> dual[n+1];
	for (int i=0; i<m; ++i){
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		dual[b].push_back(a);
		dual[a].push_back(b);
	}
	bool pos = 0;
	vector<int> visited(n+1, 0);
	for (int i=1; i<=n; ++i){
		if (visited[i]) continue;
		pos = dfs(i, dual, visited, -1);
		if (pos) break;
	}
	char ans[n+1];
	int count = 0;
	for (int i=1; i<=n; ++i){
		if (adj[i].size()==0){
			ans[i] = 'A';
			count++;
		}
		else
			ans[i] = 'E';
	}
	if (pos){
		cout << -1 << endl;
		return;
	}
	cout << count << endl;
	for (int i=1; i<=n; ++i){
		cout << ans[i];
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}