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
#define iii pair<int, pair<int, int> > 
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
int get(int h, int w){
	w = (w)%MOD;
	int first = (w*(w+1))%MOD; 


	int second = (h*(h+1))%MOD;
	int ans = (first*second)%MOD;
	ans = (ans*inverse(4))%MOD; 
	return ans;
}

int y(int x){
	int ans = (x*(x+1))%MOD;
	ans = (ans*inverse(2))%MOD;
	return ans;
}

signed main(){
	int n; cin >> n;
	int h[n];
	for (int i=0; i<n; ++i) cin >> h[i];

	int w[n];
	for (int i=0; i<n; ++i){
		cin >> w[i];
	} 


	int ans = 0;
	int prev = 0;
	set<iii> values;
	for (int i=0; i<n; ++i){
		ans = (ans + get(h[i], w[i]))%MOD;
		iii comp = mp(h[i], mp(-1, -1));

		auto itr = values.upper_bound(comp);
		auto copy = itr;
		int width = 0;
		while (copy != values.end()){
			width = (width + (*copy).second.first)%MOD; 
			copy++;
		}
		int prev_vals = 0;
		if (itr != values.begin()){
			itr--;
			prev_vals = (*itr).second.second;
			itr++;
		}
		ans = (ans + (prev_vals*w[i])%MOD)%MOD;
		int cur_zone = (y(h[i])*w[i])%MOD;
		cur_zone = (cur_zone*width)%MOD;

		ans = (ans + cur_zone)%MOD;
		width = (width + w[i])%MOD;
		int cur = (y(h[i])*width)%MOD;
		int tot = (cur + prev_vals)%MOD;

		iii current = mp(h[i], mp(width, tot));
		values.erase(itr, values.end());
		values.insert(current);
	}

	cout << ans << endl;

	return 0;
}