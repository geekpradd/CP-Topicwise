#include <bits/stdc++.h>
#define int long long
#define double long double
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
	int h, c, t; cin >> h >> c >> t;
	double mean = (h+c)/(2.0);
	
	if (t >= h){
		cout << 1 << endl;
		return;
	}
	else if (mean >= t){
		cout << 2 << endl;
		return;
	}
	else{
		int upper = 10;
		double denom = 2*upper + 1;
		double val = ((upper+1)*h + upper*c)/denom;
		while (val >= t){
			upper = 10*upper;
			denom = 2*upper + 1;
			val = ((upper+1)*h + upper*c)/denom;
		}
		int low = 0, high = upper;
		while (low < high - 1){
			int mid = (low + high)/2;
			double denom = 2*mid + 1;
			double val = ((mid+1)*h + mid*c)/denom;
			if (val >= t){
				low = mid;
			}
			else {
				high = mid;
			}
		}
		denom = 2*low + 1;
		val = ((low+1)*h + low*c)/denom;
		double denom2 = 2*high + 1;
		double val2 = ((high+1)*h + high*c)/denom2;
		if (abs(val-t)<=abs(val2-t)){
			cout << 2*low + 1 << endl;
		}
		else {
			cout << 2*high + 1 << endl;
		}
	}
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}