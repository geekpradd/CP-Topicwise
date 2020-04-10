#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
using namespace std;
 
signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int gap = -1;
		int prev_a = 0, prev_b = 0;
		bool pos = 1;
		for (int i=0; i<n; ++i){
			int a, b; cin >> a >> b;
			if (a<b)
				pos =0;
			if ((a-prev_a)<(b-prev_b))
				pos = 0;
			if (a<prev_a)
				pos = 0;
			if (b<prev_b)
				pos = 0;
			prev_a = a;
			prev_b = b;
		}
		if (pos)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
