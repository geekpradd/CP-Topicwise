#include <bits/stdc++.h>
#define MOD 998244353 
#define int long long
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

signed main(){
	int fact[61]; fact[0] = 1;
	for (int i=1; i<=60; ++i)
		fact[i] = (i*fact[i-1])%MOD;
	int inv[61]; inv[0] = inv[1] = 1;
	for (int i=2; i<=60; ++i)
		inv[i] = inverse(fact[i]);
	int d; cin >> d;
	int cur = -1;
	vector<int> primes;
	for (int i=2; i*i<=d; ++i){
		if (d%i==0){
			primes.push_back(i);
			while (d%i==0){
				d = d/i;
			}
		}
	}
	if (d!=1)
		primes.push_back(d);
	int q;
	cin >> q;
	while (q--){
		int u, v; cin >> u >> v;
		int incr_sum = 0, decr_sum = 0;
		int prod = 1;
		for (int i=0; i<primes.size(); ++i){
			int c = 0;
			while (u%primes[i]==0){
				c++; u /= primes[i];
			}
			int d = 0;
			while (v%primes[i]==0){
				d++; v/=primes[i];
			}
			if (c < d){
				incr_sum += (d-c);
				prod = (prod*inv[d-c])%MOD;
			}
			else if (c > d){
				decr_sum += (c-d);
				prod = (prod*inv[c-d])%MOD;
			}
		}
		prod = (prod*fact[incr_sum])%MOD;
		prod = (prod*fact[decr_sum])%MOD;
		cout << prod << endl;
	}
	return 0;
}