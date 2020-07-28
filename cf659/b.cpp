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
	int n, k, l; cin >> n >> k >> l;
	vector<int> d(n);
	bool pos = 1;
	for (int i=0; i<n; ++i) {
		cin >> d[i];
		if (d[i] > l)
			pos = 0;
	}
	if (!pos){
		d1("No");
		return;
	}
	vector<ii> zones(n, mp(-1, -1));

	for (int i=0; i<n; ++i){
		int gap = l - d[i];
		if (d[i]+k <= l){
			continue;
		}
		zones[i] = (mp((2*k-gap)%(2*k), gap));
	}
	ii prev; bool rot = 0;
	bool got = 0;
	int got_index;
	for (int i=0; i<n; ++i){
		// DUMP(zones[i]);
		// DUMP(i);
		if (zones[i].first==-1) {
			got = 0; rot = 0;
			continue;
		}
		if (!got){
			got = 1; got_index = i;
			prev = zones[i];
		}
		else {
			if (prev.first == 0){
				rot = true;
			}
			// DUMP(rot);
			// DUMP(prev);
			if (rot){
				prev.first++;
				if (prev.first > zones[i].second){
					pos = 0; break;
				}
				prev.second = zones[i].second;
			}
			else if (prev.first >= zones[i].first){
				prev.first = (prev.first+1)%(2*k);
				// cout << "here" << endl;
				if (zones[i].first == 0){
					prev.first = 0;
				}
				if (prev.first == 0){
					rot = true;
				}
				prev.second = zones[i].second;
			}
			else {
				prev = zones[i];
				prev.first = (prev.first)%(2*k);
				if (prev.first == 0){
					rot = true;
				}
			}
		}
	}
	if (pos){
		d1("Yes");
	}
	else {
		d1("No");
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