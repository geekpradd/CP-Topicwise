#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
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

signed main(){
	int n; cin >> n;
	int a[n];
	a[0] = 10;
	int sum = a[0];
	for (int i=1; i<n; ++i){
		a[i] = ((9*sum)%MOD + (9*power(10, i))%MOD)%MOD;
		sum = (sum+a[i])%MOD;
	}
	for (int i=n-1; i>=0; --i){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
