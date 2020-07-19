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
	int n; cin >> n;
	string s; cin >> s;
	string cc = "abacaba";

	int total = 0;
	for (int i=0; i<s.size()-6; ++i){
		bool got = 1;
		for (int j=i; j<i+7; ++j){
			if (s[j]!=cc[j-i]){
				got = 0;
			}
		}
		if (got){
			total++;
		}
	}
	if (total > 1){
		d1("No");
	}
	else if (total == 1){
		d1("Yes");
		for (int i=0; i<s.size(); ++i){
			if (s[i]!='?')
				cout << s[i];
			else 
				cout << 'd';
		}
		cout << endl;
	}
	else {
		string copied = s;
		bool done = 0;
		for (int i=0; i<s.size()-6; ++i){
			bool hap = 1;
			for (int j=i; j<i+7; ++j){
				if (copied[j]!=cc[j-i]){
					if (copied[j] == '?'){

					}
					else {
						hap = 0;
					}
					
				}
			}
			if (hap){
				for (int j=i; j<i+7; ++j){
					if (copied[j]!=cc[j-i]){
						if (copied[j] == '?'){
							copied[j]=cc[j-i];
						}
					}
				}
				int total = 0;
				for (int k=0; k<s.size()-6; ++k){
					bool got = 1;
					for (int j=k; j<k+7; ++j){
						if (copied[j]!=cc[j-k]){
							got = 0;
						}
					}
					if (got){
						total++;
					}
				}
				if (total == 1){
					done = 1;
					break;
				}
				else{
					copied = s;
				}
			}

		}
		if (done){
			d1("Yes");
			for (int i=0; i<s.size(); ++i){
				if (copied[i]!='?')
					cout << copied[i];
				else 
					cout << 'd';
			}
			cout << endl;
		}
		else {
			d1("No");
		}
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