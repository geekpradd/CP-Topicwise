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

int dfs(int i, int p, vector<int> adj[], vector<int>&sum, int ps[]){
	sum[i] = ps[i];
	for (int to: adj[i]){
		if (to != p){
			sum[i] += dfs(to, i, adj,sum, ps);
		}
	}
	return sum[i];
}

void dfs2(int i, int par, vector<int> adj[], vector<int>&sum, int p[], int h[], bool&status){
	int current = h[i] + p[i];
	int res = 0;
	for (int to: adj[i]){
		if (to != par){
			res += h[to];
			dfs2(to, i, adj, sum, p, h, status);
		}
	}
	int val = current - res;
	if (val >= 0 && val%2 == 0){

	}
	else {
		status = 0;
	}
	if (h[i]>sum[i]){
		status = 0;
	}
}

void solve(){
	int n, m; cin >> n >> m;
	int p[n+1];
	for (int i=1; i<=n; ++i) cin >> p[i];
	int h[n+1];
	for (int i=1; i<=n; ++i) cin >> h[i];
	vector<int> adj[n+1];
	
	REP1(i, n-1){
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	bool status = true;
	vector<int> sum(n+1, 0);
	dfs(1, 1, adj, sum, p);
	dfs2(1, 1, adj, sum, p, h, status);

	if (status){
		d1("YES");
	}
	else {
		d1("NO");
	}

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
	
	return 0;
}	