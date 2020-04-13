#include <bits/stdc++.h>
#pragma gcc optimise('O3')
#define MOD 1000000007
#include <cstdio>
#define int long long
using namespace std;
int inv;
int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res);
	if (exp%2)
		return (res*base);
	return res;
}
int power_m(int base, int exp){
	if (exp==0)
		return 1;
	int res = power_m(base, exp/2);
	res = (res*res)%MOD;
	if (exp%2)
		return (res*base)%MOD;
	return res;
}
bool is_perfect_square(int n){
	int sq = round(sqrt(n));
	return (sq*sq == n);
}
bool is_perfect_cube(int n){
	int cb = round(cbrt(n));
	return (cb*cb*cb == n);
}
int inverse(int n){
	return power_m(n, MOD-2);
}
int square(int n){
	return ((((n*(n+1))%MOD)*(2*n+1))%MOD*inverse(6))%MOD;
}
signed main(){
	int t; scanf("%llu", &t);
	// ofstream fout("log2.txt");
	inv = inverse(6);
	while (t--){
		int n; scanf("%llu", &n);
		int ans = n;
		int bound = log2(n)+10;
		vector<int> sieve(bound+1, 1);
	
		for (int i=2; i<=bound; ++i){
			if (!sieve[i]) continue;
			for (int j=2*i; j<=bound; j+=i)
				sieve[j] = 0;
		}
		// handle y = 2 here
		int term = cbrt(n);
		// cout << "Term is " << term << endl;
		for (int x=2; x<=term; ++x){
			int po = power(x, 2); int count = n/po;
			po = (po)%MOD; count = (count)%MOD;
			ans = (ans + (po*count)%MOD)%MOD;
		}
		int current_val = n/power(term, 2);
		for (int val=current_val; val>=1; --val){
			int cast = sqrt(n/(val+1));
			int low_x = max(cast, term);
			int upper_x = sqrt(n/val);
			int diff = (square(upper_x) - square(low_x));
			// cout << "upper is " << upper_x << " lower is " << low_x << endl;
			// int diff = 5; 
			if (diff < 0) diff += MOD;

			ans = (ans + (diff*val)%MOD)%MOD;
		}

		map<int, int> found;
		for (int y=3; y<=bound; ++y){
			if (!sieve[y]) continue;
			for (int x=2; y*log(x)<=log(n); ++x){
				int po = power(x, y); int count = n/po;
				if (y > 2){
					if (is_perfect_square(po)) continue;
				}
				if (y > 3){
					if (is_perfect_cube(po)) continue;
					if (found.count(po)) continue;
					found[po] = 1;
				}
				// po = (po)%MOD; count = (count)%MOD;
				// if (y > 2){
				// 	fout << x << " " << y << endl;
				// 	cur = (cur + (po*count)%MOD)%MOD;
				// }
				ans = (ans + (po*count)%MOD)%MOD;
			}
		}
		printf("%llu\n", ans);
		// cout << ans << endl;
		// cout << cur << endl;
	}
	return 0;
}
				

