#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 100000000
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



void solve(){
	int n, m; cin >> n;
	
	string first; cin >> first;
	m = first.size();
	char grid[n][m];
	REP0(j, m){
		grid[0][j] = first[j];
	}
	REP1(i, n-1){
		REP0(j, m){
			cin >> grid[i][j];
		}
	}
	vector<int> adj[26];
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (i!=0){
				if (grid[i-1][j] != grid[i][j]){
					adj[grid[i][j]-'a'].pb(grid[i-1][j] - 'a');
				}
			}
			if (i!=n-1){
				if (grid[i+1][j] != grid[i][j]){
					adj[grid[i][j]-'a'].pb(grid[i+1][j] - 'a');
				}
			}
			if (j!=0){
				if (grid[i][j-1] != grid[i][j]){
					adj[grid[i][j]-'a'].pb(grid[i][j-1] - 'a');
				}
			}
			if (j!=m-1){
				if (grid[i][j+1] != grid[i][j]){
					adj[grid[i][j]-'a'].pb(grid[i][j+1] - 'a');
				}
			}
		}
	}
	vector<int> dist(26, E9);
	vector<bool> visited(26, false);
	queue<int> bfs;
	bfs.push(grid[0][0]-'a');
	dist[grid[0][0]-'a'] = 0;
	while (!bfs.empty()){
		int top = bfs.front();
		bfs.pop();
		if(visited[top]) continue;
		visited[top] = 1;

		for (int to: adj[top]){
			if (!visited[to]){
				if (1 + dist[top] < dist[to]){
					dist[to] = 1 + dist[top];
					bfs.push(to);
				}
			}
		}
	}

	d1(dist[grid[n-1][m-1]-'a']);

	
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}