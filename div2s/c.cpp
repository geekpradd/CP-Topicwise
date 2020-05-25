#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void dfs(int vert, int state, vector<ii> adj[], int p, int val[][2]){
	if (p==0){
		if (val[vert][state] == 0)
			return;
	}
	val[vert][state] += p;
	int other = 1 - state;
	for (ii to: adj[vert]){
		if (to.second == state) continue;
		// cout << "got travel " << to.first << " from " << vert << endl;
		int v = abs(to.first - vert);
		dfs(to.first, other, adj,  val[vert][state] + v, val);
	}

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int a[n+1];
	vector<ii> adj[n+1];
	int val[n+1][2];
	for (int i=2; i<=n; ++i){
		cin >> a[i];
		val[i][0] = val[i][1] = 0;
		if (a[i]>= i)
			val[i][0] = a[i];
		else {
			if (i-a[i] == 1) continue;
			adj[i-a[i]].push_back(make_pair(i, 0));
		}
		if (a[i]+i>n)
			val[i][1] = a[i];
		else
			adj[a[i]+i].push_back(make_pair(i, 1));
	}
	for (int i=0; i<2; ++i){
		for (int j=2; j<=n; ++j){
			dfs(j, i, adj, 0, val);
		}
	}
	//for (int i=0; i<2; ++i){
	//	for (int j=2; j<=n; ++j){
		//	cout << "val["<<j<<"][" <<i <<"] = " << val[j][i] << endl;
	//	}
	//}
	for (int i=1; i<n; ++i){
		int to = i+1;
		if (val[to][0] == 0)
			cout << -1 << " ";
		else
			cout << i + val[to][0] << " ";
	
	}
	cout << endl;
	return 0;
}

