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
	int n, m; cin >> n >> m;
	int x, k, y; cin >> x >> k >> y;
	int a[n+1], inv[n+1];
	a[0] = 0;
	inv[0] = 0;
	for (int i=1; i<=n; ++i){
		cin >> a[i]; inv[a[i]] = i;
	}
	int f[m+1];
	f[0] = 0;
	for (int i=1; i<=m; ++i){
		cin >> f[i];
	}
	bool pos = 1;
	int cost = 0;
	for (int i=0; i<m; ++i){
		if (inv[f[i]] > inv[f[i+1]]){
			pos = 0; break;
		}
		if (inv[f[i]] == inv[f[i+1]] - 1) continue;
		int m_val = a[inv[f[i]] + 1];
		for (int j = inv[f[i]] + 2; j < inv[f[i+1]]; ++j){
			m_val = max(m_val, a[j]);
		}
		int length = (inv[f[i+1]] - inv[f[i]] - 1);
		if (k*y <= x){
			if (m_val < f[i] || m_val < f[i+1]){
				cost += y*length;
			}
			else {
				if (length < k){
					pos = 0; break;
				}
				else {
					cost += x + y*(length - k);
				}
			}
		}
		else {
			if (length >= k){
				cost += (length%k)*y + (length/k)*x;
			}
			else {
				if (m_val < f[i] || m_val < f[i+1]){
					cost += y*length;
				}
				else {
					pos = 0; break;
				}
			}
		}
	}

	if (inv[f[m]] != n && pos){
		int length = n - inv[f[m]];
		int m_val = a[inv[f[m]] + 1];
		for (int j = inv[f[m]] + 2; j <= n; ++j){
			m_val = max(m_val, a[j]);
		}
		if (k*y <= x){
			if (m_val < f[m]){
				cost += y*length;
			}
			else {
				if (length < k){
					pos = 0; 
				}
				else {
					cost += x + y*(length - k);
				}
			}
		}
		else {
			if (length >= k){
				cost += (length%k)*y + (length/k)*x;
			}
			else {
				if (m_val < f[m]){
					cost += y*length;
				}
				else {
					pos = 0; 
				}
			}
		}
	}
	


	if (pos){
		d1(cost);
	}
	else {
		d1(-1);
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