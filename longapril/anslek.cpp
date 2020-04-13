#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define ii pair<int, int>
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
		vector<int> counter(m+1, 0);
		ii sorter[n];
		for (int i=0; i<n; ++i){
			for (int j=0; j<k; ++j){
					counter[sheets[j][i]]++;
			}
			int max_val = -1;
			for (int l=1; l<=m; ++l){
				if (counter[l] > max_val){
					max_val = counter[l]; 
				}
				counter[l] = 0;
			}
			sorter[i] = make_pair(-1*max_val, i);
		}
		int trials = 70;
		pair<int, vector<int> > count[trials];
		sort(sorter, sorter+n);

		for (int j=0; j<trials; ++j){
			vector<bool> done(k, 0);
			vector<int> ans(n); int score = 0;
			int so_far = 0;
			vector<int> counter(m+1, 0);

			for (int i=0; i<n; ++i){
				for (int j=0; j<k; ++j){
					if (!done[j])
						counter[sheets[j][sorter[i].second]]++;
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
					if (sheets[j][sorter[i].second] == max_ind)
						done[j] = 1;
				}
				ans[sorter[i].second] = max_ind; so_far += max_val;

				if (so_far == k){
					score++;
					so_far = 0;
					for (int j=0; j<k; ++j)
						done[j] = 0;
				}
			}
			count[j] = make_pair(score, ans);
			// for (int i=0; i<n; ++i)
			// 	cout << ans[i] << " ";
			// cout << endl;
			// // cout << score << endl;
			std::srand ( unsigned ( std::time(0) ) );
			std::random_shuffle ( sorter, sorter + n);
		}
		int max_val = -1, max_ind = -1;
		for (int i=0; i<trials; ++i){
			if (count[i].first > max_val){
				max_val = count[i].first; max_ind = i;
			}
			// cout << "Scores are " << count[i].first << endl;
		}
		for (int i=0; i<n; ++i)
			cout << count[max_ind].second[i] << " ";
		cout << endl;
		// cout << max_val << endl;
		
	}

	return 0;
}