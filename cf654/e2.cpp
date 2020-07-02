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
	int n, p; cin >> n >> p;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	int min_v = 0;
	int upper = 0;
	for (int i=0; i<n; ++i){
		min_v = max(min_v, a[i]-i);
		upper = max(upper, a[i]);
	}
	// cout<< min_v << endl;
	// d1(upper);
	int lower = min_v;
	vector<ii> residues(p, mp(0, 0));
	for (int i=0; i<n; ++i){
		int k = i+1;
		int resid = (a[i] - k)%p; 
		if (resid < 0) resid += p;
		if (residues[resid].first){
			residues[resid].second = max(residues[resid].second, a[i]);
		}
		else {
			residues[resid] = mp(1, a[i]);
		}
		if(k%p == 0){
			upper = min(upper, a[i]-1);
		}		
	}
	
	vector<int> cands;
	// d1(lower);
	// d1(upper);
	for (int i=lower; i<= upper; ++i){
		int res = i%p;
		if (residues[res].first){
			if (i>residues[res].second){
				cands.pb(i);
			}
		}
		else {
			cands.pb(i);
		}
	}

	d1(cands.size());

	for (int z: cands){
		d0(z);
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}