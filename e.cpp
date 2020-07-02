#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, a, r, mz; cin >> n >> a >> r >> mz;
	if (mz > r + a) {
		mz = r + a;
	}
	double m = mz/2.0;
	int h[n+1];
	double tot = 0;
	for (int i=1; i<=n;++i){
		cin >> h[i];
		tot += h[i];
	} 
	tot = tot/n;
	sort(h+1, h+n+1);
	int pref[n+1]; pref[0] = 0;
	int first;
	for (int i=1; i<=n; ++i){
		pref[i] = pref[i-1] + h[i];
		if (h[i]<=tot){
			first = i;
		}
	}

	int best = 10000000000000000;
	for (int i=1; i<=n; ++i){
		int first = m*(2*i-n)*h[i] - m*pref[i] + m*(pref[n]-pref[i]);
		if(h[i] <= tot){
			int second = (m-r)*(n*h[i]-pref[n]);
			best = min(best, second+first);
		}
		else {
			int second = (a-m)*(n*h[i]-pref[n]);
			best = min(best, second+first);
		}
	}
	int low = tot;
	int high = tot + 1;
	int first_a = m*(2*first-n)*low - m*pref[first] + m*(pref[n]-pref[first]);
	int second_a = (m-r)*(n*low - pref[n]);
	int first_b = m*(2*first-n)*high - m*pref[first] + m*(pref[n]-pref[first]);
	int second_b = (a-m)*(n*high - pref[n]);
	best = min(best, second_b + first_b);
	best = min(best, second_a + first_a);
	// if (mean_val == tot){
	// 	int lam = (2*first-n)*tot*m - m*pref[first] + m*(pref[n] - pref[first]);
	// 	best = min(best, lam);
	// }
	cout << best << endl;
}