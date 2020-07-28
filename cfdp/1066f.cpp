#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E13 10000000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define edge pair<int, pair<int, int> > 
#define REP0(i, n) for (int i=0; i<n; ++i)
#define REP1(i, n) for (int i=1; i<=n; ++i)
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
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
int dist(ii &a, ii &b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
	int n; cin >> n;
	ii points[n];
	vector<int> least(n+1);
	for (int i=0; i<n; ++i){
		cin >> points[i].first >> points[i].second;
		least[i+1] = max(points[i].first, points[i].second);
	}
	least[0] = 0;
	sort(least.begin(), least.end());
	map<int, int> compress;
	vector<int> inverse;
	inverse.pb(0);
	compress[0] = 0;
	int start = 0;
	int current = 0;
	for (int i=1; i<=n; ++i){
		if (least[i] == current) continue;
		else {
			current = least[i];
			start++;
			compress[current] = start;
			inverse.pb(current);
		}
	}
	vector<int> lh(start+1, E13);
	vector<int> mh(start+1, -1);
	vector<int> lv(start+1, E13);
	vector<int> mv(start+1, -1);

	for (int i=0; i<n; ++i){
		int cat = max(points[i].first, points[i].second);
		int id = compress[cat];
		int other = -cat + points[i].first + points[i].second;
		if (other == points[i].first){
			lh[id] = min(lh[id], other);
			mh[id] = max(mh[id], other);
		}
		if (other == points[i].second){
			lv[id] = min(lv[id], other);
			mv[id] = max(mv[id], other);
		}
	}

	vector<ii> first(start+1);
	vector<ii> second(start+1);
	vector<int> value(start+1);
	for (int i=1; i<=start; ++i){
		int val;
		if (lh[i] == E13){
			val = mv[i] - lv[i];
			first[i] = mp(inverse[i], lv[i]);
			second[i] = mp(inverse[i], mv[i]);
		}
		else if (lv[i] == E13){
			val = mh[i] - lh[i];
			first[i] = mp(lh[i], inverse[i]);
			second[i] = mp(mh[i], inverse[i]);
		}
		else {
			val = 2*inverse[i] - (lh[i] + lv[i]);
			first[i] = mp(lh[i], inverse[i]);
			second[i] = mp(inverse[i], lv[i]);
		}
		value[i] = val;
		// DUMP(i);
		// DUMP(val);
		// DUMP(first[i]);
		// DUMP(second[i]);
	}
	int dp[start+1][2];
	dp[start][0] = dp[start][1] = value[start];
	for (int i=start-1;i>=1;--i){
		dp[i][0] = value[i] + min(dp[i+1][0] + dist(second[i], first[i+1]), dp[i+1][1] + dist(second[i], second[i+1]));
		dp[i][1] = value[i] + min(dp[i+1][0] + dist(first[i], first[i+1]), dp[i+1][1] + dist(first[i], second[i+1]));
	}
	ii origin = mp(0, 0);

	int ans = min(dp[1][0] + dist(first[1], origin), dp[1][1] + dist(second[1], origin));

	cout << ans << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	
	return 0;
}