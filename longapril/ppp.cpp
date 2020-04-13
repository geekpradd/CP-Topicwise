#include <bits/stdc++.h>
#define MOD 1000000007
#include <cstdio>
#define int long long
using namespace std;
int inv = 166666668;
int power(int base, int exp){
	int res = 1;
	for (int i=0; i<exp; ++i)
		res = res*base;
	return res;
}
bool is_perfect_square(int n){
	int sq = round(sqrt(n));
	return ((sq*sq == n) || ((sq+1)*(sq+1)==n) || ((sq-1)*(sq-1)==n));
}
bool is_perfect_cube(int n){
	int cb = round(cbrt(n));
	return ((cb*cb*cb == n) || ((cb+1)*(cb+1)*(cb+1)==n) || ((cb-1)*(cb-1)*(cb-1)==n));
}
int square(int n){
	return (((n*(n+1))%MOD*(2*n+1))%MOD*inv)%MOD;
}
signed main(){
	int t; cin >> t;
	while (t--){
		int n; scanf("%llu", &n);
		int bound = log2(n);
		int ans = (n)%MOD;
		int term = round(cbrt(n));
		for (int x=2; x<=term; ++x){
			int po = power(x, 2); int count = n/po;
			po = (po)%MOD; count = (count)%MOD;
			ans = (ans + (po*count)%MOD)%MOD;
		}

		int current_val = n/power(term, 2);
		long double bet = n;
		for (int val=current_val; val>=1; --val){
			int cast = sqrt(bet/(val+1));
			if (n%(val+1) == 0){
				int z = n/(val+1);
				int sqr = round(sqrt(z));
				if (sqr*sqr == z){
					cast = sqr;
				}
				if ((sqr-1)*(sqr-1)==z)
					cast  = sqr - 1;
				if ((sqr+1)*(sqr+1)==z)
					cast = sqr + 1;
			}
			int low_x = max(cast, term);
			int upper_x = (sqrt(bet/val));
			if (n%(val) == 0){
				int z = n/(val);
				int sqr = round(sqrt(z));
				if (sqr*sqr == z){
					upper_x = sqr;
				}
				if ((sqr-1)*(sqr-1)==z)
					upper_x = sqr - 1;
				if ((sqr+1)*(sqr+1)==z)
					upper_x = sqr + 1;
			}
			int diff = (square(upper_x) - square(low_x))%MOD;
			ans = (ans + (diff*val)%MOD)%MOD;
		}

		map<int, int> found;
		for (int y=3; y<=bound; ++y){
			for (int x=2; y*log(x) <= log(n); ++x){
				if (is_perfect_square(x))
					continue;
				int po = power(x, y); int count = n/po;
				
				if (y > 2){
					if (is_perfect_square(po)) {
						continue;
					}
				}
				if (y > 3){
					if (is_perfect_cube(x)) continue;
					if (is_perfect_cube(po)) continue;
					if (found.count(po)) continue;
					found[po] = 1;
				}
				po = (po)%MOD; count = (count)%MOD;
				ans = (ans + (po*count)%MOD)%MOD;
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
				
