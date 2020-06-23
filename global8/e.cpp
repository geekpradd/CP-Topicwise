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
struct cus {
	int a, b, c;
};
bool comp(cus &a, cus& b){
	return a.c > b.c;
}
void solve(){
	int n, m; cin >> n >> m;
	vector<int> adj[n+1];
	for (int i=0;i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	
	int total = 0;
	vector<cus> vals;
	for (int i=1; i<=n; ++i){
		for(int to: adj[i]){
			for (int tt: adj[to]){
				cus x = {i, to, tt};
				vals.pb(x);
			}
		}
	}
	// sort(vals.begin(), vals.end(), comp);
	vector<int> rem;
	vector<bool> removed(n+1, false);
	for (int i=0; i<vals.size(); ++i){
		if (!removed[vals[i].a] && !removed[vals[i].b] && !removed[vals[i].c]){
			rem.pb(vals[i].b);
			removed[vals[i].b] = true;
		}
	}
	cout << rem.size() << endl;
	for (int z: rem){
		cout << z <<  " ";
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}