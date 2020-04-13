#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int get(int n){
	int it = (1<<29);
	int index = 30;
	while (it > 0){
		if (n & it)
			return index;
		index--;
		it = it >> 1;
	}
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; 
	cin >> t;
	for (int w=1; w<=t; ++w){
		int n; cin >> n;
		// cout << "Case #" << w << ": " << endl;

		int p = n;
		int cur = 0;
		int target = get(p);
		int rem = p - (1 << (target-1));
		cout << "rem is " << rem << endl;
		while (target != (cur+1)){
			cur++; p--; rem--;
			if (rem < 0){
				target--;
				rem = (1<<target)-1;
			}
			if (target <= cur)
			cout << "CUsR now " << cur << " P " << p << endl;
			
			cout << cur << " 1" << endl;
		}
		cur++;
		// cout << "ITER CUR " << cur << endl;
		for (int i=1; i<=cur; ++i){
			cout << cur << " " << i << endl;
		}
		p = p - (1 << (get(p)-1));
		// cout << "P now " << p << endl;
		bool right = true;
		while (p!=0){
			int target = get(p);
			int rem  = p - (1 << (target-1));
			while (target != (cur-1)){
				cur--; p--; rem--;
				if (rem < 0){
					target--;
					rem = (1<<target)-1;
				}
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