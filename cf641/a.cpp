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
	res = (res*res);
	if (exp % 2)
		return (res*base);
	return res;
}
int inverse(int n){
	return power(n, MOD-2);
}

void solve(){
	int n; cin >> n;
	vector<ii> sieve(200001, mp(1, 0));
	for (int i=2; i<=200000; ++i){
		if (sieve[i].second != 0) continue;
		sieve[i].first = i; sieve[i].second = 0;
		for (int j=2*i; j<=200000; j+=i){
			sieve[j] = mp(i, j/i);
		}
	}

	int a[n];

	vector<ii> ps(200001, mp(0, 0));
	vector<ii> least_two(200001, mp(E9, E9));
	vector<int> pp(200001, 0);
	vector<int> primes;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		int to = a[i];
		cout << "to " << to << endl;
		int prev = -1;
		while (to != 0){
			int prime = sieve[to].first;
			to = sieve[to].second;
			cout << "prime " << prime << " going " << to << endl;
			if (prev != prime){
				pp[prime]++;
				prev = prime;
			}
			
			if (ps[prime].second == a[i]){
				ps[prime].first++;
			}
			else {
				ii cur = least_two[prime];
				int cur_val = ps[prime].first;
				if (cur_val != 0){
					cout << "got cur " << cur_val << " for " << prime << endl;
					cout << cur.first << " and " << cur.second << endl;
					if (cur_val >= cur.first && cur_val < cur.second)
						cur.second = cur_val;
					else if (cur_val <= cur.first){
						cur.second = cur.first;
						cur.first = cur_val;
					}
					least_two[prime] = cur;
					cout << "least two " << prime << " is " << least_two[prime].first << "and " << least_two[prime].second << endl;
				}
				
				if (ps[prime].second == 0){
					cout << "got " << prime << endl;
					primes.push_back(prime);
				}
				ps[prime].second = a[i];
				ps[prime].first = 1;
			}
		}
	}
	int ans = 1;
	for (int p: primes){
		ii cur = least_two[p];
		int cur_val = ps[p].first;
		if (cur_val >= cur.first && cur_val < cur.second)
			cur.second = cur_val;
		else if (cur_val <= cur.first){
			cur.second = cur.first;
			cur.first = cur_val;
		}
		least_two[p] = cur;
		cout << "prime " << p << endl;
		cout << "Count" << pp[p] << endl;
		cout << "val " << least_two[p].first << " and " << least_two[p].second << endl;
		cout << "power is " << least_two[p].second << endl;
			if (pp[p] == n)
				ans = ans*power(p, least_two[p].second);
			else if (pp[p] == n-1){
				ans = ans*power(p, least_two[p].first);
			}
		
	}
	cout << ans << endl;
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}