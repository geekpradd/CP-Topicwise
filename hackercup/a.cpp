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
	int n, k; cin >> n >> k;
	vector<int> s(n);
	vector<int> x(n);
	vector<int> y(n);

	int total = 0;
	for (int i=0; i<k; ++i){
		cin >> s[i];
		total += s[i];
	}
	int a, b, c, d; cin >> a >> b >> c >> d;
	int ps = s[k-1], pps = s[k-2];


	for (int i=k; i<n; ++i){
		s[i] = (a*pps + b*ps + c)%d;
		pps = ps;
		ps = s[i];
		total += s[i];
	}
	int low = 0;
	int lower = 0;
	for (int i=0; i<k; ++i){
		cin >> x[i];
		low += x[i];
		if (s[i] < x[i]){
			lower += x[i]-s[i];
		}
	}
	cin >> a >> b >> c >> d;
	ps = x[k-1], pps = x[k-2];

	for (int i=k; i<n; ++i){
		x[i] = (a*pps + b*ps + c)%d;
		pps = ps;
		ps = x[i];
		low += x[i];
		if (s[i] < x[i]){
			lower += x[i]-s[i];
		}
	}
	int high = 0;
	int upper = 0;
	for (int i=0; i<k; ++i){
		cin >> y[i];
		high += y[i]+x[i];
		if (s[i] > y[i]+x[i]){
			upper += s[i]-y[i]-x[i];
		}
	}
	cin >> a >> b >> c >> d;
	ps = y[k-1], pps = y[k-2];

	for (int i=k; i<n; ++i){
		y[i] = (a*pps + b*ps + c)%d;
		pps = ps;
		ps = y[i];
		high += y[i]+x[i];
		if (s[i] > y[i]+x[i]){
			upper += s[i]-y[i]-x[i];
		}
	}

	if (total < low || total > high){
		cout << -1 << endl;
		return;
	}

	cout << max(upper, lower) << endl;	


}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	for (int i=1; i<=t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
}