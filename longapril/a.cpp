#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

signed main(){
	int n, k; cin >> n >> k;
	int max_moves = 0;
	int r_so_far = 0;
	int a[n];
	vector<ii> pos;
	bool is_there = 0;
	int l, r;
	for (int i=0; i<n; ++i){
		char in; cin >> in;
		if (in=='R')
			a[i] = 1;
		else
			a[i] = 0;
		if (a[i]==1)
			r_so_far++;
		else
			max_moves += r_so_far;

		if (!is_there && a[i]==1){
			is_there = 1; l = i;
		}
		else if (is_there && a[i] == 0){
			r = i-1;
			pos.push_back(make_pair(l, r));
			is_there = 0;
			// cout << "got at " << l << "  " << r << endl;
		}
	}
	if (is_there){
		pos.push_back(make_pair(l, n-1));
	}
	
	int cur_l = pos[0].first, cur_r = pos[0].second;
	// cout << cur_l << " and " << cur_r << endl;
	int j = 0;
	int cur_i = cur_r;
	vector<int> got(n, 0);
	vector< vector<int> > batches;
	vector<int> vals;
	while (true){
		// cout << "Cur i " << cur_i << endl;
		if (got[cur_i]){
			batches.push_back(vals);
			vals.clear();
			got.clear();
		}
		vals.push_back(cur_i);
		got[cur_i] = 1;
		if (cur_i != cur_l){
			cur_i--;
		}
		else {
			cur_r++;
			cur_l++;
			if (j != pos.size()-1){
				if (cur_r == pos[j+1].first-1){
					cur_r = pos[j+1].second;
					// cout << "cur r " << cur_r << endl;
					j++;
				}
			}
			if (cur_r == n-1)
				break;
			cur_i = cur_r;
		}
	}
	if (vals.size()>0)
		batches.push_back(vals);
	if (k < batches.size() || k > max_moves){
		cout << -1 << endl;
		return 0;
	}
	int rem = batches.size();
	int i = 0; int f=0;
	// cout << "k is " << k << " rem " << rem << endl;
	while (k!=rem){
		if (f==batches[i].size()){
			f = 0; i++;
			rem--;
		}
		cout << 1 << " " << batches[i][f]+1 << endl;
		f++;
		k--;
	}
	int cap = batches[i].size() - f;
	if (cap != 0){
		cout << cap << " ";
		for (int p=f; p<batches[i].size(); ++p)
			cout << batches[i][p]+1 << " ";
		cout << endl;
	}
	for (int j=i+1; j<rem; ++j){
		cout << batches[j].size() << " ";
		for (int x: batches[j])
			cout << x+1 << " ";
		cout << endl;
	}
	
	return 0;

}