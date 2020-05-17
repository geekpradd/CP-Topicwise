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
	int l, r;
	cin >> l >> r;
	bool first = 0;
	if (r >= l){
		int gap = r - l;
		long double root = sqrt(1+8*gap) - 1;
		root = root/2;
		int val = root;	
		int zone = (val*(val+1))/2;
		bool swapp = 0;
		if (zone == gap){
			swapp = 1;
		}
		r = r - zone;
		long double frr = sqrt(val*val + 4*r) - val;
		frr = frr/2;
		int m = frr;
		long double fff = sqrt((val+1)*(val+1)+4*l) - (val+1);
		fff = fff/2;
		int n = fff;
		int zone2 = m*val + m*m;
		int zone3 = n*val + n*n + n;
		l = l - zone3;
		r = r - zone2;
		int total = val + n + m;
		cout << total << " ";
		if (swapp){
			swap(l, r);
		}
		cout << l << " ";
		cout << r << endl;
	}
	else {
		int gap = l - r;
		long double root = sqrt(1+8*gap) - 1;
		root = root/2;
		int val = root;	
		int zone = (val*(val+1))/2;
		
		l = l - zone;
		long double frr = sqrt(val*val + 4*l) - val;
		frr = frr/2;
		int m = frr;
		long double fff = sqrt((val+1)*(val+1)+4*r) - (val+1);
		fff = fff/2;
		int n = fff;
		int zone2 = m*val + m*m;
		int zone3 = n*val + n*n + n;
		r = r - zone3;
		l = l - zone2;
		int total = val + n + m;
		cout << total << " ";
		
		cout << l << " ";
		cout << r << endl;
	}
	
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