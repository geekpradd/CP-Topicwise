#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	int out[n+1], in[n+1], a[n+1];
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		out[i] = a[i];
		in[a[i]] = i;
	}
	
	ifstream fin("out.txt");
	int ops; fin >> ops;
	while (ops--){
		int p, q, r; fin >> p >> q >> r;
		int v1 = a[p], v2 = a[q], v3 = a[r];
		a[p] = v3; a[q] = v1; a[r] = v2;
		cout << "OP " << ops << endl;
		for (int i=1; i<=n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
	}
	for (int i=1; i<=n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

signed main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
}