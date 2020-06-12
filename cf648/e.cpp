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

int ans(vector<int> &a, int n, int bit){
	sort(a.begin(), a.end());
	int checker = 1LL << bit;
	int an = 0;
	vector<int> b;
	if (checker & a[n-1]){
		int first = -1;
		for (int i=n-1; i>=0; --i){
			if (checker & a[i]){
				b.pb(a[i] - checker);
			}
			else {
				if (first == -1){
					b.pb(a[i]);
					first = 0;
				}
				else if (first == 0){
					b.pb(a[i]);
					break;
				}
			}
		}
		an += checker;
		if (bit != 0)
			an += ans(b, b.size(), bit-1);
	}
	else {
		if (bit != 0)
			an += ans(a, n, bit-1);
	}
	
	

	return an;
	
}
void solve(){
	int n; cin >> n;
	set<int> a;
	for (int i=0; i<n; ++i){
		int val; cin >> val;
		a.insert(val);
	}	
	vector<int> b;
	for (auto itr = a.begin(); itr != a.end(); ++itr){
		b.push_back(*itr);
	}
	
	vector<int> vv[63];
	for (int i=62; i>=0; --i){
		int checker = 1LL << i;
		for (int j=0; j<b.size(); ++j){
			if (checker & b[j]){
				vv[i].pb(j);
			}
		}
	}
	int cap = 2;
	int ans = 0;
	bool hav = 0;
	vector<int> prev;
	for (int i=62; i>=0; --i){
		if (vv[i].size() == 0) continue;
		if (!hav){
			hav = 1;
			prev = vv[i];
			ans += (1LL << i);
		}
		else {
			vector<int> oth;
			for (int z: prev){
				if (binary_search(vv[i].begin(), vv[i].end(), z))
					oth.push_back(z);
			}
			if (oth.size()){
				prev = oth;
				ans += (1LL << i);
			}
			else {
				cap--;
				hav = 0;
				if (cap >= 0){
					ans += (1LL << i);
				}
				else {
					break;
				}
			}
		}
	}
	cout << ans << endl;
}	


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}