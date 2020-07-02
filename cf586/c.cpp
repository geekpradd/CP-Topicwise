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

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	string a; cin >> a;
	string b; cin >> b;
	int c_a = 0, c_b = 0;
	for (int i=0; i<n; ++i){
		if (a[i] == 'a') c_a++;
		else 
			c_b++;
		if (b[i] == 'b') c_b++;
		else
			c_a++;
	}
	if (c_a %2 || c_b%2){
		cout << -1 << endl;
		return 0;
	}
	vector<int> first;
	vector<int> second;
	for (int i=0; i<n; ++i){
		if (a[i] != b[i]){
			if (a[i] == 'a')
				first.pb(i);
			else 
				second.pb(i);

		}
	}
	vector<ii> total;
	bool last = 0;
	for (int i=0; i<first.size(); i+=2){
		if (i == first.size() - 1){
			last = 1; break;
		}
		total.pb(mp(first[i], first[i+1]));
	}
	for (int i=0; i<second.size(); i+=2){
		if (i == second.size() - 1){
			last = 1; break;
		}
		total.pb(mp(second[i], second[i+1]));
	}
	if (last){
		total.pb(mp(first[first.size()-1], first[first.size()-1]));
		total.pb(mp(first[first.size()-1], second[second.size()-1]));
	}

	cout << total.size() << endl;
	for (ii z : total){
		cout << z.first + 1 << " " << z.second + 1 << endl;
	}

}