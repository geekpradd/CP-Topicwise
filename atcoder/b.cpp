#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin >> n;
	int count = 0;
	for (int i=1; i<=n; ++i){
		int v; cin >> v;
		if (i%2){
			if (v%2)
				count++;
		}
	}
	cout << count << endl;

	return 0;
}