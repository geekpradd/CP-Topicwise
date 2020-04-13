#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int n, m, q; 
vector< vector<int> > mul(vector< vector<int> > &a, vector< vector<int> > &b, int k){
	vector< vector<int> > fin(k, vector<int>(k, 0));
	for (int i=0; i<k; ++i){
		for (int j=i; j<k; ++j){
			for(int l=i;l<=j; ++l)
				fin[i][j] = (fin[i][j] + (a[i][l]*b[l][j])%MOD)%MOD;
		}
	}
	return fin;
}
vector< vector<int> > fast_expo(vector< vector<int> > matrix, int exp, int k){
	vector< vector<int> > base(k, vector<int>(k, 0));
	for (int i=0; i<k; ++i) base[i][i] = 1;

	while (exp > 0){
		if (exp%2){
			base = mul(base, matrix, k);
		}
		matrix = mul(matrix, matrix, k);
		exp /= 2;
	}

	return base;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	int l[n+1];
	for (int i=1; i<=n; ++i) cin >> l[i];
	vector< vector<int> > adj(n, vector<int>(n, 0));
	for (int i=0; i<m; ++i){
		int u, v; cin >> u >> v;
		adj[u-1][v-1] = 1;
	}
	for (int i=0; i<n; ++i)
		adj[i][i] = l[i+1];
	for (int e=1; e<=5; ++e){
		vector< vector<int> > final = fast_expo(adj, e, n);
		cout << "M^" << e << endl;
		for (vector<int> v: final){
			for (int i:v)
				cout << i << " ";
			cout << endl;
		}
	}
	for (int i=0; i<q; ++i){
		int d; cin >> d;
		vector< vector<int> > final = fast_expo(adj, d, n);
		int ans = final[0][n-1];
		cout << ans << endl;
	}
	return 0;
}