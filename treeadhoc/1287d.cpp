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
int n; 
bool pos = 1;

vector<int> get_ans(int cur, int c[], vector<int> adj[]){
	vector<int> res;
	if (adj[cur].size()==0){
		if (c[cur]!=0)
			pos = 0;
		res.push_back(cur);
		return res;
	}
	int cummulative = 0;
	bool added = 0;
	for (int child: adj[cur]){
		vector<int> ans = get_ans(child, c, adj);
		if (cummulative + ans.size() > c[cur] && !added){
			for (int i: ans){
				if (cummulative == c[cur]){
					res.push_back(cur);
					res.push_back(i);
					cummulative += 2;
				}
				else{
					res.push_back(i);
					cummulative++;
				}
			}
			added = 1;
		}
		else{
			for (int i:ans){
				res.push_back(i); cummulative++;
			}
		}
	}
	if (c[cur] == cummulative){
		res.push_back(cur); added = 1; cummulative++;
	}
	if (!added){
		pos = 0;
	}
	return res;
}
void solve(){
	 cin >> n;
	int c[n+1], p[n+1], v[n+1];
	vector<int> adj[n+1];
	int root;
	for (int i=1; i<=n; ++i){
		cin >> p[i] >> c[i];
		adj[p[i]].pb(i);
		if (p[i] == 0)
			root = i;
	}
	vector<int> res = get_ans(root, c, adj);
	for (int i=n; i>=1; --i){
		int index = res[i-1];
		v[index] = i;
	}
	if (!pos){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i=1; i<=n; ++i)
		cout << v[i] << " ";

	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
}