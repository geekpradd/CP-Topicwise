#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;

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
	string s, t;
	cin >> s;
	cin >> t;
	int dp[s.length()][t.length()];
	for (int i=0; i<s.length(); ++i){
		for (int j=0; j<t.length(); ++j){
			char l = s[i];
			char x = t[t.length()-1-j];
			if (i!=0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = 0;
			if (l==x){
				if (j!=0){
					dp[i][j] = dp[i][j] + (i !=0 ? dp[i-1][j-1] : 0);
				}
				else 
					dp[i][j] = dp[i][j] + power(2, i);
			}

			cout << "Dp " << i << "  " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[s.length()-1][t.length()-1] << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}