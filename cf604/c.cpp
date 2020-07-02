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
	int n; cin >> n;
	vector<int> freqs;
	int first; cin >> first;
	freqs.pb(1);
	int j = 0;
	for (int i=1; i<n; ++i){
		int k; cin >> k;
		if (k == first){
			freqs[j]++;
		}
		else {
			j++;
			freqs.pb(1);
		}
		first = k;
	}
	int m = freqs.size();
	vector<int> pref(m+1);
	pref[0] = 0;
	for (int i=1; i<=freqs.size(); ++i){
		pref[i] = pref[i-1] + freqs[i-1];
	}
	int total = pref[m];
	int g = 0, s = 0, b = 0;
	if (freqs.size() <= 3){

	}
	else {
		int g_l = 1;
		int val = 2*pref[g_l];
		int s_l = -1;
		for (int i=2; i<m; ++i){
			if (pref[i] > val){
				s_l = i;
				break;
			}
		}
		if (s_l !=-1){
			int b_l = -1;
			for (int j=s_l+1; j<n; ++j){
				if (pref[j] > pref[s_l] + pref[g_l] ){
					b_l = j; break;
				}
			}
			if (b_l != -1){
				while (pref[b_l] <= total/2){
					b_l++;
					if (pref[b_l] > total/2){
						b_l--;
						break;
					}
				}

				g = pref[g_l];
				s = pref[s_l] - g;
				b = pref[b_l] - s - g;
			}
		}
	}
	d3(g, s, b);
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