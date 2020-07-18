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
	int a[n+1];
	int total = 0;
	int s[n+1];
	for (int i=1; i<=n; ++i){
		cin >> a[i]; total += a[i];
		if (i == 1 || i == 2){
			s[i] = a[i];
		}
		else {
			s[i] = a[i] + s[i-2];
		}
	} 
	if (n==1){
		cout << a[1] << endl;
		return;
	}
	int r = n/2;
	int min_rem = 100000000000000000;
	for (int i=1; i<=n; ++i){
		int left = n - i + 1;
		int cap = (left + 1)/2;
		if (cap >= r){
			int final = i + 2*(r-1);
			int val = s[final];
			if (i >= 3){
				val -= s[i-2];
			}
			min_rem = min(min_rem, val);
		}
		else {
			int rem = (r - cap);
			int val = (i%2 ? s[n]  : s[n-1]);
			if (i >= 3){
				val -= s[i-2];
			}
			val += (i%2 ? s[2*rem] : s[2*rem-1]);
			min_rem = min(min_rem, val);
		}
	}
	cout << total - min_rem << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}