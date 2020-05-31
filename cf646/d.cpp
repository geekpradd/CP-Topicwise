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

int query(vector<int> batches[], int low, int high){
	vector<int> vals;
	for (int i=low; i<=high; ++i){
		for (int x: batches[i])
			vals.pb(x);
	}
	cout << "? " << vals.size() << " ";
	for (int x: vals){
		cout << x << " ";
	}
	cout << endl;
	int ret; cin >> ret;
	return ret;
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> batches[k+1];
	vector<bool> ticked(n+1, 0);
	for (int i=0; i<k; ++i){
		int s; cin >> s;
		for (int j=0; j<s; ++j){
			int val; cin >> val;
			batches[i].pb(val);
			ticked[val] = 1;
		}
	}
	for (int i=1; i<=n; ++i){
		if (!ticked[i])
			batches[k].pb(i);
	}
	cout << "? " << n << " ";
	for (int i=1; i<=n; ++i){
		cout << i << " ";
	}
	cout << endl;
	int mx; cin >> mx;
	int low = 0, high = k;
	while (low < high){
		int mid = (low + high)/2;
		int val = query(batches, low, mid);
		if (val != mx){
			low = mid + 1;
		}
		else{
			high = mid;
		}
	}
	vector<int> sep;
	for (int i=0; i<=k; ++i){
		if (i==high) continue;
		for (int z: batches[i])
			sep.pb(z);
	}
	cout << "? " << sep.size() << " ";
	for (int z: sep){
		cout << z << " ";
	}
	cout << endl;
	int vvv; cin >> vvv;
	cout << "! ";
	for (int i=0; i<k; ++i){
		if (i == high){
			cout << vvv << " ";
		}
		else {
			cout << mx << " ";
		}
	}
	cout << endl;

	string res;
	cin >> res;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}