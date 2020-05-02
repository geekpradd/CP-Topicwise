#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 163577857
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
	int a = 0, b = 0, c = 0;
	for (int i=0; i<n; ++i){
		int v; cin >> v;
		if (v==-1) a++;
		if (v==0) b++;
		if (v==1) c++;
	}
	int binom = 1;
	vector<int> revs;
	int up = a + c;
	for (int i=n; i>=-n; --i){
		int val = 0;
		if (c-i<0){
			revs.push_back(0);
			continue;
		}
		else if (c-i > up){
			revs.push_back(0);
			continue;
		}
		int j = c - i;
		int vv = (up-j+1)%MOD;
		if (vv<0) vv += MOD;
		if (j!=0)
			binom = ((binom*vv)%MOD*inverse(j))%MOD;
		val = (binom*power(2, b))%MOD;
		if (i==0)
			val--;
		revs.push_back(val);
	}
	for (int i=revs.size()-1; i>=0; --i){
		cout << revs[i] << " ";
	}
	cout << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}