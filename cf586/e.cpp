#include <bits/stdc++.h>
#define int long long
#define E9 100000000000000
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int a[n];
	vector<bool> cols(21, false);
	for (int i=0; i<n; ++i){
		cin >> a[i];
		cols[a[i]] = 1;
	}
	int ops[21][21];
	for (int i=1; i<=20; ++i){
		for (int j=1; j<=20; ++j){
			ops[i][j] = 0;
			if (i == j) continue;
			int count = 0;
			for (int k=0; k<n; ++k){
				if (a[k] == i) count++;
				if (a[k] == j) ops[i][j] += count;
			}
		}
	}
	vector<int> dp(1 << 20, E9);
	dp[0] = 0;
	for (int i=1; i<=20; ++i){
		dp[1 << (i-1)] = 0;
	}
	for (int i=0; i< (1<<20); ++i){
		for (int j=0; j<20; ++j){
			int itr = 1 << j;
			if ((i&itr)==0){
				int increm = 0;
				for (int k=0; k<20; ++k){
					int itr = 1 << k;
					if (i&itr){
						increm += ops[k+1][j+1];
					}
				}
				dp[i|itr] = min(dp[i|itr], dp[i] + increm);
			}
		}
	}

	cout << dp[(1 << 20) - 1] << endl;

}
