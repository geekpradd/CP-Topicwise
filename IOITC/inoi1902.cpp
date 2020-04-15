#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;
int n, l;
vector<ii> a;
vector< vector<int> > batches;
int gap_max = 0;

bool achievable(int g){
	if (g <= gap_max)
		return true;
	int k = batches.size();
	int dp[k][2]; 
	int max_val = 1;
	for (int i=k-1; i>=0; --i){
		dp[i][0] = dp[i][1] = 1; // base case, just choose yourself
		for (int j=i+1; j<k; ++j){
			if (abs(batches[i][0] - batches[j][0])>=g){
				dp[i][0] = max(dp[i][0], 1 + dp[j][0]);
			}
			if (abs(batches[i][0] - batches[j][batches[j].size()-1])>=g){
				dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
			}
			if (abs(batches[i][batches[i].size()-1] - batches[j][0])>=g){
				dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
			}
			if (abs(batches[i][batches[i].size()-1] - batches[j][batches[j].size()-1])>=g){
				dp[i][1] = max(dp[i][1], 1 + dp[j][1]);
			}
		}
		max_val = max(max_val, max(dp[i][0], dp[i][1]));
	}
	return (l<=max_val);
}

void solve(){
	cin >> n >> l;
	a.resize(n);

	for (int i=0; i<n; ++i){ cin >> a[i].first; a[i].second = i; }
	sort(a.begin(), a.end());
	int prev = -1;
	vector<int> cur;
	for (int i=n-1; i>=0; --i){
		if (a[i].first != prev){
			if (cur.size()>0){
				batches.pb(cur);
			}
			cur.clear();
		}
		cur.pb(a[i].second);
		prev = a[i].first;
	}
	if (cur.size()>0)
		batches.pb(cur);
	for (vector<int> batch: batches){
		gap_max = max(gap_max, batch[0] - batch[batch.size()-1]);
	}


	int low = 0, high = n; // high is not achievable, low is;
	while (low != high - 1){
		int mid = (low+high)/2;
		if (achievable(mid)){
			low = mid;
		}
		else {
			high = mid;
		}
	}
	cout << low << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
		batches.clear();
		a.clear();
		gap_max = 0;
	}
}