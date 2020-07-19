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

void cleanse(int &ans, vector<bool> &killed, vector<int>& leaf_children, vector<in){
	if (leafch_count[i] > k){
		int offset = leafchild[i].size() - leafch_count[i];
		int cycles = leafch_count[i]/k;
		ans += cycles;
		leafch_count[i] -= k*cycles;
		for (int i=0; i<k*cycles; ++i){
			killed[leaf_children[i][offset+i]] = 1;
		}
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> adj[n+1];
	REP1(i, n-1){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	int ans = 0;
	vector<bool> killed(n+1, false);
	vector<int> leaf_children[n+1];
	vector<int> leafch_count(n+1, 0);
	vector<bool> leaf(n+1, false);
	REP1(i, n){
		if (adj[i].size() == 1){
			leaf[i] = 1;
			leafchild[adj[i][0]].pb(i);
			leafch_count[adj[i][0]]++;
		}
	}
	REP1(i, n){
		
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