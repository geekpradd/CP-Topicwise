#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;
#define is pair<int, string>
map<ii, is> memo;

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
is solve(int x, int y){
	if (memo.count(make_pair(x, y)))
		return memo[make_pair(x, y)];
	is ret;
	// cout << "X " << x << " y " << y << endl;
	if (x == 0 && y == 0){
		ret.second = "";
		ret.first = 0;
		memo[make_pair(x, y)] = ret;
		return memo[make_pair(x, y)];
	}
	if (x==0 && y == 1){
		memo[make_pair(x, y)] = make_pair(1, "N");
		return memo[make_pair(x, y)];
	}
	if (x==1 && y == 0){
		memo[make_pair(x, y)] = make_pair(1, "E");
		return memo[make_pair(x, y)];
	}
	if (x%2 == y%2){
		ret.first = E9;
		memo[make_pair(x, y)] = ret;
		return memo[make_pair(x, y)];
	}
	if (x%2){
		is fir = solve((x-1)/2, y/2);
		is sec = solve((x+1)/2, y/2);
		if (fir.first < sec.first){
			fir.second += "E";
			memo[make_pair(x, y)] = fir;
			return memo[make_pair(x, y)];
		}
		else {
			sec.second += "W";
			memo[make_pair(x, y)] = sec;
			return memo[make_pair(x, y)];
		}
	}
	if (y%2){
		is fir = solve((x)/2, (y-1)/2);
		is sec = solve((x)/2, (y+1)/2);
		if (fir.first < sec.first){
			fir.second += "N";
			memo[make_pair(x, y)] = fir;
			return memo[make_pair(x, y)];
		}
		else {
			sec.second += "S";
			memo[make_pair(x, y)] = sec;
			return memo[make_pair(x, y)];
		}
	}

}

void solve(){
	int x, y; cin >> x >> y;
	bool x_flip = 0, y_flip = 0;
	if (x < 0){
		x = -x; x_flip = 1;
	}
	if (y < 0){
		y = -y; y_flip = 1;
	}
	is cur = solve(x, y);
	if (cur.first == E9){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	string out = cur.second;
	if (x_flip){
		for (int i=0; i<out.size(); ++i){
			if (out[i]=='E') out[i] = 'W';
			else  if (out[i] == 'W') out[i] = 'E';
		}
	}
	if (y_flip){
		for (int i=0; i<out.size(); ++i){
			if (out[i]=='N') out[i] = 'S';
			else  if (out[i] == 'S') out[i] = 'N';
		}
	}
	for (int i=out.size()-1; i>=0; --i){
		cout << out[i];
	}
	cout << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		cout << "Case #" << w << ": ";
		solve();
	}

	return 0;
}