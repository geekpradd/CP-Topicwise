#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin >> n;
	vector<int> counter(1000001, 0);
	vector<int> length(1000001, 0);
	vector<bool> here(1000001, false);
	vector<int> unique;

	vector< pair<int, int> > a(n);
	for (int i=0; i<n; ++i){
		char type; cin >> type;
		int val; cin >> val;
		a[i] = make_pair((type == 'e' ? -1 : 1), val);
		if (type == 'e')
			counter[val]++;
		else
			counter[val]--;

		length[val]++;
		if (!here[val]){
			unique.push_back(val);
			here[val] = 1;
		}
	}
	int removal = 0;
	int best = 0;
	for (int i=0; i<unique.size(); ++i){
		cout << unique[i] << endl;
		cout << "got " << counter[unique[i]] << endl;
		if (counter[unique[i]] != 0){
			removal += length[unique[i]];
			here[unique[i]] = false;
		}
		else {
			best++;
		}
	}
	int ans = -n;
	vector<int> cutoffs;
	vector<int> current(1000001, 0);
	vector<int> least_zeros(1000001, n-1);
	vector<bool> is_negative(1000001, false);
	vector<int> highest_min(1000001, 0);
	for (int i=0; i<n; ++i){
		if (!here[a[i].second]) continue;
		current[a[i].second] += a[i].second;
		if (current[a[i].second] == 0){
			least_zeros[a[i].second] = min(least_zeros[a[i].second], i);
		}
		if (current[a[i].second] == -1){
			is_negative[a[i].second] = 1;
			highest_min[a[i].second] = i;
			current[a[i].second] = 0;
		}
	}

	int min_zeros = n-1;
	int highest = 0;
	bool any = false;
	for (int i=0; i<unique.size(); ++i){
		if (!here[unique[i]]) continue;
		min_zeros = min(min_zeros, least_zeros[unique[i]]);
		if (is_negative[unique[i]]){
			any = 1;
			highest = max(highest, highest_min[unique[i]]);
		}

	}
	int val;
	if (any){
		val = highest + 1;
	}
	else {
		val = min_zeros + 1;
	}
	cout << val << " " << best << " " << removal << endl;
}