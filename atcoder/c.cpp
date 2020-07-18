#include <bits/stdc++.h>
using namespace std;

signed main(){
	vector<int> vals(10001, 0);
	for (int x=1; x<=100; ++x){
		for (int y=1; y<=100; ++y){
			for (int z=1; z<=100; ++z){
				int ex = x*x + y*y + z*z + x*y + y*z + z*x;
				if (ex > 10000) continue;
				vals[ex]++;
			}
		}
	}
	int n; cin >> n;
	for (int i=1; i<=n; ++i)
		cout << vals[i] << endl;
	return 0;
}