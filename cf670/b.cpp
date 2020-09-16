
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
	vector<int> p, ne;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		if (x >= 0){
			p.pb(x);
		}
		else {
			ne.pb(x);
		}
	}
	sort(p.begin(), p.end());
	sort(ne.begin(), ne.end());
	if (n == 5){
		int a = 1;
		for (int i=0; i<p.size(); ++i)
			a = a*p[i];
		for (int i=0; i<ne.size(); ++i)
			a = a*ne[i];

		cout << a << endl;
		return;
	}

	if (p.size() == 0){
		int a = 1;
		int tot = 0;
		for (int i=(((int)ne.size())-1); i>=0; --i){
			if (tot == 5){
				break;
			}
			a = a*ne[i];
			tot++;
		}
		cout << a << endl;
	}
	else {
		int best = -E13;
		for (int pp = 1; pp <=5; pp+=2){
			if (pp > p.size()) break;
			int other = 5 - pp;
			if (other > ne.size()) continue;
			int cur = 1;
			int tot = 0;
			for (int i=(((int)p.size())-1); i>=0; --i){
				if (tot == pp){
					break;
				}
				cur = cur*p[i];
				tot++;
				
			}
			for (int i=0; i<=5 ; ++i){
				if (tot == 5){
					break;
				}
				cur = cur*ne[i];
				tot++;
			}
			best = max(best, cur);
		}
		cout << best << endl;
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