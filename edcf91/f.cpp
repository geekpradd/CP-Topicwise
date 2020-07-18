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
	int n, k; cin >> n >> k;
	int prev_e = 0,  prev_o = 0, prev_u = 0;
	int prev_up = 2*n + 1;
	int ans = -1;

	while (n > 0){
		int up = n;
		int low = (n >> 1) + 1;

		int odd_val = (1 + prev_e);
		int even_val = 2*odd_val;

		int up_val;
		if (up%2){
			up_val = odd_val;
		}
		else {
			up_val = odd_val + prev_o;
		}
		if (odd_val >= k){
			if (up%2)
				ans = max(ans, up);
			else 
				ans = max(ans, up - 1);
		}
		else if (up_val >= k){
			ans = max(ans, up);
		}
		if (even_val >= k){
			if (up%2)
				ans = max(ans, up-1);
			else
				ans = max(ans, up-2);
		}

		DUMP(up);
		DUMP(even_val);
		DUMP(odd_val);
		DUMP(up_val);
		if (ans != -1)
			break;

		prev_e = even_val;
		prev_o = odd_val;
		n = n >> 1;
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