#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;
#define x first
#define y second
#define ld long double

int a, b; 
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
int query(ii point){
	cout << point.x << " " << point.y << endl;
	string res; cin >> res;
	if (res == "CENTER")
		return 2;
	else if (res=="HIT")
		return 1;
	return 0;
}
bool gg = 0;
void get_points(ii hit, vector<ii> &points){
	int right = E9; 
	int low = hit.x; // low inside, right outside
	
	if (query(mp(right, hit.y))){
		if (query(mp(right, hit.y)) == 2){
			gg = 1;
			return;
		}
		low = right;
	}
	else {
		while (low != right -1){
			int mid = (low + right)/2;
			int q = query(make_pair(mid, hit.y));
			if (q==2){
				gg = 1;
				return;
			}
			if (q >= 1)
				low = mid;
			else
				right = mid;
		}
	}
	points.pb(mp(low, hit.y));
	int left = -E9;
	low = hit.x;
	if (query(mp(left, hit.y))){
		if (query(mp(left, hit.y)) == 2){
			gg = 1;
			return;
		}
		low = left;
	}
	else {
		while (low != left + 1){
			int mid = (low + left)/2;
			int q = query(make_pair(mid, hit.y));
			if (q==2){
				gg = 1;
				return;
			}
			if (q >= 1)
				low = mid;
			else
				left = mid;
		}
	}
	points.pb(mp(low, hit.y));

	int top = E9; 
	low = hit.y; // low inside, right outside
	
	if (query(mp(hit.x, top))){
		if (query(mp(hit.x, top)) == 2){
			gg = 1;
			return;
		}
		low = top;
	}
	else {
		while (low != top -1){
			int mid = (low + top)/2;
			int q = query(make_pair(hit.x, mid));
			if (q==2){
				gg = 1;
				return;
			}
			if (q >= 1)
				low = mid;
			else
				top = mid;
		}
	}
	points.pb(mp(hit.x, low));
	int bottom = -E9;
	low = hit.y;
	if (query(mp(hit.x, bottom))){
		if (query(mp(hit.x, bottom)) == 2){
			gg = 1;
			return;
		}
		low = bottom;
	}
	else {
		while (low != bottom + 1){
			int mid = (low + bottom)/2;
			int q = query(make_pair(hit.x, mid));
			if (q==2){
				gg = 1;
				return;
			}
			if (q >= 1)
				low = mid;
			else
				bottom = mid;
		}
	}
	points.pb(mp(hit.x, low));
}


void solve(){
	vector<ii> points = { make_pair(0, 0), make_pair(E9/2, E9/2), make_pair(-E9/2, E9/2), make_pair(E9/2, -E9/2), make_pair(-E9/2, -E9/2)};
	ii hit;
	bool got = 0;
	for (ii point: points){
		int q = query(point);
		if (q == 2){
			hit = point; got = 1;
			break;
		}
		if (q == 1){
			hit = point;
			break;
		}
	}
	if (got)
		return;
	vector<ii> surface; 
	get_points(hit, surface);
	if (gg == 1){
		gg = 0;
		return;
	}


	// cout << "points " << endl;
	// for (ii point: surface){
	// 	cout << point.x << " " << point.y << endl;
	// }
	int c_x = (surface[0].x + surface[1].x)/2;
	int c_y = (surface[2].y + surface[3].y)/2;
	for (int x = c_x - 2; x<=c_x+2; ++x){
		for (int y=c_y -2; y<=c_y +2; ++y){
			int q = query(mp(x, y));
			if (q==2)
				return;
		}
	}
	
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t >> a >> b;
	while (t--){
		solve();
	}
	return 0;
}