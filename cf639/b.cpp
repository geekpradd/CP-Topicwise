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
	int grid[n][m];
	vector<ii> points;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			char in; cin >> in;
			if (in=='#'){
				grid[i][j] = 1;
				points.pb(make_pair(i, j));
			}
			else
				grid[i][j] = 0;
		}
	}
	bool col = 0;
	bool pos = 1;
	for (int i=0; i<n; ++i){
		int status = 0;
		for (int j=0; j<m; ++j){
			if (grid[i][j]){
				if (status == 0)
					status = 1;
				else if (status == 2)
					status = 3;
			}
			else {
				if (status == 1)
					status = 2;
			}
		}
		if (status==3)
			pos = 0;
		if (status == 0){
			col = 1;
		}
	}
	bool row = 0;
	for (int i=0; i<m; ++i){
		int status = 0;
		for (int j=0; j<n; ++j){
			if (grid[j][i]){
				if (status == 0)
					status = 1;
				else if (status == 2)
					status = 3;
			}
			else {
				if (status == 1)
					status = 2;
			}
		}
		if (status==3)
			pos = 0;
		if (status == 0){
			row = 1;
		}
	}
	if (pos==0){
		cout << -1 << endl;
		return;
	}
	bool res = row ^ col;
	if (res){
		cout << -1 << endl;
		return;
	}
	int comp = 0;
	for (ii point: points){
		if (grid[point.first][point.second]==2) continue;
		queue<ii> dfs;
		comp++;
		dfs.push(point);
		while (!dfs.empty()){
			ii cur = dfs.front();
			dfs.pop();
			if (grid[cur.first][cur.second]==2) continue;
			
			grid[cur.first][cur.second] = 2;
			if (cur.first !=0){
				if (grid[cur.first-1][cur.second]==1){
					dfs.push(make_pair(cur.first-1, cur.second));
				}
			}
			if (cur.first !=n-1){
				if (grid[cur.first+1][cur.second]==1){
					dfs.push(make_pair(cur.first+1, cur.second));
				}
			}
			if (cur.second !=0){
				if (grid[cur.first][cur.second-1]==1){
					dfs.push(make_pair(cur.first, cur.second-1));
				}
			}
			if (cur.second !=m-1){
				if (grid[cur.first][cur.second+1]==1){
					dfs.push(make_pair(cur.first, cur.second+1));
				}
			}
		}
	}

	cout << comp << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}