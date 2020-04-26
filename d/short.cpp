#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int inv = 166666668;
int square(int n){
	return (((n*(n+1))%MOD*(2*n+1))%MOD*inv)%MOD;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int term = round(cbrt(n));
		// cout << "Term is " << term << endl;
		int ans = 0;
		for (int x=1; x<=min(term, m); ++x){
			int po = (x*x); int count = n/po;
			po = (po)%MOD; count = (count)%MOD;
			// cout << "x " << x << " po " << po << " count " << count << endl;
			ans = (ans + (po*count)%MOD)%MOD;
		}
		// cout << " ans " << ans << endl;
		if (m > term){
			int denom = term*term;
			int current_val = n/denom;
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
				// cout << "current " << val << endl;
				// if (val==current_val || val>=current_val-10)
					// cout << "AT " << val << " with upper " << upper_x << " and lower " << low_x << endl;
				if (upper_x > m){
					// cout << "this happened " << endl;
					upper_x = m;
					int diff = (square(upper_x) - square(low_x))%MOD;
					// cout << "up " << upper_x << " low " << low_x << endl;
					if (diff < 0) diff += MOD;

					// cout << "diff " << diff << endl;
					ans = (ans + (diff*val)%MOD)%MOD;
					break;
				}
				else {
					int diff = (square(upper_x) - square(low_x))%MOD;
					if (diff < 0) diff += MOD;
					// cout << "up " << upper_x << " low " << low_x << endl;

					// cout << "diff " << diff << endl;
					ans = (ans + (diff*val)%MOD)%MOD;	
				}
				
			}
		}
		// cout << "ams is " << ans << endl;
		int tot = (((n)%MOD*(m)%MOD)%MOD - ans)%MOD;
		if (tot < 0)
			tot += MOD;
		cout << tot << endl;
	}
}