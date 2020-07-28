#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000007
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

int dfs(int cur, vector<int> adj[], vector<int> & dp, int p){
	if (adj[cur].size()==1){
		dp[cur] = 1;
		return E9;
	}
	int min_a = E9, min_b = E9;
	int ans = E9;
	for (int to: adj[cur]){
		if (to != p){
			ans = min(ans, dfs(to, adj, dp, cur));
			if (dp[to] < min_a){
				min_b = min_a;
				min_a = dp[to];
			}
			else if (dp[to] < min_b){
				min_b = dp[to];
			}
		}
	}
	dp[cur] = 1 + min_a;

	if (min_a != E9 && min_b != E9){
		return min(ans, 1 + min_a + min_b);
	}
	else{
		return ans;
	}
}
void solve(){
	int n; int k; cin >> n >> k;
	vector<int> adj[n+1];
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i=0; i<n-1; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int root = -1;
	for (int i=1; i<=n; ++i){
		if (adj[i].size() != 1){
			root = i; break;
		}
	}
	vector<int> dp(n+1);
	int value;
	if (n==2){
		value = 2;
	}
	else {
		value = dfs(root, adj, dp, root);
	}


	int rem = k%(2*value);
	int cyc = k/(2*value);
	int ans = 0;
	if (cyc != 0){
		int counter = 2*value;
		for (int i=n-1; counter>0; i--){
			ans += cyc*a[i]*2;
			counter -=2;
		}
	}
	bool ot = 0;
	if (rem == 1){
		ans += a[n-1];
	}
	else if (rem == 2){
		ans += a[n-1] + a[n-2];
	}
	else if (rem == 3){
		ans += 2*a[n-1] + a[n-2];
	}
	else {
		if (rem % 2){
			ot = 1;
		}
		int z = rem/2;
		int i;
		for (i=n-1; z>0; --i){
			ans += 2*a[i];
			z--;
		}
		if (ot){
			ans += a[i];
		}

	}
	
	cout << ans << endl;
	
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	// DUMP(freq[cap]);
	// DUMP(g[cap]);
	// cout << g << endl;
	// cout << freq << endl;
	// cout << s << endl;
	int t; cin >> t;
	while (t--){
		solve();

	}
	
	return 0;
}