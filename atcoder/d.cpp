#include <bits/stdc++.h>
using namespace std;

int steps(int num){
	if (num == 0)
		return 0;
	int count = __builtin_popcount(num);
	return 1 + steps(num % count);
}

signed main(){
	int n; cin >> n;
	vector<char> x(n);
	int m = 0;
	for (int i=0; i<n; ++i){
		char inp; cin >> inp;
		if (inp == '1') m++;
		x[i] = inp;
	}

	
	int rem_minus = 0;
	int rem_plus = 0;
	int cur_m = 1;
	int cur_p = 1;
	for (int i=n-1; i>=0; --i){
		if (x[i] == '1'){
			if (m > 1){
				rem_minus = (rem_minus + cur_m)%(m-1);

			}
			rem_plus = (rem_plus + cur_p)%(m+1);
		}

		if (m > 1)
			cur_m = (cur_m*2)%(m-1);
		cur_p = (cur_p*2)%(m+1);
	}

	vector<int> ans(n);
	cur_m = 1; cur_p = 1;
	for (int i=n-1; i>=0; --i){
		if (x[i] == '0'){
			int val = rem_plus;
			val = (val + cur_p)%(m+1);
			ans[i] = 1 + steps(val);
		}
		else {
			if (m == 1){
				ans[i] = 0;
			}
			else {
				int val = rem_minus;
				val = (val - cur_m)%(m-1);
				if (val < 0) val += (m-1);
				ans[i] = 1 + steps(val);
			}
			
		}
		if (m > 1)
			cur_m = (cur_m*2)%(m-1);
		cur_p = (cur_p*2)%(m+1);
	}

	for (int i=0; i<n; ++i){
		cout << ans[i] << endl;
	}
}