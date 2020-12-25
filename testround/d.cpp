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
ii dfs(int cur, vector<bool> &visited, vector<int> adj[]){
	ii ans = mp(1, adj[cur].size());
	visited[cur] = 1;
	for (int to: adj[cur]){
		if (!visited[to]){
			ii v = dfs(to, visited, adj);
			ans.first += v.first;
			ans.second += v.second;
		}
	}

	return ans;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;	
	vector<int> adj[n+1];
	REP0(i, m){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<bool> visited(n+1, false);
	vector<ii> comps;
	for (int i=1; i<=n; ++i){
		if (!visited[i]){
			comps.pb(dfs(i, visited, adj));
		}
	}
	int red = 0;
	sort(comps.begin(), comps.end(), greater<ii>());
	for (ii &v: comps){
		int ed = v.second/2;
		int extra = ed - v.first + 1;
		red += extra;
	}

	// cout << comps << endl;
	int used = 0;
	bool free = 1;
	int big = comps[0].first;
	int i = 1;
	for (;i<comps.size(); ++i){
		if (used == red){
			free = 0;
		}
		if (used == k){
			break;
		}
		used++;
		
		if (free){
			big += comps[i].first;
		}
		else {
			big += comps[i].first - 1;
		}

		
		
	}
	int ans = (big*(big-1))/2;
	for (int j=i; j<comps.size(); ++j){
		ans += (comps[j].first*(comps[j].first-1))/2;
	}

	cout << ans << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	
	return 0;
}