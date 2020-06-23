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
	int n; cin >> n;
	int iters = n/2;
	vector<ii> points;
	points.pb(mp(0, 1)); points.pb(mp(1, 1));
	for (int i=0; i<iters; ++i){
		points.pb(mp(3*i+2, 1));
		points.pb(mp(3*i+3, 1));
		points.pb(mp(3*i+2, 0));
		points.pb(mp(3*i+3, 0));
		points.pb(mp(3*i+2, 2));
		points.pb(mp(3*i+3, 2));
		points.pb(mp(3*i+4, 1));
	}
	int last = 3*(iters-1) + 4;
	if (n%2){
		points.pb(mp(last+1, 1));
		points.pb(mp(last+2, 1));
		points.pb(mp(last+1, 0));
		points.pb(mp(last+2, 0));
		points.pb(mp(last+1, 2));
		points.pb(mp(last+1, 3));
	}
	else {
		points.pb(mp(last+1, 1));
		points.pb(mp(last+1, 2));
		points.pb(mp(last+1, 3));
	}
	points.pb(mp(0, 2));
	points.pb(mp(0, 3));
	for (int i=0; i<=last+1; ++i){
		points.pb(mp(i, 4));
	}
	cout << points.size() << endl;
	for (ii z: points){
		cout << z.first << " " << z.second << endl;
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