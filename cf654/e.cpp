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
	for (int i=0; i<n; ++i){
		min_v = max(min_v, a[i]-i);
	}
	// cout<< min_v << endl;
	vector<int> outs;
	for (int i=min_v; i<=3000; ++i){
		int used = 0;
		bool div = 0;
		for (int j=n-1; j>=0; --j){
			int out;
			if (a[j] <= i){
				out = n - used;
			}
			else {
				int min_pos = a[j] - i;
				out = n - min_pos  - used;
			}
			// if (i == 3){
			// 	cout<< "at j " << j << " out " << out << endl;

			// }
			if (out%p == 0){
				div = 1; break;
			}
			used++;
		}
		if (!div){
			outs.pb(i);
		}
	}
	cout << outs.size() << endl;
	for (int z: outs){
		cout << z << " ";
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