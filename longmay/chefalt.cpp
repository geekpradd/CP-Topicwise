#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int x, int y, int l, int r){
	int indexer = 1LL << 62;
	vector<int> candidates;
	candidates.push_back(l);
	bool found = 0;
	int current = 0;
	int both = (x | y);
	while (indexer > 0){
		bool pres_r = (r & indexer);
		bool pres_l = (l & indexer);

		if (!found && (pres_r) == (pres_l)){
			current += indexer*pres_r;
			indexer = indexer >> 1;
			continue;
		}
		if (!found) {
			found = 1;
		}
		if (pres_r){
			int val = current + (both & (indexer-1));
			if (val < l){
				int copy = val;
				int sep = indexer >> 1;
				while (sep > 0){
					// cout << "Sep " << sep << endl;
					bool in_l = (l&sep);
					bool in_copy = (copy&sep);
					if (in_l && !in_copy)
						copy += sep;
					if (copy >= l)
						break;

					sep = sep >> 1;
				}
				val = copy;
			}
			// cout << "pushed " << val << endl;
			candidates.push_back(val); 

			if ((x&indexer) || (y&indexer)){
				current = current + indexer;
			}
			else {
				break;
			}
		}

		indexer = indexer >> 1;
	}
	candidates.push_back(current);

	int max_val = -1, z;
	for (int j = 0; j<candidates.size(); ++j){
		int i = candidates[j];
		// cout << "candidate " << i << endl;
		if (i < l) continue;
		int l = i&x; int r = i&y;
		int val = l*r;
		if (val > max_val){
			max_val = val;
			z = i;
		}
		else if (val == max_val){
			if (i < z)
				z = i;
		}
	}

	return z;
}

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t;
	cin >> t;
	while (t--){
		int x, y, l, r; cin >> x >> y >> l >> r;
		cout << solve(x, y, l, r) << endl;
	}
}