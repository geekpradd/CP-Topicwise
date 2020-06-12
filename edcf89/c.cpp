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

void solve(){
	int n, m; cin >> n >> m;
	int grid[n][m];
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j)
			cin >> grid[i][j];
	}
	int total = (n-1) + (m-1) + 1;
	int step = total/2;
	
	vector<int> zer(step, 0);
	 vector<int> one(step, 0);
	int mid_z = 0, mid_o = 0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			int dist_a = (i+j);
			int dist_b = (n-1 + m - 1) - (i+j);
			if (dist_a == dist_b){
				if (grid[i][j])
					mid_o++;
				else
					mid_z++;
			}
			else {
				int dist = min(dist_a, dist_b);
				if (grid[i][j])
					one[dist]++;
				else
					zer[dist]++;
			}
		}
	}
	int ans = 0;
	for (int i=0; i<step; ++i){
		ans += min(zer[i], one[i]);
	}
	cout << ans << endl;
	
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