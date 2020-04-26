#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#pragma gcc optimise('O3')
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
struct cus {
	int type, x, y, i;
};

bool custom(cus &l, cus&r){
	if (l.x != r.x)
		return l.x < r.x;
	if (l.type != r.type)
		return l.type < r.type;
	return l.y < r.y;
}
void update(vector<int> &bit, int i,int n){
	// cout << "update " << i << endl;
	for (; i<n; i = i | i + 1)
		bit[i]++;
}
int sum( vector<int> &bit, int i, int n){
	// cout << "sum " << i << endl;

	int sum = 0;
	for (; i >= 0; i = (i&(i+1)) - 1)
		sum += bit[i];
	return sum;
}

void solve(){
	int n, q; cin >> n >> q;
	vector<cus> points;
	vector<int> vals;

	for (int i=0; i<n; ++i){
		int x, y; cin >> x >> y;
		if (x < y) continue;
		cus cur = {1, x-y, x+y, -1};
		points.pb(cur);
		// cout << "main updated with " << cur.y << endl;
		if (cur.y <= 1000000)
			vals.push_back(cur.y);
	}
	sort(vals.begin(), vals.end());
	for (int i=0; i<q; ++i){
		int l, r; cin >> l >> r;
		cus cur = {0, l, r, i};
		points.pb(cur);
	}
	sort(points.begin(), points.end(), custom);
	vector<int> bit(1000001, 0);
	int ans[q];
	for (cus cur: points){
		// cout << "cur type " << cur.type << endl;
		// cout << "x " << cur.x << " y " << cur.y << " i " << cur.i << endl;
		if (cur.type == 1){
			if (cur.y <= 1000000){
				update(bit, cur.y, 1000001);
			}
			continue;
		}
		int here = sum(bit, cur.y, 1000001);
		// cout << "here " << here << endl;
		int tot = upper_bound(vals.begin(), vals.end(), cur.y) - vals.begin();
		// cout << "tot " << tot << endl;
		ans[cur.i] = tot - here;
		// cout << "ans " << ans[cur.i] << endl;
	}
	for (int i=0; i<q; ++i){
		cout << ans[i] << endl;
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}