#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;

		vector<int> positions(1001, 0);
		for (int i=0; i<n; ++i){
			int val; cin >> val;
			positions[val] = 1;
		}
		positions[0] = 1;
		int v = 0;
		while (x > 0){
			if (positions[v]){

				v++;
							}
			else {
				x--;
				v++;
			}
		}
		cout << (positions[v] ? v : v-1) << endl;
	}
	return 0;
}
