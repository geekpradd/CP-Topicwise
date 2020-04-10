#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, l, r; cin >> n >> l >> r;
		double v = sqrt((1-2*n)*(1-2*n) - 4*l);
		double z = ((2*n-1) - v)/2;
		int comp = z;
		int fin = comp; // finished
		if (2*n*fin - fin*(fin+1) == l || comp == z)
			fin--;
		// cout << "Comp " << comp << endl;
		// cout << "fin " << fin << endl;
		int so_far = 2*n*fin - fin*(fin+1);
		// cout << "so far " << so_far << endl;
		int gap = l - so_far;
		int excess = fin;
		int iteration = fin+1;
		int beyond = n*(n-1);
		// cout << "gap " << gap << endl;
		for (int i=l; i<=min(r, beyond); ++i){
			if (gap%2)
				cout << (1 + excess) << " ";
			else
				cout << (1 + excess + gap/2) << " ";

			if (gap == 2*(n - iteration)){
				gap = 1;
				excess++; iteration++;
			}
			else {
				gap++;
			}
		}
		// cout << "beyond " << beyond << endl;
		if (r > beyond)
			cout << 1 << " ";
		cout << endl;
		
	}
	return 0;
}