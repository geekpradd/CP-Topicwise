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

int re(vector<int> &v){
	if (v.size() == 1){
		return 1;
	}
	if (v.size() == 0){
		return 0;
	}
	int mx = E13;
	int mi = -1;
	for (int i=0; i<v.size(); ++i){
		if (v[i] < mx){
			mx = v[i];
			mi = i;
		}
	}
	vector<int> cp = v;
	for (int i=0; i<v.size(); ++i){
		cp[i] -= mx;
	}
	vector< vector<int> > vals;
	vector<int> cur;
	for (int i=0; i<v.size(); ++i){
		int vx; vx = cp[i];
		if (vx == 0){
			if (cur.size()){
				vals.push_back(cur);
				vector<int> nn;
				cur = nn;
			}
		}
		else {
			cur.pb(vx);
		}
	}
	if (cur.size()){
		vals.push_back(cur);
	}

	int ans = 1;
	for (vector<int> &g: vals){
		ans += re(g);
	}

	for (int i=0; i<v.size(); ++i){
		vector<int> left(v.begin(), v.begin()+i);
		vector<int> right(v.begin()+i+1, v.end());
		int cur_ans = 1 + re(left) + re(right);
		ans = min(ans, cur_ans);
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector< vector<int> > vals;
	vector<int> cur;
	for (int i=0; i<n; ++i){
		int v; cin >> v;
		if (v == 0){
			if (cur.size()){
				vals.push_back(cur);
				vector<int> nn;
				cur = nn;
			}
		}
		else {
			cur.pb(v);
		}
	}
	if (cur.size()){
		vals.push_back(cur);
	}
	int ans = 0;
	for (int i=0; i<vals.size(); ++i){
		ans += re(vals[i]);
	}
	d1(ans);
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	
	return 0;
}