#include <bits/stdc++.h>
#include <fstream>
#define MOD 1000000007

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

	int t; cin >> t;
	ofstream fout("log.txt");

	while (t--){

		int n; cin >> n;

		int ans = n;

		int bound = log2(n);

		vector<int> sieve(bound+1, 1);
		for (int i=2; i<=bound; ++i){
			if (!sieve[i]) continue;
			for (int j=2*i; j<=bound; j+=i)
				sieve[j] = 0;
		}
		map<int, int> found;
		int cur = 0;
		bool first = false;
		for (int y=2; y<=bound; ++y){
			if (!sieve[y]) continue;
			for (int x=2; y*log(x)<=log(n); ++x){

				int po = power(x, y); 
				
				int count = n/po;

				if (found.count(po)) continue;
				found[po] = 1;


				po = (po)%MOD; count = (count)%MOD;
				ans = (ans + po*count)%MOD;
				if (y > 2){
					fout << x << " " << y << endl;
					cur = (cur + po*count)%MOD;
				}
				

			}

		}

		cout << ans << endl;

	}

	return 0;

}

				




