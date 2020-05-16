#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
using namespace std;

string decToBinary(int n) 
{ 
    // array to store binary number 
    string bin = "";
  
    // counter for binary array 
    while (n > 0) { 
  
        // storing remainder in binary array 
        char cur = ('0' + (n%2));
        bin += cur;
        n = n / 2; 
    } 
  
  	reverse(bin.begin(), bin.end());
    // printing binary array in reverse order 
    return bin;
} 
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

void solve(int x, int y, int l, int r){
	int best = x | y;
	int indexer = 1LL << (63 - 1);
	bool diff = 0;
	int current = 0;
	vector<int> candidates;
	// cout << "l "<< decToBinary(l) << endl;
	// cout << "r " << decToBinary(r) << endl;
	// cout << "best " << decToBinary(best) << endl;
	// cout << "indexer " << decToBinary(indexer) << endl;
	while (indexer > 0){
		bool in_r = ((indexer & r) > 0); bool in_l = ((indexer & l) > 0);
		// cout << "indexer " << decToBinary(indexer) << endl;
		// cout << "in_r " << in_r << endl;
		// cout << "in_l " << in_l << endl;
		if (!diff & (in_r == in_l)){
		}
		else if (!diff & (in_r != in_l)){
			diff = 1;
			int cur = current + (best & (indexer-1));
			candidates.push_back(cur);
		}
		else if (in_r){
			int cur = current + (best & (indexer - 1));
			candidates.push_back(cur);
		}
		current += indexer*in_r;
		indexer = indexer >> 1;
	}
	candidates.pb(current);
	int max_val = -1, z;
	for (int i: candidates){
		cout << i << " in  cand" << endl;
		int l = i&x; int r = i&y;
		int val = l*r;
		if (val > max_val){
			max_val = val;
			z = i;
		}
		else if (val == max_val){
			if (i < z)
				z = i;
		}
	}
	cout << z << endl;
	
}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	for (int w=1; w<=t; ++w){
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		solve(x, y, l, return);
	}
	return 0;
}