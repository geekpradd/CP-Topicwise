#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 998244353
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
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	int b[m];
	for (int i=0; i<m; ++i){
		cin >> b[i];
	}
	bool pos = 1;
	int j = m-1; 
	vector<int> positions(m, -1);
	vector<int> left(m, -1);
	int min_so_far = 2*E9;
	bool prev_done = false;
	for (int i=n-1; i>=0; --i){
		min_so_far = min(a[i], min_so_far);
		if (j >= 0){
			if (min_so_far < b[j]){
				// cout << "At i " << i << endl;
				// cout << " j " << j << endl;
				// cout << min_so_far << endl;
				pos = 0; break;
			}
		}
		
		if (j!= m-1 && !prev_done){
			if (a[i] < b[j+1]){
				prev_done = 1;
				left[j+1] = i;
			}
		}
		if (j >= 0){
			if (min_so_far == b[j]){
				positions[j] = i;
				j--;
				prev_done = 0;
			}
		}
		
		// if (j < 0) break;
		
	}
	if (left[0] != -1){
		pos = 0;
	}
	for (int i=0; i<m; ++i){
		if (positions[i] == -1) {
			pos = 0; break;
		}
	}
	if (pos == 0){
		cout << 0 << endl;
	}
	else{
		int ans = 1;
		for (int i=1; i<m; ++i){
			ans = (ans*(positions[i]-left[i]))%MOD;
		}
		cout << ans << endl;
	}

	// for (int i=0; i<m; ++i){
	// 	cout << "pos " << i << " " <<positions[i] << endl;
	// 	cout << "left " << left[i] << endl;
	// }
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}