
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
int get(vector<int> &seg, int j, int l, int r, int i){
	if (l == r && l == j){
		return seg[i];
	}
	int mid = (l+r)/2;
	seg[2*i+1] += seg[i];
	seg[2*i+2] += seg[i];
	seg[i] = 0;
	if (j <= mid){
		return get(seg, j, l, mid, 2*i+1);
	}
	else {
		return get(seg, j, mid+1, r, 2*i+2);
	}
}

void update(vector<int> &seg, int x, int l, int r, int i, int ql, int qr){
	if (r < ql || l > qr){
		return;
	}
	if (l >= ql && r <= qr){
		// cout << "updated " << l << " and " << r << " with x " << x << endl;
		seg[i] += x;
		return; 
	}
	int mid = (l + r)/2;
	seg[2*i+1] += seg[i];
	seg[2*i+2] += seg[i];
	seg[i] = 0;
	update(seg, x, l, mid, 2*i+1, ql, qr);
	update(seg, x, mid+1, r, 2*i+2, ql, qr);

}

void solve(){
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	int incr = 0;
	for (int i=1; i<n; ++i){
		if (a[i] > a[i-1]){
			incr += (a[i] - a[i-1]);
		}
	}
	int q; cin >> q;
	int base = a[0];
	int ca = (base + incr)/2;
	cout << max(ca, base+incr - ca) << endl;
	vector<int> seg(4*n+1, 0);
	while (q--){
		int l, r, x; cin >> l >> r >> x;
		if (l == 1) base += x;
		int pl, cl, pr, cr;
		if (l != 1){
			pl = get(seg, l-2, 0, n-1, 0) + a[l-2];
			cl = get(seg, l-1, 0, n-1, 0) + a[l-1];
			// DUMP(pl);
			// DUMP(cl);
		}
		if (r != n){
			pr = get(seg, r, 0, n-1, 0) + a[r];
			cr = get(seg, r-1, 0, n-1, 0) + a[r-1];
			// DUMP(pr);
			// DUMP(cr);
		}
		update(seg, x, 0, n-1, 0, l-1, r-1);
		if (l != 1){
			int nl = get(seg, l-1, 0, n-1, 0) + a[l-1];
			if (cl > pl){
				incr -= (cl - pl);
			}
			if (nl > pl){
				incr += (nl - pl);
			}
			// DUMP(nl);
		}
		if (r != n){
			int nr = get(seg, r-1, 0, n-1, 0) + a[r-1];
			if (pr > cr){
				incr -= (pr - cr);
			}
			if (pr > nr){
				incr += (pr - nr);
			}
			// DUMP(nr);
		}
		int ca = (base + incr)/2;
	cout << max(ca, base+incr - ca) << endl;

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