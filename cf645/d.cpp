#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;

int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp % 2)
		return (res*base)%MOD;
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}

void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> pref(2*n);
	int a[n];
	cin >> a[0];
	pref[0] = a[0];
	int tot[2*n];
	tot[0] = (pref[0]*(pref[0]+1))/2;
	
	for (int i=1; i<n; ++i){
		cin >> a[i];
		pref[i] = a[i];
		int tem = (pref[i]*(pref[i]+1))/2;
		pref[i] += pref[i-1];
		tot[i] = tot[i-1] + tem;
	}
	for (int i=n; i<2*n; ++i){
		pref[i] = a[i-n];
		int tem = (pref[i]*(pref[i]+1))/2;
		pref[i] += pref[i-1];
		tot[i] = tot[i-1] + tem;
	}
	int valx = 0;
	for (int i=0; i<2*n; ++i){
		int val = pref[i];
		int start = pref[i] - x + 1;
		if (start <= 0) continue;
		auto itr = lower_bound(pref.begin(), pref.end(), start);
		int index = itr - pref.begin();
		int including = pref[i];
		int count = tot[i];
		if (index != 0){
			including -= pref[index-1];
			count -= tot[index - 1];
		}
		int rem = including  - x;
		count -=  (rem*(rem+1))/2;
		valx = max(valx, count);
		// cout << "backward i " << i << " got " << count << endl;

	}

	for (int i=0; i<2*n; ++i){
		int st = x;
		if (i!=0) st += pref[i-1];
		if (st > pref[2*n-1]) continue;
		auto it = lower_bound(pref.begin(), pref.end(), st);

		int ind = it - pref.begin();
		int days = pref[ind-1];
		if (i!=0) days -= pref[i-1];
		int left = x - days;
		int vv = tot[ind-1];
		if (i!=0) vv -= tot[i-1];
		vv += (left*(left+1))/2;
		// cout << "forward i " << i << " got " << vv << endl;

		valx = max(valx, vv);
	}
	cout << valx << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}