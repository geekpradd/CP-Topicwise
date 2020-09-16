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
	int n; cin >> n;
	int a[n+1];
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}
	vector< vector<int> >  pref(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; ++i){
		pref[i][a[i]] = 1 + pref[i-1][a[i]];
		for (int j=1; j<=n; ++j){
			if (j == a[i]) continue;
			pref[i][j] = pref[i-1][j];
		}
	}
	// cout << pref[3][1] << endl;
	// cout << pref[1][1] << endl;
	vector< vector<int> >  pairs(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; ++i){
		for (int j=i+1; j<=n; ++j){
			int current = pref[j-1][a[j]] - pref[i-1][a[j]];
			pairs[i][j] = current + pairs[i][j-1];
				// DUMP(i);
				// DUMP(j);
				// DUMP(pairs[i][j]);
		}
	}
	int ans = 0;
	vector<int>  count(n+1, 0);
	for (int i=1; i<=n; ++i){
		int found = 0;
		for (int k=1; k<i; ++k){
			if (a[k]!=a[i]) continue;
			found++;
			int total = count[i-1] - count[k];
			// DUMP(i);
			// DUMP(k);
			// DUMP(total);
			total -= pairs[k][i-1];
			// cout << "now" << endl;
			// DUMP(total);
			ans += total;
		}
		count[i] = count[i-1] + found;
	}
	d1(ans);
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