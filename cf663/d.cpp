#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
	int mi = min(n, m);
	int **final = new int*[n];
	REP0(i, n){
		final[i] = new int[m];
		REP0(j, m){
			char in; cin >> in; 
			final[i][j] = (in - '0');
		}
	}
	if (mi >= 4){
		d1(-1);
		return;
	}
	
	if (n == 1){
		cout << 0 << endl; return;
	}
	if (n == 2){
		int states[m];
		states[m-1] = 0;
		for (int i=0; i<m-1; ++i){
			int value = final[0][i] + final[1][i] + final[0][i+1] + final[1][i+1];
			states[i] = (value)%2;
		}
		int dp[m][2];
		dp[m-1][0] = dp[m-1][1] = 0;
		for (int i=m-2; i>=0; --i){
			int correct = states[i+1];
			dp[i][1] = dp[i+1][correct];
			dp[i][0] = 1 + min(dp[i+1][0], dp[i+1][1]);
		}
		cout << dp[0][states[0]] << endl;
	}
	else  {
		int states[2][m];
		states[0][m-1] = states[1][m-1] = 0;
		for (int i=0; i<m-1; ++i){
			int value = final[0][i] + final[1][i] + final[0][i+1] + final[1][i+1];
			states[0][i] = (value)%2;
			value = final[1][i] + final[2][i] + final[1][i+1] + final[2][i+1];
			states[1][i] = (value)%2;
		}
		int dp[4][m];
		dp[0][m-1]  = dp[1][m-1] = dp[2][m-1] = dp[3][m-1] = 0;
		for (int i=m-2; i>=0; --i){
			int state_future = 2*states[1][i+1] + states[0][i+1];
			dp[3][i] = dp[state_future][i+1];
			dp[2][i] = 1 + min(dp[state_future][i+1], dp[(state_future ^ 1)][i+1]);
			dp[1][i] = 1 + min(dp[state_future][i+1], dp[(state_future ^ 2)][i+1]);
			dp[0][i] = 1 + min(dp[state_future][i+1], dp[(state_future ^ 3)][i+1]);
		}
		int initial = 2*states[1][0] + states[0][0];
		cout << dp[initial][0] << endl;
	}

}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}