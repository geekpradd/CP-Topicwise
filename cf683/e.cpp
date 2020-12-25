
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

int ans(int bit, vector<int>::iterator left, vector<int>::iterator right, int base){
	if (left == right) return 0;
	int num = 1LL << bit; num += base;
	int oth = 1LL << bit;
	// DUMP("huh");
	auto low = lower_bound(left, right, num);
	int pos = 0;

	if (low != right){
		if (bit != 0){
			pos = max(pos, 1+ans(bit-1, left, low, base));
		}
		else {
			if (left != low){
				pos = max(pos, 2LL);
			}
			else {
				pos = max(pos, 1LL);
			}
		}
	}
	else if (bit !=0){
			// DUMP("hsuh");

		pos = max(pos, ans(bit-1, left, right, base));
	}
	if (low != left){
		
		if (bit != 0){
			pos = max(pos, 1+ans(bit-1, low, right, num));

		}
		else {
			if (right != low){
				pos = max(pos, 2LL);
			}
			else {
				pos = max(pos, 1LL);
			}
		}
	}
	else if (bit !=0){
			// DUMP("hussh");

		pos = max(pos, ans(bit-1, left, right, num));
	}

	// DUMP(bit);
	// DUMP(base);
	// DUMP(pos);
	return pos;
}
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int count = ans(32, a.begin(), a.end(), 0);

	cout << n - count << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	
	return 0;
}