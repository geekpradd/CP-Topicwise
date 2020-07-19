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

vector<bool> sieve(101, true);

void dfs(int cur, vector<int> adj[], int parent, int p, int depth, vector<int>&values){
	if (values[cur]%p == 0) return;
	if (depth == p){
		values[cur] *= p; return;
	}
	for (int to: adj[cur]){
		if(to == parent) continue;
		dfs(to, adj, cur, p, depth+1, values);
	}
}

void solve(){
	int n; cin >> n;
	vector<int> adj[n+1];
	vector<int> values(n+1, 1);
	REP1(i, n-1){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i=2; i<=n; ++i){
		if (sieve[i] == false) continue;
		vector<int> elements(n);
		for (int i=0; i<n; ++i)
			elements[i] = i+1;
		for (int j=1; j<=n; ++j){
			dfs(j, adj, -1, i, 1, values);
		}
	}
	for (int i=1; i<=n; ++i){
		d0(values[i]);
	}
	cout << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	for (int i=2; i<=100; ++i){
		if (sieve[i]==false) continue;
		for (int j=2*i; j<=100; j+=i){
			sieve[j] = false;
		}
	}
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}