#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res)%MOD;
	if (exp%2)
		return (res*base)%MOD;
	return res;
}
int inverse(int num){
	return power(num, MOD-2);
}

signed main(){
	int t; cin >> t;
	while (t--){
		int d; cin >> d;
		int num = 0;
		for (int i=0; i<=d; ++i){
			int fir = (i+1)/2;
			int sec = power(2, i);
			num = (num + (fir*sec)%MOD)%MOD;
		}
		int n = (power(2, d+1)-1)%MOD;
		int denom = (n*(n-1))%MOD;
		cout << (num*inverse(denom))%MOD << endl;
	}
	return 0;
}
