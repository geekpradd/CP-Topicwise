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

void dfs(int i, stack<int>&tops, vector<int> adj[], vector<int> &visited, bool &pos, int &time, vector<int> &tin, vector<int> &tout){
	visited[i] = true;
	tin[i] = time;
	time++;
	for (int to: adj[i]){
		if (visited[to]){
			if (tout[to] == -1){
				pos = false;
				break;
			}
	
		}
		if (!visited[to])
			dfs(to, tops, adj, visited, pos, time, tin, tout);
	}
	tops.push(i);
	tout[i] = time;
	time++;
}
void solve(){
	int n, m; cin >> n >> m;
	vector<int> adj[n+1];
	vector<ii> others;
	vector<ii> normals;
	for (int i=0; i<m; ++i){
		int t, x, y; cin >> t >> x >> y;
		if (t){
			adj[x].pb(y);
			normals.pb(mp(x, y));
		}
		else {
			others.pb(mp(x, y));
		}
	}
	stack<int> tops;
	vector<int> visited(n+1, 0);
	vector<int> tin(n+1, -1);
	vector<int> tout(n+1, -1);
	bool pos = true;
	int time = 0;
	for (int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i, tops, adj, visited, pos, time, tin, tout);
		}
	}
	if (!pos){
		d1("NO");
		return;
	}
	vector<int> count(n+1, 0);
	int k = 0;
	while (!tops.empty()){
		int to = tops.top();
		tops.pop();
		count[to] = k;
		k++;
	}
	// for (int i=0; i<normals.size(); ++i){
	// 	if (count[normals[i].first] > count[normals[i].second]){
	// 		d1("ERROR");
	// 	}
	// }
	for (int i=0; i<others.size(); ++i){
		if (count[others[i].first] > count[others[i].second]){
			others[i] = mp(others[i].second, others[i].first);
		}
	}
	d1("YES");
	for (ii cur: normals){
		d2(cur.first, cur.second);
	}
	for (ii cur: others){
		d2(cur.first, cur.second);
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