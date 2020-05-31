#include <bits/stdc++.h>
using namespace std;

void build(int a[], int n, vector< vector<int> > &table, bool mx){
	for (int i=0; i<n; ++i){
		table[i][0] = a[i];
	}
	
	
	for (int size = 1; (1 << size) <=n; ++size){
		for (int i=0; i<n; ++i){
			if (i + (1 << size) > n)
				break;
			int mid = i + (1 << (size - 1));
			table[i][size] = (mx ? max(table[i][size-1], table[mid][size-1]) : min(table[i][size-1], table[mid][size - 1]));
			// cout << "Tab " << i << " " << (1 << size) << " " << table[i][size] << endl;
		}
	}
}
int query(vector< vector<int> > &table, int l, int r, bool mx){
	int gap = r - l + 1;
	int base = log2(gap);
	int val = 1 << base;
	int mid = r - val + 1;
	if (mx){
		return max(table[l][base], table[mid][base]);
	}
	else {
		return min(table[l][base], table[mid][base]);
	}

}

signed main(){
	int n; cin >> n; 
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	int size = log2(n) + 2;
	vector<  vector<int> > max_table(n, vector<int>(size));
	vector< vector<int> > min_table(n, vector<int>(size));
	build(a, n, max_table, 1); build(a, n, min_table, 0);

	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		int minima = query(min_table, l, r, 0);
		int maxima = query(max_table, l, r, 1);
		double value = (minima + maxima)/2.0;
		if (l != 0){
			int mx = query(max_table, 0, l-1, 1);
			int other = mx + minima;
			if (other > value){
				value = other;
			}
		}
		if (r != n-1){
			int mx = query(max_table, r+1, n-1, 1);
			int other = mx + minima;
			if (other > value){
				value = other;
			}
		}
		cout << fixed;
		cout << setprecision(1);
		cout << value << endl;
	}

}