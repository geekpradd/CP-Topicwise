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
	int p, f; cin >> p >> f;

	int x, y; cin >> x >> y;
	int s, w; cin >> s >> w;

	if (s > w){
		swap(s,w);
		swap(x, y);
	}
	int cap_p = p/s; int cap_f = f/s;
	int left_p = p%s; int left_f = f%s;
	if (cap_p + cap_f <= x){
		cout << cap_p + cap_f << endl;
	}
	else {
		// cout << "gonna take " << x << endl;

		int total = x;
		int c = cap_f + cap_p - x;
		// cout << c << endl;
		int best = 0;
		for (int i=	0; i<=min(c, cap_p); ++i){
			if ((c-i)>cap_f){
				continue;
			} 
			int s1 = left_p + i*s;
			int s2 = left_f + (c-i)*s;
			int value = (s1/w) + (s2/w);
			if (value > y){
				value = y;
			}
			// cout << "at " << i << " got " << value << endl;
			// cout << "s1 " << s1 << endl;
			// cout << "s2 " << s2 << endl;
			best = max(best, value);
		}
		cout << total + best << endl;
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