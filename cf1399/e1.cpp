#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E13 10000000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define edge pair<int, pair<int, int> > 
#define REP0(i, n) for (int i=0; i<n; ++i)
#define REP1(i, n) for (int i=1; i<=n; ++i)
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
int n, m;
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

int dfs(int cur, vector<ii> adj[], vector<ii>&edges, int p){
	bool leaf = true;
	int tot = 0;
	for (ii &to: adj[cur]){
		if (to.first != p){
			leaf = false;
			int count = dfs(to.first,adj, edges, cur);
			edges[to.second].second = count;
			tot += count;
		}
	}
	if (!leaf)
		return tot;
	else
		return 1;

}

void solve(){
	int n, s; cin >> n >> s;
	vector<ii> adj[n+1];
	vector<ii> edges(n-1);
	for (int i=0; i<n-1; ++i){
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
		edges[i] = mp(w, 0);
	}
	dfs(1, adj, edges, 1);

	int current = 0;
	priority_queue<ii> best;
	for (int i=0; i<n-1; ++i){
		current += edges[i].first * edges[i].second;
		int diff = edges[i].first - (edges[i].first/2);
		best.push(mp(diff*edges[i].second, i));
	}
	int steps = 0;
	while (current > s){
		ii top = best.top();
		best.pop();
		current -= top.first;
		steps++;
		edges[top.second].first /= 2;
		int diff = edges[top.second].first - (edges[top.second].first/2);
		if (diff != 0)
			best.push(mp(diff*edges[top.second].second, top.second));
	}

	cout << steps << endl;

}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
	}
}