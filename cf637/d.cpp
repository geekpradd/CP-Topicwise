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
	int n, k; cin >> n >> k;
	int **dp = new int*[n+1];
	vector<ii> pos[n+1];

	string vals[n+1];
	int nums[10] = {119, 18, 93, 91, 58, 107, 111, 82,  127, 123};
	for (int i=1; i<=n; ++i){
		dp[i] = new int[k+1];
		cin >> vals[i];
		int num = 0, iter = 1;
		for (int j=6;j>=0; --j){
			char x = vals[i][j];
			if (x == '1')
				num += iter;
			iter = iter << 1;
		}
		// cout << num << endl;
		for (int j=0; j<10; ++j){

			if ((nums[j]&num) == num){
				// cout << "Gto for " << j << endl;
				int res = nums[j] - num;
				int iter = 1, tot = 0;
				for (int k=0; k<7; ++k){
					if (res&iter)
						tot++;
					iter = iter << 1;
				}
				pos[i].pb(mp(j, tot));
				// cout << "pos[" << i << "] added " << j << " with cost " << tot << endl;
			}
		}
	}
	for (int i=0; i<=k; ++i){
		dp[n][i] = -1;
	}
	for (ii x: pos[n]){
		if (x.second > k) continue;
		dp[n][x.second] = x.first;
	}
	for (int i=n-1; i>=1; --i){
		for (int j=0; j<=k; ++j){
			dp[i][j] = -1;
			for (ii x: pos[i]){
				if (x.second <= j){
					int res = dp[i+1][j-x.second];
					if (res != -1){
						dp[i][j] = x.first;
					}
				}
			}
		}
	}
	int init = dp[1][k];
	if (init == -1)
		cout << -1 << endl;
	else {
		int used = 0;
		for (int i=1; i<=n; ++i){
			int cur = dp[i][k-used];
			for (ii x: pos[i]){
				if (x.first == cur){
					used += x.second; break;
				}
			}
			cout << cur;
		}
		cout << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}