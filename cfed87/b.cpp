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
	string inp; cin >> inp;
	vector<int> a, b, c;
	for (int i=0; i<inp.size(); ++i){
		int ch = inp[i] - '0';
		if (ch==1){
			a.pb(i);
		}
		else if(ch==2){
			b.pb(i);
		}
		else {
			c.pb(i);
		}
	}
	bool found = 0;
	int val = E9;
	if (c.size()==0 || a.size()==0 || b.size()==0){
		cout << 0 << endl;
		return;
	}
	else {
		for (int i=0; i<inp.size()-2; ++i){
			if (inp[i]!=inp[i+1]){
				int v1 = inp[i] - '0';
				int v2 = inp[i+1] - '0';
				int other = 6 - v1 - v2;
				// cout << "other " << i << " is " << other << endl;
				if (other == 1){
					auto itr = upper_bound(a.begin(), a.end(), i);
					if (itr != a.end()){
						int dist = *itr;
						int va = dist - i + 1;
						val = min(va, val);
					}
				}
				else if (other == 2){
					auto itr = upper_bound(b.begin(), b.end(), i);
					if (itr != b.end()){
						int dist = *itr;
						int va = dist - i + 1;
						val = min(va, val);
					}
				}
				else {
					auto itr = upper_bound(c.begin(), c.end(), i);
					if (itr != c.end()){
						int dist = *itr;
						int va = dist - i + 1;
						val = min(va, val);
					}
				}
			}
		}
	}
	cout << val << endl;
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