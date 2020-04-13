#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

int get(int n){
	int it = (1<<30);
	int index = 31;
	while (it > 0){
		if (n & it)
			return index;
		index--;
		it = it >> 1;
	}
}

signed main(){
	int t; 
	cin >> t;
	for (int w=1; w<=t; ++w){
		int n; cin >> n;
		cout << "Case #" << w << ": " << endl;

		if (n<500){
			for (int i=0; i<n; ++i){
				cout << (i+1) << " " << 1 << endl;
			}
			continue;
		}
		int p = n;
		int cur = 0;
		bool same = 0;
		while (get(p) != (cur+1)){
			cur++; p--;
			// cout << "CUR now " << cur << " P " << p << endl;
			if (get(p)==cur){
				
			}
			cout << cur << " 1" << endl;
		}
		
		// cout << "ITER CUR " << cur << endl;
		if (!same)
			cout << cur << " " << 1 << endl;
		for (int i=2; i<=cur; ++i){
			cout << cur << " " << i << endl;
		}
		p = p - (1 << (get(p)-1));
		// cout << "P now " << p << endl;
		bool right = true;
		while (p!=0){
			while (get(p) != (cur-1)){
				cur--; p--;
				// cout << "CURSS now " << cur << " P " << p << endl;

				cout << cur << " " << (right ? cur : 1) << endl;
				if (p==0)
					break;
			}
			if (p==0)
				break;
			cur--;
			// cout << "iter cur " << cur << endl;
			if (right){
				for (int i=cur; i>=1; --i){
					cout << cur << " " << i << endl;
				}
			}
			else {
				for (int i=1; i<=cur; ++i){
					cout << cur << " " << i << endl;
				}
			}
			right = 1-right;
			p = p - (1 << (get(p)-1));
			// cout << "P now " << p << endl;

		}

	}
	return 0;
}