#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<pair<int, int>> positions;
		positions.push_back(make_pair(0, 0));
		for (int i=1; i<=n; ++i){
			int val; cin >> val;
			if (val == 0)
				positions.push_back(make_pair(i, 0));
			else if (val % 2 == 0){
				int quo = val/2;
				if (quo % 2)
					positions.push_back(make_pair(i,1));
				else
					positions.push_back(make_pair(i, 0));
			}
		}
		positions.push_back(make_pair(n+1, 0));
		int sub = 0;
		for (int i=0; i<positions.size(); ++i){
			if (!positions[i].second) continue;
			sub += (positions[i].first - positions[i-1].first)*(positions[i+1].first - positions[i].first);
		}
		int ans = (n*(n+1))/2;
		ans -= sub;
		cout << ans << endl;
	}
	return 0;
}
