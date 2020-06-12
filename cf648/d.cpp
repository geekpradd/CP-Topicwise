#include <bits/stdc++.h>
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

void solve(){
	int n, m; cin >> n >> m;
	vector< vector<int> > grid(n, vector<int>(m));
	vector<ii> gg;
	vector<ii> bb;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			char x; cin >> x;
			if (x == '.')
				grid[i][j] = 0;
			else if (x == '#')
				grid[i][j] = 1;
			else if (x == 'G'){
				gg.pb(mp(i, j));
				grid[i][j] = 2;
			}
			else if (x == 'B'){
				bb.pb(mp(i, j));
				grid[i][j] = 3;
			}
		}
	}
	bool pos = 1;
	for (ii x: bb){
		int i = x.first, j = x.second;

		if (i != 0){
			if (grid[i-1][j] == 2){
				pos = 0; break;
			}
			grid[i-1][j] = 1;
		}
		if (i != n-1){
			if (grid[i+1][j] == 2){
				pos = 0; break;
			}
			grid[i+1][j] = 1;
		}
		if (j != 0){
			if (grid[i][j-1] == 2){
				pos = 0; break;
			}
			grid[i][j-1] = 1;
		}
		if (j != m-1){
			if (grid[i][j+1] == 2){
				pos = 0; break;
			}
			grid[i][j+1] = 1;
		}

		grid[i][j] = 1;
	}


	vector< vector<bool> > visited(n, vector<bool>(m, false));
	queue<ii> bfs;
	if (grid[n-1][m-1] != 1){
		bfs.push(mp(n-1, m-1));
		while (!bfs.empty()){
			ii cur = bfs.front();
			bfs.pop();
			int i = cur.first, j = cur.second;
			visited[i][j] = 1;
			if (i != 0){
				if (grid[i-1][j] != 1 && !visited[i-1][j]){
					visited[i-1][j] = 1;
					bfs.push(mp(i-1, j));
				}
			}
			if (j != 0){
				if (grid[i][j-1] != 1 && !visited[i][j-1]){
					visited[i][j-1] = 1;
					bfs.push(mp(i, j-1));
				}
			}
			if (i != n-1){
				if (grid[i+1][j] != 1 && !visited[i+1][j]){
					visited[i+1][j] = 1;
					bfs.push(mp(i+1, j));
				}
			}
			if (j != m-1){
				if (grid[i][j+1] != 1 && !visited[i][j+1]){
					visited[i][j+1] = 1;
					bfs.push(mp(i, j+1));
				}
			}
		}	
	}
	
	for (ii y: gg){
		if (!visited[y.first][y.second]){
			pos = 0;
		}
	}
	
	if (pos){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
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