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
	int n, k; cin >> n >> k;
	vector<int> both, a, b;
	for (int i=0; i<n; ++i){
		int t, ax, bx; cin >> t >> ax >> bx;
		if (ax & bx){
			both.pb(t);
		}
		else if (ax){
			a.pb(t);
		}
		else if(bx) {
			b.pb(t);
		}
	}
	sort(both.begin(), both.end());
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	int l = 0;
	int z = 0;
	int cap_a = k, cap_b = k; int cost = 0;
	bool pos = 1;
	while (cap_a || cap_b){
		if (l == a.size() || l == b.size()){
			if (z == both.size()){
				pos = 0; break;
			}
			cost += both[z]; z++;
			cap_a--; cap_b--;
		}
		else if (z == both.size()){
			if (l == a.size() || l == b.size() ){
				pos = 0; break;
			}
			cost += a[l] + b[l]; l++;
			cap_a--; cap_b--;
		}
		else {
			if (a[l] + b[l] < both[z]){
				cost += a[l] + b[l];
				cap_a--; cap_b--;
				l++;
			}
			else {
				cost += both[z];
				cap_a--; cap_b--;
				z++;
			}
		}
	}
	if (pos){
		cout << cost << endl;
	}
	else {
		cout << -1 << endl;
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