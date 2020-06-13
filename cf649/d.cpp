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
struct custom {
	int i, dist, p;
};

void dfs(int cur, int dist, vector<int> adj[], int &odd, int &even, vector<int> &timer){
	if (dist%2) odd++;
	else
		even++;

	timer[cur] = dist;
	for (int to: adj[cur]){
		if (timer[to] == -1){
			dfs(to, dist+1, adj, odd, even, timer);
		}
	}
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> adj[n+1];
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	if (m != n-1){
		vector<int> dist(n+1, -1);
		vector<int> parent(n+1, -1);

		stack<custom> dfs;
		custom first = {1, 0, 0};
		dfs.push(first);
		vector<int> answer;
		while (!dfs.empty()){
			custom cur = dfs.top();
			dfs.pop();
			if (dist[cur.i] != -1) continue;
			dist[cur.i] = cur.dist;
			parent[cur.i] = cur.p;

			int u = cur.i;
			bool got = 0;
			for (int to: adj[u]){
				if (to == cur.p) continue;
				if (dist[to] == -1){
					custom th = {to, cur.dist + 1, u};
					dfs.push(th);
				}
				else {
					int z = dist[u] - dist[to] + 1;
					// cout << "at " <<  to << " from " << u << endl;
					while (u != to){
						answer.pb(u);
						u = parent[u];
					}
					answer.pb(to);
					got = 1;
					break;
				}
			}
			if (got){
				break;
			}
		}
		if (answer.size() > k){
			cout << 1 << endl;
			int number = k/2;
			if (k%2) number++;
			int total = 0;
			for (int i=0, j=0; i<answer.size() && j<number; i+=2, j++){
				cout << answer[i] << " ";
				total+=1;
			}
			assert(total == number);
			cout << endl;
		}
		else {
			cout << 2 << endl;
			cout << answer.size() << endl;
			for (int i=0; i<answer.size(); i+=1){
				cout << answer[i] << " ";
			}
			cout << endl;
		}
	}
	else {
		vector<int> timer(n+1, -1);
		int odd = 0, even = 0;
		dfs(1, 0, adj, odd, even, timer);

		int number = k/2;
		if (k%2) number++;
		if (number <= even){
			vector<int> values;
			for (int i=1; i<=n; ++i){
				if (timer[i]%2 == 0)
					values.pb(i);
			}
			cout << 1 << endl;
			assert(values.size()>=number);
			for (int i=0; i<number; ++i){
				cout << values[i] << " ";
			}
			cout << endl;
		}
		else {
			vector<int> values;
			for (int i=1; i<=n; ++i){
				if (timer[i]%2)
					values.pb(i);
			}
			assert(values.size()>=number);

			cout << 1 << endl;
			for (int i=0; i<number; ++i){
				cout << values[i] << " ";
			}
			cout << endl;
		}
		
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}