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

pair<int, vector<int> > solve(int a[], int n, int r){
	int mn = E9; int j = -1;
	vector<int> answer;
	cout << "n " << n << " r " << r << endl;
	int pos = 1;
	if (n <= 2){
		if (a[r+0] > a[r+1]){
			pos = 0;
		}
		return mp(pos, answer);
	}
	for (int i=0; i<n; ++i){
		cout << a[r+i] << " ";
	}
	cout << endl;
	for (int i=0; i<n; ++i){
		if (a[r+i] < mn){
			mn = a[r+i]; j = i;
		}
	}
	cout << " j " << j << endl;
	cout << " r " << r << endl;
	if (j != r ){
		if (j % 2 == 0){
			for (int k=j-2; k>=0; k-=2){
				answer.push_back(k+r+1);
				swap(a[k+r], a[k+r+2]);
				swap(a[k+r+1], a[k+r+2]);
			}
		}
		else {
			for (int k=j-2; k>=1; k-=2){
				answer.push_back(k+r+1);
				swap(a[k+r], a[k+r+2]);
				swap(a[k+r+1], a[k+r+2]);
			}
			answer.push_back(r+1);
			answer.push_back(r+1);
			swap(a[0+r], a[0+r+2]);
			swap(a[0+r+1], a[0+r+2]);
			swap(a[0+r], a[0+r+2]);
			swap(a[0+r+1], a[0+r+2]);
		}
	}
	for (int i=0; i<n; ++i){
		cout << a[i+r] << " ";
	}
	cout << endl;
	pair<int, vector<int> > f = solve(a, n-1, r+1);
	if (f.first == 0){
		pos = 0;
	}
	for (int z: f.second){
		answer.push_back(z);
	}
	return mp(pos, answer);
	
}

void solve(){
	int n; 
	cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];	
	pair<int, vector<int> > res = solve(a, n, 0);
	if (res.first == 0){
		cout << -1 << endl;
	}
	else{
		cout << res.second.size() << endl;
		for (int z: res.second){
			cout << z << " ";
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
	while (t--){
		solve();
	}
	
	return 0;
}