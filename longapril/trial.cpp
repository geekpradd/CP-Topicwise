#include <bits/stdc++.h>
#define int long long
using namespace std;
int power(int base, int exp){
	if (exp==0)
		return 1;
	int res = power(base, exp/2);
	res = (res*res);
	if (exp%2)
		return (res*base);
	return res;
}


signed main(){
	long long c = 9007199254740992;
	cout << power(43, 11) << endl;
	cout << (53*log(2) == log(c)) << endl;

}
