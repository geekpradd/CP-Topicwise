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
	bool reversed = false;
	if (m > n){
		swap(n, m);
		reversed = true;
	}


	int ans = min(n+1, 2*m+1);
	int grid[n][m];
	for (int i=0; i<m; ++i){
		for (int j=0; j<m; ++j){
			grid[i][j] = (i+j)%m;
		}
		grid[i][0] = (grid[i][0]+1);
	}
	if (n > m){
		for (int j=0; j<m; ++j){
			grid[m][j] = j;
		}
		for (int j=1; j<m; ++j){
			grid[0][j] = m;
		}
	}
	for (int j=0; j<m; ++j){
		for (int i=m+1; i<n; ++i){
			grid[i][j] = i;
			if (i == m+j+1){
				grid[i][j]++;
			}
		}
	}
	if (!reversed){
		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j){
				d0(grid[i][j]);
			}
			cout << endl;
		}
	}
	else {
		for (int j=0; j<m; ++j){
			for (int i=0; i<n; ++i){
				d0(grid[i][j]);
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
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}