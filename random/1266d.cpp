#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
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
 	vector<int> inflow(n+1, 0), outflow(n+1, 0);
 	REP0(i, m){
 		int u, v; cin >> u >> v;
 		int d; cin >> d;
 		inflow[v] += d; outflow[u] += d;
 	}
 	vector<int> positive, negative;
 	vector<int> vals(n+1);
 	REP1(i, n){
 		vals[i] = inflow[i] - outflow[i];
 		if (inflow[i] > outflow[i]){
 			positive.pb(i);
 		}
 		else if(outflow[i] > inflow[i]) {
 			negative.pb(i);
 			vals[i] = -vals[i];
 		}
 	}
 	vector< pair< pair<int, int>, int> > outs;

 	int l = 0, r = 0;
 	while (l < positive.size() && r < negative.size()){
 		if (vals[positive[l]] < vals[negative[r]]){
 			outs.pb(mp(mp(negative[r], positive[l]),vals[positive[l]]));
 			vals[negative[r]] -= vals[positive[l]];
 			l++;
 		}
 		else if (vals[positive[l]] > vals[negative[r]]){
 			outs.pb(mp(mp(negative[r], positive[l]),vals[negative[r]]));
 			vals[positive[l]] -= vals[negative[r]];
 			r++;
 		}
 		else{
 			outs.pb(mp(mp(negative[r], positive[l]),vals[negative[r]]))	;
 			r++; l++;
 		}
 	}

 	d1(outs.size());
 	for (int i=0; i<outs.size(); ++i){
 		d3(outs[i].first.first, outs[i].first.second, outs[i].second);
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