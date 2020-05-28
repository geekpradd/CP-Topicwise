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
	int n, m, x, y; cin >> n >> m >> x >> y;
	if (2*x < y){
		y = 2*x;
	}
	bool grid[n][m];
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			char inp; cin >> inp;
			if (inp=='.')
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	int cost = 0;
	for (int i = 0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (grid[i][j]){
				if (j==m-1){
					cost += x;
				}
				else {
					if (grid[i][j+1]){
						cost += y; 
						j++;
					}
					else {
						cost += x;
					}
				}
			}
		}
	}
	cout << cost << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}