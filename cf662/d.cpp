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

void solve(){
	int n, m; cin >> n >> m;
	vector< vector<char> > grid(n, vector<char>(m));
	vector< vector<int> > l(n, vector<int>(m));

	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			cin >> grid[i][j];
			l[i][j] = 0;
		}
	}

	vector< vector<int> > c(n, vector<int>(m));
	int tot = 0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (i == 0){
				l[i][j] = 1;
			}
			else {
				if (grid[i][j] == grid[i-1][j])
					l[i][j] = 1 + l[i-1][j];
				else
					l[i][j] = 1;
			}
			int cap = (l[i][j]+1)/2;
			if (j == 0 || j == m-1){
				c[i][j] = 1; tot++;
			}
			else if (i == 0){
				c[i][j] = 1; tot++;
			}
			else {
				if (grid[i-1][j-1] == grid[i][j] && grid[i-1][j+1] == grid[i][j]){
					int pos = min(c[i-1][j-1], c[i-1][j+1]);
					if (pos < cap){
						c[i][j] = pos+1;
						tot += c[i][j];
					}
					else {
						c[i][j] = cap;
						tot += c[i][j];
					}
				}
				else {
					c[i][j] = 1; tot++;
				}
			}
		}
	}
	cout << tot << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}