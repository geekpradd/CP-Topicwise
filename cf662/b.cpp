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
	int n;
	cin >> n;
	int a[n];
	vector<int> freq(100001, 0);
	int n4 = 0, n2 = 0, n8 = 0, n6 = 0;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		freq[a[i]]++;
	}
	for (int i=1; i<=100000; ++i){
		if (freq[i]>=8){
			n8++;
		}
		else if (freq[i] >= 6){
			n6++;
		}
		else if (freq[i] >= 4){
			n4++;
		}
		else if (freq[i] >= 2){
			n2++;
		}
	}
	int q; cin >> q;
	while (q--){
		char op; cin >> op; int num; cin >> num; 
		if (op == '+'){
			int i = num;
			if (freq[i]>=8){
				n8--;
			}
			else if (freq[i] >= 6){
				n6--;
			}
			else if (freq[i] >= 4){
				n4--;
			}
			else if (freq[i] >= 2){
				n2--;
			}
			freq[i]++;
			if (freq[i]>=8){
				n8++;
			}
			else if (freq[i] >= 6){
				n6++;
			}
			else if (freq[i] >= 4){
				n4++;
			}
			else if (freq[i] >= 2){
				n2++;
			}
		}
		else {
			int i = num;
			if (freq[i]>=8){
				n8--;
			}
			else if (freq[i] >= 6){
				n6--;
			}
			else if (freq[i] >= 4){
				n4--;
			}
			else if (freq[i] >= 2){
				n2--;
			}
			freq[i]--;
			if (freq[i]>=8){
				n8++;
			}
			else if (freq[i] >= 6){
				n6++;
			}
			else if (freq[i] >= 4){
				n4++;
			}
			else if (freq[i] >= 2){
				n2++;
			}
		}
		if (n8 > 0){
			d1("YES");
		}
		else if (n6 > 1){
			d1("YES");
		}
		else if (n6 == 1) {
			if (n2 > 0 || n4 > 0){
				d1("YES");
			}
			else {
				d1("NO");
			}
		}
		else if (n4 > 1){
			d1("YES");
		}
		else if (n4 == 1){
			if (n2 > 1){
				d1("YES");
			}
			else {
				d1("NO");
			}
		}
		else {
			d1("NO");
		}
	}

}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}