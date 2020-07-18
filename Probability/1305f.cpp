#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
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

int ans(int a[], int n, int div){
	int val = 0;
	for (int i=0; i<n; ++i){
		int rem = (a[i]%div);
		if (a[i] == rem){
			val += (div-rem);
		}
		else {
			val += min(rem, div-rem);
		}
	}
	return val;
}

void solve(){
	int n; cin >> n;
	int a[n];
	REP0(i, n){
		cin >> a[i];
	}
	
	
	int operations = 20;
	int ops = E9;
	if (n > 35){
		srand((unsigned) time(0));
		int index = (rand()%n);
		int distinct = 0;
		vector<bool> got(n, false);
		while (distinct < operations){
			int e = a[index];
			for (int i=2; i*i <= e; ++i){
				if (e%i) continue;
				ops = min(ops, ans(a, n,i));

				ops = min(ops, ans(a, n, e/i));

			}
			for (int i=2; i*i <= (e+1); ++i){
				if ((e+1)%i) continue;
				ops = min(ops, ans(a, n,i));

				ops = min(ops, ans(a, n, (e+1)/i));


			}
			for (int i=2; i*i <= (e-1); ++i){
				if ((e-1)%i) continue;
				ops = min(ops, ans(a, n,i));

				ops = min(ops, ans(a, n, (e-1)/i));

			}

			got[index] = 1;
			distinct++;

			index = (rand()%n);
			while (got[index]){
				index = (rand()%n);
			}
		}
	}
	else {
		REP0(index, n){

			int e = a[index];
			for (int i=1; i*i <= e; ++i){
				if (e%i) continue;
				if (i!=1)
					ops = min(ops, ans(a, n,i));
				if ((e/i) != 1)
					ops = min(ops, ans(a, n, e/i));

			}
			for (int i=1; i*i <= (e+1); ++i){
				if ((e+1)%i) continue;
				if (i!=1)
					ops = min(ops, ans(a, n,i));

				if (((e+1)/i) != 1)
					ops = min(ops, ans(a, n, (e+1)/i));

			}
			for (int i=1; i*i <= (e-1); ++i){
				if ((e-1)%i) continue;
				if (i!=1)
					ops = min(ops, ans(a, n,i));
				if (((e-1)/i) != 1)
					ops = min(ops, ans(a, n, (e-1)/i));
			}

		}

	}
	
	int other = 0;
	REP0(i, n){
		if (a[i]%2) other++;
	}
	ops = min(ops, other);
	d1(ops);
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}