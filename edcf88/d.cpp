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

void build(int arr[], int n, vector< vector<int> > &look, bool flip) 
{  
    for (int i = 0; i < n; i++) {
    	if (flip)
        	look[i][0] = -arr[i]; 
       	else
       		look[i][0] = arr[i];
    }
  
    for (int j = 1; (1 << j) <= n; j++) { 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
            if (look[i][j - 1] < look[i + (1 << (j - 1))][j - 1]) 
                look[i][j] = look[i][j - 1]; 
            else
                look[i][j] =  
                         look[i + (1 << (j - 1))][j - 1]; 
        } 
    } 
} 
   
int query(int L, int R, vector<vector<int> >&look) 
{ 
    int j = (int)log2(R - L + 1); 
  
    if (look[L][j] <= look[R - (1 << j) + 1][j]) 
        return look[L][j]; 
    else
        return look[R - (1 << j) + 1][j]; 
} 

void solve(){
	int n; cin >> n;
	int a[n+1];
	vector<int> pos[61];
	int pref[n+1];
	pref[0] = 0;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		pref[i] = a[i] + pref[i-1];
		
		pos[a[i]+30].pb(i);
	}
	int low[n+1];
	int up[n+1];

	for (int i=1; i<=n; ++i){
		int upper = n;
		int lower = 1;
		for (int num=a[i]+1; num<=30; ++num){
			int mask = num + 30;
			auto up = upper_bound(pos[mask].begin(), pos[mask].end(), i);
			if (up != pos[mask].end()){
				upper = min(upper, *(up) - 1);
			}
			if (up != pos[mask].begin()){
				up--;
				lower = max(lower, *(up) + 1);
			}
		}
		low[i] = lower;
		up[i] = upper;
		// cout << "low " << lower << " up " << upper << " for val " << a[i] << " index " << i << endl;
	}

	int j = log2(n+1) + 3;
	vector< vector<int> > lookmax(n+1, vector<int>(j));
	vector< vector<int> > lookmin(n+1, vector<int>(j));

	// cout << "ok" << endl;
	build(pref, n+1, lookmax, true);
	build(pref, n+1, lookmin, false);
	int best = -E9;
	for (int i=1; i<=n; ++i){
		// cout << "hmm " << i << endl;
		// cout << up[i] << endl;
		// cout << low[i] << endl;
		int upper = -query(i, up[i], lookmax);
		int lower = query(low[i]-1, i-1, lookmin);
		int value = upper - lower - a[i];
		best = max(best, value);
	}
	cout << best << endl;

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}