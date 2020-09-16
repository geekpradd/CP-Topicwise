
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
	int n, k; cin >> n >> k ;
	string s; cin >> s;
	bool pos = 1;
	int z = 0, o = 0;
	int q = 0;
	int qz = 0, qo = 0;
	for (int i=0; i<k; ++i){
		if (s[i]=='0') z++;
		else if (s[i]=='1') o++;
		else q++;
	}
	int l = k/2;
	if (l < z|| l <o) pos = 0;
	else {
		qz = (l-z); qo = (l-o);
	}
	int prev_q = q;
	for (int i=k; i<n; ++i){
		

		if (s[i] == s[i-k]) {

		}
		else if (s[i] == '?'){
			s[i] = s[i-k];
		}
		else if (s[i-k] == '?'){
			if (s[i] == '1'){
				if (qo == 0){
					pos = 0; break;
				}
			}
			if (s[i] == '0'){
				if (qz == 0){
					pos = 0; break;
				}
			}
		}
		else {
			pos = 0; break;
		}

		if (s[i-k]=='0') z--;
		else if (s[i-k]=='1') o--;
		else q--;

		if (s[i]=='0') z++;
		else if (s[i]=='1') o++;
		else q++;

		if (l < z|| l <o) {
			pos = 0;
			break;
		}
		else {
			qz = (l-z); qo = (l-o);
		}
		

	}

	if (pos){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
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