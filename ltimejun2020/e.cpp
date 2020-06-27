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
	set<int> vals;

	for (int i=0; i<n; ++i){
		int v; cin >> v;
		vals.insert(v);
	} 
	int least = 0;

	int prev = 0;
	int ans[n];
	bool pos = 1;
	for (int i=0; i<n; ++i){
		if (n%2 && i == n-1){

		}
		else {
			i = i^1;
		}
		
		if (i%2 == 0){
			int j = i^1;
			set<int>::iterator itr;
			if (n % 2 && i == n-1){
				itr = vals.upper_bound((prev));
			}
			else {
				itr = vals.upper_bound(max(prev, ans[j]));
			}
			// auto itr = vals.upper_bound(max(prev, ans[j]));
			// auto itr = vals.begin();
			if (itr == vals.end()){
				pos = 0; break;
			}
			ans[i] = *itr;
			vals.erase(itr);
			prev = ans[j];
		}
		else {
			ans[i] = *(vals.begin());
			// prev = ans[i];
			vals.erase(vals.begin());
		}

		i = i^1;
		
	}

	if (pos){
		cout << "YES" << endl;
		for (int i=0; i<n; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}