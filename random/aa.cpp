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
	int n; cin >> n;
	int c = 0;
	map<int, int> found;
	set<int> backs;
	int prev = 0;
	int oc = 0;
	set<int>::iterator it;
	for (int i=0; i<n; ++i){
		int t; cin >> t;
		
		if (t < prev){
			if (oc)
				backs.erase(it);
			backs.insert(prev);
			cout << "inserted " << prev << endl;
			auto itr = backs.lower_bound(t); 
			if (*itr == t){
				it = itr;
				oc = 1;
			}
			else if (itr == backs.begin()){

				cout << *itr << endl;
				cout << t << endl;
				cout << "got nothing increment" << endl;
				c++;
			}
			else {
				itr--;
				cout << "got " << *itr << endl;
				it = itr;
				oc = 1;
			}
		}
		prev = t;
	}
	cout << c + 1 << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		solve();
	}
	return 0;
}