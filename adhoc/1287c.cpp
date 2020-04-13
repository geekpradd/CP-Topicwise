#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
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
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];
	int even = n/2; int odd = n - even;
	int dp[n][even+1][odd+1][2];
	for (int i=n-1; i>=1; --i){
		for (int j=0; j<=even; ++j){
			for (int k=0; k<=odd; ++k){
				if (a[i]==0){
					if (i==n-1){
						dp[i][j][k][0] = min((j>=1 ? 0 : E9), (k >= 1 ? 1: E9));
						dp[i][j][k][1] = min((j>=1 ? 1 : E9), (k >= 1 ? 0: E9));
						continue;
					}
					dp[i][j][k][0] = min((j>=1 ? dp[i+1][j-1][k][0] : E9), (k >= 1 ? 1 + dp[i+1][j][k-1][1] : E9));
					dp[i][j][k][1] = min((j>=1 ? 1 +  dp[i+1][j-1][k][0] : E9), (k >= 1 ? dp[i+1][j][k-1][1] : E9));
				}
				else {
					if (i == n-1){
						if (a[i]%2){
							dp[i][j][k][0] = (k >= 1 ? 1  : E9);
							dp[i][j][k][1] = (k >= 1 ? 0 : E9);
						}
						else {
							dp[i][j][k][0] = (j >= 1 ? 0 : E9);
							dp[i][j][k][1] = (j >= 1 ? 1 : E9);
						}
						continue;
					}
					if (a[i]%2){
						dp[i][j][k][0] = (k >= 1 ? 1 + dp[i+1][j][k-1][1] : E9);
						dp[i][j][k][1] = (k >= 1 ? dp[i+1][j][k-1][1] : E9);
					}
					else {
						dp[i][j][k][0] = (j >= 1 ? dp[i+1][j-1][k][0] : E9);
						dp[i][j][k][1] = (j >= 1 ? 1 + dp[i+1][j-1][k][0] : E9);
					}
				}	
			}
		}
	}
	int ans; 
	if (n==1){
		ans = 0;
	}
	else if (a[0]==0){
		ans = min(dp[1][even-1][odd][0], dp[1][even][odd-1][1]);
	}
	else if (a[0]%2){
		ans = dp[1][even][odd-1][1];
	}
	else {
		ans = dp[1][even-1][odd][0];
	}
	cout << ans << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}