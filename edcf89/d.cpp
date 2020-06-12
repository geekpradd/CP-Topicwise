#include <bits/stdc++.h>
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
	vector<int> sieve(10000001, 0);
	for (int i=2; i<=10000000; ++i){
		if (sieve[i] != 0) continue;
		for (int j=2*i; j<=10000000; j+=i)
			sieve[j] = i;
	}
	int n; cin >> n;
	ii ans[n];
	for (int i=0; i<n; ++i){
		int num; cin >> num;
		if (sieve[num] == 0){
			ans[i] = mp(-1, -1); continue;
		}
		int rest = num;
		int div = sieve[num];
		while (rest % div == 0){
			rest = rest/div;
		}
		if (rest == 1){
			ans[i] = mp(-1, -1); continue;
		}
		else {
			ans[i] = mp(rest, num/rest);
		}
	}
	for (int i=0; i<n; ++i){
		cout << ans[i].first << " ";
	}
	cout << endl;
	for (int i=0; i<n; ++i){
		cout << ans[i].second << " ";
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