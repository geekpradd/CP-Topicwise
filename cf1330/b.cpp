#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		vector<int> left_i;
		int lowest_not_yet = 1;
		int max_from_left = -1;
		vector<int> left_count(n+5, 0);
		vector<int> right_count(n+5, 0);
		for (int i=0; i<n; ++i)
			cin >> a[i];
		for (int i=0; i<n; ++i){
			max_from_left = max(max_from_left, a[i]);
			if (left_count[a[i]] != 0)
				break;
			left_count[a[i]]++;
			if (a[i] == lowest_not_yet){
				
				int j = i;
				while (left_count[lowest_not_yet]!=0)
					lowest_not_yet++;
				if (lowest_not_yet == max_from_left + 1){
					left_i.push_back(i);
				}
			}
		}
		int ans = 0;
		int max_from_right = -1;
		int right_not_yet  = 1;
		vector<int> right_i;
		for (int i=n-1; i>=0; --i){
			max_from_right = max(a[i], max_from_right);
			if (right_count[a[i]]!=0) break;
			right_count[a[i]]++;
			if (a[i] == right_not_yet){
				while (right_count[right_not_yet]!=0){
					right_not_yet++;
				}
				
				if (right_not_yet == max_from_right + 1){
					right_i.push_back(i);
				}
			}
		}
		vector<int> indexes;
		for (int i=0; i<right_i.size(); ++i){
			if (binary_search(left_i.begin(), left_i.end(), right_i[i]-1)){
				ans++;
				indexes.push_back(right_i[i]);
			}
		}
		cout << ans << endl;
		for (auto x: indexes){
			cout << x << " " << n - x << endl;
		}
	}
	return 0;
}


