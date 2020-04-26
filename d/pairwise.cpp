#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin >> n;
	vector<int> vals(n); vals[0] = 1;
	vector<int> storage(80000001, 0);
	int cur = 2;
	int i;
	for  (i=1; i<n; ++i){
		if (cur > 4*10000000)
			break;
		bool pos = 1;
		for (int j=0; j<i; ++j){
			if (storage[cur + vals[j]]){
				pos = 0; break;
			}
		}
		if (!pos){
			i--;
			cur++;
		}
		else {
			vals[i] = cur;
			for (int j=0; j<i; ++j){
				storage[cur + vals[j]] = 1;
			}
			cur++;
		}
	}
	if (i < n){
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<n; ++i)
		cout << vals[i] << " ";

	cout << endl;
	return 0;
}