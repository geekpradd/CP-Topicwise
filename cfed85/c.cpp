#include <bits/stdc++.h>
#define ii pair<int, int>
#define pb push_back
using namespace std;
 
signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		long long a[n], b[n];
		cin >> a[0] >> b[0];
		long long sasta[n];
		long long z = 0;
		long long min_val;
		
		long long sum = 0;
		for (int i=1; i<n;++i){
			cin >> a[i] >> b[i];
			sasta[i] = max(a[i]-b[i-1], z); sum += sasta[i];
			if (i == 1)
				min_val = a[i] - sasta[i];
			else
				min_val = min(min_val, a[i] - sasta[i]);
 
		}
		sasta[0] = max(a[0]-b[n-1], z);
		sum += sasta[0];
		min_val = min(min_val, a[0] - sasta[0]);
		cout << sum + min_val << endl;
		
	}
	return 0;
}
