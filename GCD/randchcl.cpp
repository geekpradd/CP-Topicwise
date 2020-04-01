#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;

int power(int base, int exp){
	if (exp == 0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp%2)
		return (res*base)%MOD;
	return res;
}
int inverse(int num){
	return power(num, MOD-2);
}

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; 
		int w[n];
		for (int i=0; i<n; ++i)
			cin >> w[i];
		int MAXVAL = 500000;
		vector<int> f(MAXVAL+1, 0);
		for (int i=0; i<n; ++i)
			f[w[i]]++;
		
		int d[MAXVAL+1];
		for (int i=1; i<=MAXVAL; ++i){
			d[i] = f[i];
			int j = 2*i;
			while (j<=MAXVAL){
				d[i] = (d[i] +  f[j])%MOD;
				j += i;
			}
			d[i] = (d[i]*d[i])%MOD;
		}
		int sum_gcd = 0;
		int e[MAXVAL+1];
		for (int i=MAXVAL; i>=1; --i){
			e[i] = d[i];
			int j = 2*i;
			while (j<=MAXVAL){
				e[i] = (e[i]-e[j])%MOD;
				if (e[i]<0)
					e[i] += MOD;

				j += i;
			}
			sum_gcd = (sum_gcd + (i*e[i])%MOD)%MOD;
		}
		int ans = ((n+1)*(2*n+1))%MOD;
		int denom = inverse((6*n*n)%MOD);
		ans = (ans*denom)%MOD;
		ans = (ans*sum_gcd)%MOD;
		cout << ans << endl;
	}
	return 0;
}
		
