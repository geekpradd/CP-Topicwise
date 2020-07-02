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
	int base = k/n;
	vector<int> vals(n);
	vector<ii> vv(n);
	for (int i=0; i<n; ++i){
		vals[i] = base;
		vv[i] = mp(base, -1);
	}
	int ans = 0;
	if (k%n == 0){

	}	
	else {
		ans = 2;
		int rem = k - base*n;
		for (int i=0; i<rem; ++i){
			vals[i]++; vv[i].first++;
		}
	}
	int grid[n][n];
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			grid[i][j] = 0;
		}
	}
	int j = 0;
	int prev = -1;
	int cur = 0;
	for (int i=0; i<k; ++i){
		int x;
		if (cur==vals[j]){
			j++;
			x = j;
			cur = 1;
		}
		else {
			x = j;
			cur++;
		}
		int y;
		int max_val = -1, max_ind = -1;
		if (prev == x){
			for (int k=0; k<n; ++k){
				if (vv[k].second != x){
					if (vv[k].first > max_val){
						max_val = vv[k].first;
						max_ind = k;
					}
				}
			}
			vv[max_ind].second = x;
			vv[max_ind].first--;
			y = max_ind;
		}
		else {
			for (int k=0; k<n; ++k){
				if (vv[k].first > max_val){
					max_val = vv[k].first;
					max_ind = k;
				}
			}
			vv[max_ind].second = x;
			vv[max_ind].first--;
			y = max_ind;
		}

		grid[x][y] = 1;

		prev = x;
	}

	cout << ans << endl;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			cout << grid[i][j];
		}
		cout << endl;
	}

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}