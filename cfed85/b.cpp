#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
using namespace std;
 
signed main(){
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x;
		int a[n];
		vector<int> less;
		int val = 0;
		for (int i=0; i<n; ++i){
			cin >> a[i];
			if (a[i] >= x)
				val += (a[i]-x);
			else
				less.push_back(a[i]);
		}
		sort(less.begin(), less.end(), greater<int>());
		// cout << "val is " << val << endl;
		int count = 0, tot = 0, j = 0;
		while (tot <= val && count < n && j < less.size()){
			// cout << "Adding " << less[j] << endl;
			tot += (x - less[j]);
			// cout << "Tot " << tot << endl;
			j++;
			if (tot <= val)
				count++;
		}
		// cout << "less " << less.size() << endl;
		cout << count + (n - less.size()) << endl;
	}
	return 0;
}
