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
	int n, m; cin >> n >> m;
	bool c[n][m]; 
	int b_c = 0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			char in; cin >> in;
			c[i][j] = (in-'0'); 
			c[i][j] = 1 - c[i][j];
			b_c += c[i][j]; 
			cout << "c[" << i << "][" << j << "] = " << c[i][j] << endl;
		}
	}
	cout << "cout " << b_c << endl;
	ii adj[n][m];
	vector< vector<int> > in(n, vector<int>(m, 0));
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			char inp; cin >> inp;
			if (inp == 'U'){
				adj[i][j] = (mp(i-1, j)); in[i-1][j]++;
			}
			if (inp == 'R'){
				adj[i][j] = (mp(i, j+1)); in[i][j+1]++;
			}
			if (inp=='D'){
				adj[i][j] = (mp(i+1, j)); in[i+1][j]++;
			}
			if (inp == 'L'){
				adj[i][j] = (mp(i, j-1)); in[i][j-1]++;
			}
		}
	}
	int net = n*m;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (in[i][j]!=0) continue;
			cout << "At " << i << "  " << j << endl;
			ii cur = mp(i, j);
			while (in[cur.first][cur.second] < 2){
				net--; 
				if (c[cur.first][cur.second]){
					cout << "removal at " << cur.first << " " << cur.second << endl;
					b_c--;
				}
				cur = adj[cur.first][cur.second];
			}
		}
	}

	cout << net << " " << b_c << endl;
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
}