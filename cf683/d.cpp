
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
	int n, m; cin >> n >> m;
	string a, b; cin >> a;
	cin >> b;
	vector< vector<int> >  dp(n+1, vector<int>(m+1, 0));

	// vector<int> pos_a[26];
	// vector<int> pos_b[26];
	// for (int i=0; i<n; ++i){
	// 	pos_a[a[i]-'a'].push_back(i+1);
	// }
	// for (int i=0; i<m; ++i){
	// 	pos_b[b[i]-'a'].push_back(i+1);
	// }
	int ans = 0;
	vector<int> latest(26, -1);
	for (int i=1; i<=n; ++i){
		latest[a[i-1]-'a'] = i;
		vector<int> oth(26, -1);
		for (int j=1; j<=m; ++j){
			oth[b[j-1]-'a'] = j;
			if (a[i-1] != b[j-1]){
				dp[i][j] = max(dp[i-1][j-1]-2, 0LL);
			}
			else {
				dp[i][j] = max(dp[i-1][j-1]+2, 0LL);
			}
			// auto first_l = upper_bound(pos_b[a[i-1]-'a'].begin(), pos_b[a[i-1]-'a'].end(), j);
			// if (first_l != pos_b[a[i-1]-'a'].begin()){
			// 	first_l--;
			// 	int val = *first_l;
			// 	dp[i][j] = max(dp[i][j], dp[i-1][val-1] + 2 - (j-val));
			// }
			int indexs = oth[a[i-1]-'a'];
			// auto sfirst_l = upper_bound(pos_a[b[j-1]-'a'].begin(), pos_a[b[j-1]-'a'].end(), i);
			if (indexs != -1){
				dp[i][j] = max(dp[i][j], dp[i-1][indexs-1] + 2 - (j-indexs));
			}
			int index = latest[b[j-1]-'a'];
			// auto sfirst_l = upper_bound(pos_a[b[j-1]-'a'].begin(), pos_a[b[j-1]-'a'].end(), i);
			if (index != -1){
				dp[i][j] = max(dp[i][j], dp[index-1][j-1] + 2 - (i-index));
			}
			// if (sfirst_l != pos_a[b[j-1]-'a'].begin()){
			// 	sfirst_l--;
			// 	int val = *sfirst_l;
			// 	dp[i][j] = max(dp[i][j], dp[val-1][j-1] + 2 - (i-val));
			// }
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}