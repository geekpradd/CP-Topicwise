#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m, k; cin >> n >> m >> k;
		int sheets[k][n];
		for (int i=0; i<n; ++i){
			for (int j=0; j<k; ++j)
				cin >> sheets[j][i];
		}
		int ans[n];
		vector<bool> done(k, 0);
		vector<int> counter(m+1, 0);
		int so_far = 0;
		int score = 0;
		for (int i=0; i<n; ++i){
			for (int j=0; j<k; ++j){
				if (!done[j])
					counter[sheets[j][i]]++;
			}
			int max_val = -1, max_ind = -1;
			for (int l=1; l<=m; ++l){
				if (counter[l] > max_val){
					max_val = counter[l]; max_ind = l;
				}
				counter[l] = 0;
			}
			// cout << "I " << i << " MAX_VAL " << max_val << " IND " << max_ind << endl;
			for (int j=0; j<k; ++j){
				if (sheets[j][i] == max_ind)
					done[j] = 1;
			}
			ans[i] = max_ind; so_far += max_val;

			if (so_far == k){
				score++;
				so_far = 0;
				for (int j=0; j<k; ++j)
					done[j] = 0;
			}
		}

		for (int i=0; i<n; ++i)
			cout << ans[i] << " ";
		cout << endl;
		cout << score << endl;
	}

	return 0;
}