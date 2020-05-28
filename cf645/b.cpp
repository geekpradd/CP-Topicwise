#include <bits/stdc++.h>
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
	int n; scanf("%d", &n);

	int a[n];
	for (int i=0; i<n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int val = 1;
	int unused = 0;
	for (int i=0; i<n; ++i){
		int j = i;
		for (j=i; j<n; ++j){
			if (a[j] != a[i])
				break;
		}
		if (j==n-1){
			if (a[n-1] == a[i]){
				j++;
			}
		}
		int num = j - i;
		if (num + val + unused > a[i]){
			val = val + num + unused;
			unused = 0;
		}
		else {
			unused += num;
		}
		i = j - 1;
	}
	printf("%d\n", val);
}


signed main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; scanf("%d", &t);
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}