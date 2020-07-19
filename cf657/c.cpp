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
	vector<ii> a(m+1);
	int b[m+1];
	for (int i=1; i<=m; ++i){
		cin >> a[i].first >> b[i];
		a[i].second = i;
	}
	sort(a.begin()+1, a.end());
	int inverse[m+1];
	vector<int> aa(m);
	for (int i=1; i<=m; ++i){
		inverse[a[i].second] = i;
		aa[i-1] = a[i].first;
	}
	int pref[m+1]; pref[0] = 0;
	for (int i=1; i<=m; ++i){
		pref[i] = pref[i-1] + a[i].first;
	}
	int ans = -1;
	if (n <= m){
		ans = max(ans, pref[m] - pref[m-n]);
	}
	for (int i=1; i<=m; ++i){
		auto itr = upper_bound(aa.begin(), aa.end(), b[i]);
		if (itr != aa.end()){
			int pos = itr-aa.begin();
			int used = (m-pos);
			if (used < n){
				int value = pref[m] - pref[pos];
				int val;
				if (inverse[i]>=(1+pos)){
					val = value + (n-used)*b[i];
				}
				else {
					val = value + a[inverse[i]].first + (n-used-1)*b[i];
				}
				ans = max(ans, val);
			}			
		}
		else {
			int val = (n-1)*b[i] + a[inverse[i]].first;
			ans = max(ans, val);
		}
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