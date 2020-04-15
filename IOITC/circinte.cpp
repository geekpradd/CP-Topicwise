#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;
int m, n;
vector<ii> vals;
int max_ind = -1;

bool achievable(int gap){
	bool pos = 1;
	int cur_pos = vals[max_ind].first;
	int dist;
	if (max_ind  == n-1){
		dist = vals[0].second + (m-vals[n-1].first);
	}
	else {
		dist = vals[max_ind + 1].second - vals[max_ind].first;
	}
	int index = max_ind;
	for (int i=1; i<=n; ++i){
		if (gap > dist){
			pos = 0; break;
		}
		cur_pos = (cur_pos + gap)%m;
		if (index == n-1){
			if (cur_pos > vals[index].first || cur_pos < vals[0].first)
				cur_pos = vals[0].first;
		}
		else {
			if (cur_pos < vals[index+1].first)
				cur_pos = vals[index+1].first;
		}
		index = (index+1)%n;
		if (index  == n-1){
			dist = vals[0].second + (m-cur_pos);
		}
		else {
			dist = vals[index + 1].second - cur_pos;
		}
	}
	return pos;
}

void solve(){
	cin >> m >> n; vals.resize(n);
	int low = 0, high = m/n + 1; // high not achievable;
	for (int i=0; i<n; ++i) cin >> vals[i].first >> vals[i].second;
	int gap = 0;
	for (int i=0; i<n-1; ++i){
		int cur_gap = vals[(i+1)].first - vals[i].first;
		if (cur_gap > gap){
			gap = cur_gap;
			max_ind = i;
		}
	}
	int sec = vals[0].first - vals[n-1].first + m;
	if (sec > gap){
		gap = sec;
		max_ind = n-1;
	}
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
	solve();
}