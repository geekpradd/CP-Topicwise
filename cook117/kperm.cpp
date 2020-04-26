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
#define N 500
int dp[N+1][(N/2)*(N-1)+1];
int pref[N+1][(N/2)*(N-1)+1];

// void update(int i, int bit[], int n){
// 	cout << "update " << i << endl;
// 	for (; i<n; i = i | i + 1)
// 		bit[i]++;
// }
// int sum(int i, int bit[], int n){
// 	cout << "sum " << i << endl;

// 	int sum = 0;
// 	for (; i >= 0; i = (i&(i+1)) - 1)
// 		sum += bit[i];
// 	return sum;
// }

void solve(){
	int n, r, k; cin >> n >> r >> k;
	if (r > (n*(n-1))/2){
		cout << -1 << endl;
		return;
	}
	int ans[n];
	int tot = 0; int cur = 0; int i = 0;
	int c_r = r;
	// while (tot < k && i < n){
	// 	cur++; ans[i] = cur;
	// 	// cout << "tot " << tot << " i " << i << " cur " << cur << endl;

	// 	int incr;
	// 	if (i==n-1){
	// 		incr = 1;
	// 	}
	// 	else {
	// 		incr = (c_r - cur + 1 <= ((n-i-1)*(n-i-2))/2 ? dp[n-i-1][c_r-cur+1] : 0);
	// 	}
	// 	tot += incr;
	// 	// cout << "tot incr " << incr << endl; 
	// 	if (tot >= k){
	// 		ans[i] = cur;
	// 		c_r = c_r - cur + 1;
	// 		i++;
	// 		cur = 0;
	// 		tot -= incr;
	// 	}
	// }
	int bit[n+1]; for (int i=0; i<=n; ++i) bit[i] = 0;
	for (int i=0; i<n; ++i){
		int cur = n-1	;
		int j = 0; int k;
		for (k=1; k<=n;++k){
			if (bit[k]==0) j++;
			if (j==cur){
				bit[k] = 1; break;
			}
		}
		cout << cur  << " ";
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	dp[1][0] = 1;
	pref[1][0] = 1;
	for (int i=2; i<=N; ++i){
		dp[i][0] = 1; pref[i][0] = 1;
		for (int j=1; j<=(i*(i-1))/2; ++j){
			dp[i][j] = (j > ((i-1)*(i-2))/2 ? pref[i-1][((i-1)*(i-2))/2] : pref[i-1][j] )- (j >= i ? pref[i-1][j-i] : 0);
			pref[i][j] = dp[i][j] + pref[i][j-1];
		}
	}
	// cout << dp[3][4] << endl;
	// for (int i=1; i<=6; ++i){
	// 	for (int j=1; j<=(i*(i-1))/2; ++j){
	// 		cout << "dp["<< i<<"][" <<j<<"] = " << dp[i][j] << endl;
	// 	}
	// }
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}