#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
	int n, a, b;
	cin >> n >> a >> b;
	if (a>=2*b){
		d1("Ankit"); return;
	}
	if (b>=2*a){
		if (n<=a){
			d1("Ankit");
		}
		else {
			d1("Deepanshu");
		}
		return;
	}
	vector<int> vals;
	vector<int> ulta;
	vector<int> marker;
	vals.pb(a);
	ulta.pb(b);
	vals.pb(2*b);
	ulta.pb(2*a);
	marker.pb(0);
	marker.pb(1);
	bool ank = true;
	int j = 2;
	int win_thres = E9;
	int los_thres = E9;
	while (true){
		if (ank){
			int value = vals[j-2]*a*2;
			int valul = ulta[j-2]*b*2;

			vals.push_back(value);
			ulta.pb(valul);
			marker.pb(0);
			if (value >= 2*valul){
				win_thres = value;
				break;
			}
			if (2*value<= valul){
				los_thres = value;
				break;
			}
			if (value > n)
				break;
			ank = false;
			j++;
		}
		else {
			int value = vals[j-2]*b*2;
			int valul = ulta[j-2]*a*2;
			vals.push_back(value);
			ulta.pb(valul);

			marker.pb(1);
			if (value > n)
				break;
			ank = true;
			j++;
		}
	}

	if (n > win_thres){
		d1("Ankit"); return;
	}
	if (n > los_thres){
		d1("Deepanshu"); return;
	}
	auto itr = lower_bound(vals.begin(), vals.end(), n);
	int index = itr - vals.begin();
	if (marker[index] == 0){
		d1("Ankit");
	}
	else {
		d1("Deepanshu");
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