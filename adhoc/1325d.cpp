#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int u, v; cin >> u >> v;
	int indexer = 1LL << 62;
	bool pos = 1;
	int count[64];
	for (int i=63; i>=0; --i) count[i] = 0;
	for (int i=63; i>=1; --i){
		bool xor_val = ((u & indexer)>0);
		bool sum_val = ((v & indexer)>0);
		if (xor_val && sum_val){
			count[i]++;
		}
		else if (sum_val){
			if (i==1){
				pos = 0;
			}
			count[i-1] += 2;
		}
		else if (xor_val){
			if (count[i]==0 || i==1){
				pos = 0;
				break;
			}
			count[i] = 1;
			count[i-1] += 2;
		}
		indexer = indexer >> 1;
	}
	if (!pos){
		cout << -1 << endl;
		return 0;
	}
	int n = 0;
	for (int i=1; i<=63; ++i){
		n = max(n, count[i]);
	}
	int vals[n];
	for (int i=0; i<n; ++i) vals[i] = 0;
	indexer = 1;
	for (int i=1; i<=63; ++i){
		for (int j=0; j<count[i]; ++j)
			vals[j] += indexer;
		indexer = indexer << 1;
	}
	cout << n << endl;
	for (int i=0; i<n; ++i)
		cout << vals[i] << " ";
	cout << endl;
	return 0;
}

