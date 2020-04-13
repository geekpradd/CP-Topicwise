#include <bits/stdc++.h>

#define int long long

using namespace std;



signed main(){

	int t; cin >> t;

	while (t--){

		int n; cin >> n;

		vector<int> positions;

		positions.push_back(0);

		for (int i=1; i<=n; ++i){

			int val; cin >> val;

			if (val % 2 == 0){

				int quo = val/2;

				if (quo % 2)

					positions.push_back(i);

			}

		}

		positions.push_back(n+1);

		int sub = 0;

		for (int i=1; i<positions.size()-1; ++i){
			sub += (positions[i] - positions[i-1])*(positions[i+1] - positions[i]);
		}
		int ans = (n*(n+1))/2;
		ans -= sub;
		cout << ans << endl;

	}

	return 0;

}


