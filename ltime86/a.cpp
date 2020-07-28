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


}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int cap = 2000000;
	vector<int> g(cap+1), freq(cap+1);
	vector<int> s(cap+1);
	g[1] = 1;
	s[1] = 1;
	freq[1] = 1;
	for (int i=2; i<=cap; ++i){
		g[i] = 1 + g[i - g[g[i-1]]];
		freq[i] = freq[i-1] + g[i];
		s[i] = (s[i-1] + ((i*i)%MOD*g[i])%MOD)%MOD;
	}
	// DUMP(freq[cap]);
	// DUMP(g[cap]);
	// cout << g << endl;
	// cout << freq << endl;
	// cout << s << endl;
	int t; cin >> t;
	while (t--){
		int l, r; cin >> l >> r;
		l--;
		auto itr = lower_bound(freq.begin(), freq.end(), l);
		if (*itr != l){
			itr--;
		}
		int li = itr - freq.begin();
		// DUMP(li);
		auto itr2 = lower_bound(freq.begin(), freq.end(), r);
		if (*itr2 != r){
			itr2--;
		}
		int ri = itr2 - freq.begin();
		// DUMP(ri);
		int first_val = (s[li] + ((l-freq[li])*((li+1)*(li+1))%MOD)%MOD)%MOD;
		int second_val = (s[ri] + ((r-freq[ri])*((ri+1)*(ri+1))%MOD)%MOD)%MOD;
		// DUMP(first_val);
		// DUMP(second_val);
		int ans = second_val - first_val;
		if (ans < 0)
			ans += MOD;
		cout << ans << endl;

	}
	
	return 0;
}