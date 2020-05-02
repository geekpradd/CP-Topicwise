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
	int n, k; cin >> n >> k;
	int r = 0, b = 0;
	int count = 0;
	ii vals[n];
	ii maxr[n];
	vector<int> rems(n, -1);
	int r_r = 0, b_b = 0;
	int net_rems = 0;
	for (int i=0; i<n; ++i){
		cin >> vals[i].first >> vals[i].second;
		if (vals[i].first + vals[i].second < k){
			r += vals[i].first; b += vals[i].second;
		}
		else {
			count += (vals[i].first + vals[i].second)/k;
			rems[i] = (vals[i].first + vals[i].second)%k;
			maxr[i].second = min(rems[i], vals[i].second);
			b_b += maxr[i].second;
			maxr[i].first = min(rems[i], vals[i].first);
			r_r += maxr[i].first;
			net_rems += rems[i];
		}
	}
	count += (r/k); count += (b/k); count += net_rems/k;
	int left_over = net_rems % k;
	r = r%k; b = b%k;
	int b_val = min(left_over, (b_b)%k);
	int r_val = min(left_over, (r_r)%k);
	if (b_val + b >= k)
		count++;
	if (r_val + r >=k)
		count++;
	cout << count << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}