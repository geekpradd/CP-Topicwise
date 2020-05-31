#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

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
struct ret {
	int cost, zo, oz;
};

ret dfs(int cur, int p, vector<int> adj[], vector<bool>& visited, int cost[], int a[], int b[]){
	visited[cur] = 1;
	cost[cur] = min(cost[cur], cost[p]);
	ret g = {0, 0, 0};
	if (a[cur] == 0 && b[cur] == 1){
		g.zo++;
	}
	if (a[cur] == 1 && b[cur] == 0){
		g.oz++;
	}
	for (int to: adj[cur]){
		if (!visited[to]){
			ret pp = dfs(to, cur, adj, visited, cost, a, b);
			g.zo += pp.zo;
			g.oz += pp.oz;
			g.cost += pp.cost;
		}
	}

	int dos = min(g.zo, g.oz);
	g.cost += cost[cur]*2*dos;
	g.zo -= dos;
	g.oz -= dos;
	return g;

}
void solve(){
	int n; cin >> n;
	vector<int> adj[n+1];
	int cost[n+1], a[n+1], b[n+1];
	int x = 0, y = 0;
	for (int i = 1; i<=n; ++i){
		cin >> cost[i] >> a[i] >> b[i];
		if (a[i] == 1){
			x++;
		}
		if (b[i] == 1){
			y++;
		}

	}
	for (int i=0; i<n-1; ++i){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (x != y){
		cout << -1 << endl;
		return;
	}
	vector<bool> visited(n+1, false);
	ret vv = dfs(1, 1, adj, visited, cost, a, b);
	cout << vv.cost << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}