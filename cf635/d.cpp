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
int cost(int a, int b, int c){
	return (a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a);
}

struct q{
	int f, s, t;
};
q params(vector< vector<int> > &vals, int inds[]){
	vector<ii> k;
	k.push_back(make_pair(vals[0][inds[0]], 0));
	k.push_back(make_pair(vals[1][inds[1]], 1));
	k.push_back(make_pair(vals[2][inds[2]], 2));
	sort(k.begin(), k.end());
	q v = {k[0].second, k[1].second, k[2].second};
	return v;

}

void solve(){
	int r, g, x; cin >> r >> g >> x;
	vector< vector<int> > vas(3);
	vas[0].resize(r); vas[1].resize(g); vas[2].resize(x);
	set<int> l, m, n;
	vector< vector<int> > vals(3);

	for (int i=0; i<r; ++i) cin >> vas[0][i];
	for (int i=0; i<g; ++i) cin >> vas[1][i];
	for (int i=0; i<x; ++i) cin >> vas[2][i];
	sort(vas[0].begin(), vas[0].end());
	sort(vas[1].begin(), vas[1].end());
	sort(vas[2].begin(), vas[2].end());
	int prev = -1;
	for (int i=0; i<r; ++i){
		if (vas[0][i]!=prev){
			prev = vas[0][i];
			vals[0].pb(prev);
		}
	}
	int prev2 = -1;
	for (int i=0; i<g; ++i){
		if (vas[1][i]!=prev2){
			prev2 = vas[1][i];
			vals[1].pb(prev2);
		}
	}
	int prev3 = -1;
	for (int i=0; i<x; ++i){
		if (vas[2][i]!=prev3){
			prev3 = vas[2][i];
			vals[2].pb(prev3);
		}
	}

	int val = cost(vals[0][0], vals[1][0], vals[2][0]);
	int inds[3]; inds[0] = inds[1] = inds[2] = 0;
	q p = params(vals, inds);
	while (inds[p.f] < vals[p.f].size() || inds[p.s] < vals[p.s].size() || inds[p.t] < vals[p.t].size()){
		while (vals[p.f][inds[p.f]] < vals[p.s][inds[p.s]]){
			inds[p.f]++;
			if (inds[p.f] >= vals[p.f].size()){
				inds[p.f]--; break;
			}
			if (vals[p.f][inds[p.f]] > vals[p.s][inds[p.s]]){
				inds[p.f]--; break;
			}
			val = min(val, cost(vals[p.f][inds[p.f]], vals[p.s][inds[p.s]], vals[p.t][inds[p.t]]));
		}
		double mean = (vals[p.f][inds[p.f]] + vals[p.t][inds[p.t]])/2.0;
		if (inds[p.s] != vals[p.s].size() - 1){
			int other = vals[p.s][inds[p.s] + 1];
			double d1 = other - mean; double d2 = vals[p.s][inds[p.s]] - mean;
			if (abs(d1) < abs(d2)){
				inds[p.s]++;
			}
			else if (inds[p.f] != vals[p.f].size() - 1){
				inds[p.f]++;
			}
			else {
				val = min(val, cost(vals[p.f][inds[p.f]], vals[p.s][inds[p.s]], vals[p.t][inds[p.t]]));
				break;
			}
			val = min(val, cost(vals[p.f][inds[p.f]], vals[p.s][inds[p.s]], vals[p.t][inds[p.t]]));
		}
		else if (inds[p.f] != vals[p.f].size() - 1){
			inds[p.f]++;
			val = min(val, cost(vals[p.f][inds[p.f]], vals[p.s][inds[p.s]], vals[p.t][inds[p.t]]));
		}
		else {
			val = min(val, cost(vals[p.f][inds[p.f]], vals[p.s][inds[p.s]], vals[p.t][inds[p.t]]));
			break;
		}
		p = params(vals, inds);
	}
	
	cout << val << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
	}
}