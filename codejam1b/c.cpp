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
int r, s;
bool correct(vector<ii> &seq){
	int k = 0;
	bool ok = 1;
	for (int i=1; i<=r; ++i){
		for (int j=1; j<=s; ++j){
			if (seq[k].first != i){
				ok = 0; break;
			}
			k++;
		}
		if (ok == 0)
			break;
	}

	return ok;
}

vector<ii> dos(int moves, vector<ii> my){
	vector<ii> movs;
	if (moves <= 0)
		return movs;

	cout << moves << endl;
	bool got = 0;
	
		for (int i=1; i<=r*s-1; ++i){
			for (int j=1; j+i<=r*s; ++j){
				movs.pb(mp(i, j));
				vector<ii> sec;
				for (int l=0; l<j; ++l){
					sec[l] = my[i+l];
				}
				for (int l=0; l<i; ++l){
					sec[j+l] = my[l];
				}
				vector<ii> res = dos(moves-1, sec);
				if (correct(sec)){
					for (ii x: res){
						movs.pb(x);
					}
					return movs;
				}
			}
		}

	vector<ii> emp;
	return emp;
	
	
}
void solve(){
	 cin >> r >> s;
	vector<ii> seq(r*s+1);
	int k = 0;
	for (int i=1; i<=s; ++i){
		for (int j=1; j<=r; ++j){
			seq[k+1] = mp(j, i); k++;
		}
	}

	
	for (int i=1; i<=r*s; ++i){
		vector<ii> res = dos(i, seq);
		if (res.size()){
			cout << res.size() << endl;
			for (ii x: res){
				cout << x.first << " " << x.second << endl;
			}

	}
		}

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		cout << "Case #" << w << ": " << endl;
		solve();
	}
	return 0;
}