#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n, m; cin >> n >> m;
	pair<int, int> l[m];
	int s = 0;
	for (int i=0; i<m; ++i){
		cin >> l[i].first; l[i].second=i; s+= l[i].first;
	}
	if (s<n){
		cout << -1 << endl;
		return 0;
	}
	int start = 1;
	int ans[m];
	int j = 0;
	bool pos = 0;
	while (s>n){
		if (l[j].first > n){
			pos = 1; break;
		}
		ans[l[j].second] = start;
		int posib = min(l[j].first - 1, s-n);
		s -= l[j].first;
		n -= l[j].first - posib;
		start += l[j].first - posib;
		j++;
	}
	for (; j<m; ++j){
		ans[l[j].second] = start;
		start += l[j].first;
	}
	if (pos){
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<m; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}




