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
// adjacency list of graph


void dfs(int v, vector< vector<int> > &adj, vector<bool> &visited, vector<int> &ans, vector<int> &depth) {
    visited[v] = true;
    bool got = false;
    int baap;
    for (int u : adj[v]) {
        if (!visited[u]){
        	got = true;
            dfs(u, adj, visited, ans, depth);
            baap = depth[u];
        }
    }
    if (!got){
    	depth[v] = 1;
    }
    else {
    	depth[v] = 1 + baap;
    }
    ans.push_back(v);
}

void topological_sort(int n, vector< vector<int> > &adj, vector<bool> &visited, vector<int> &ans, vector<int> &depth) {
    visited.assign(n+1, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i, adj, visited, ans, depth);
    }
    reverse(ans.begin(), ans.end());
}

void add( vector<int> &final, int &ind, int node, vector< vector<int> > & rev, vector<bool> &stop){
	
	for (int to: rev[node]){
		if (stop[to]) continue;
		add(final, ind, to, rev, stop);
	}
	final[ind] = node;
	// cout << "ind for " << node  <<  " is " << ind << endl;
	ind++;
}

void solve(){
	int n;  cin >> n;
	vector<int> a(n+1);
	for (int i=1; i<=n; ++i) cin >> a[i];

	vector<int> b(n+1);
	vector< vector<int> > adj(n+1);
	vector< vector<int> >  rev(n+1);
	vector<bool> visited;
	vector<int> ans;
	for (int i=1; i<=n; ++i){
		cin >> b[i];
		if (b[i] != -1){
			adj[i].pb(b[i]);
			rev[b[i]].pb(i);
		}
	}
	vector<int> depth(n+1);
	topological_sort(n, adj, visited, ans, depth);
	int out = 0;
	vector<bool> stop(n+1, false);
	vector<ii> order;
	for (int i=0; i<n; ++i){
		out += a[ans[i]];
		if (a[ans[i]] >= 0){
			if (b[ans[i]] != -1)
				a[b[ans[i]]] += a[ans[i]];
			else {
				stop[ans[i]] = true;
			}
		}
		else {
			stop[ans[i]] = true;
		}
		if (stop[ans[i]]){
			order.pb(mp(depth[ans[i]], ans[i]));
		}
	}
	sort(order.begin(), order.end());
	vector<int> final(n);
	int counter = 0;
	for (int i=0; i<order.size(); ++i){
		int node = order[i].second;
		if (!stop[node]) continue;
		add(final, counter, node, rev, stop);
	}
	cout << out << endl;
	for (int i=0; i<n; ++i){
		cout << final[i] << " ";
	}
	cout << endl;


}

signed main(){
		#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solve();
	
	return 0;
}