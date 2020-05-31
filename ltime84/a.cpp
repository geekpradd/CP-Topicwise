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
	int n; cin >> n;
	string a; string b;
	cin >> a;
	cin >> b;
	bool posi = true;
	vector<int> pos[26];
	vector<int> repr(26, -1);
	for (int i=0; i<n; ++i){
		int val = a[i] -'a';
		// cout << "i " << i << " val " << val << endl;
		repr[val] = i;
		if (b[i] != a[i]){
			int other= b[i] - 'a';
			if (other > val){
				posi = false;
				break;
			}
			pos[other].pb(i);
		}
	}
	if (!posi){
		cout << -1 << endl;
		return;
	}
	int count = 0;
	for (int i=25; i>=0; --i){
		if (pos[i].size() == 0) continue;
		if (repr[i] == -1){
			posi = false;
			break;
		}
		count++;
	}
	if (!posi){
		cout << -1 << endl;
		return;
	}
	cout << count << endl;
	for (int i=25; i>=0; --i){
		if (pos[i].size() == 0) continue;
		cout << (1 + pos[i].size()) << " ";
		cout << repr[i] << " ";
		for (int x: pos[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// #endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}	