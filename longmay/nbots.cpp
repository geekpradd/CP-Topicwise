#include <bits/stdc++.h>
using namespace std;

struct shot {
	int val, id, type;
};

vector<int> killed_rows;
vector<int> killed_cols;
int dead_row = 0;
int dead_col = 0;

void update(vector< vector<int> > &grid, shot cols[], shot row[], int n, int f){
	for (int i=0; i<n; ++i){
		int val = 0;
		int hits = 1;
		for (int j=0; j<n; ++j){
			if (val + grid[i][j] > f){
				hits++; val = 0;
			}
			val += grid[i][j];
		}
		val = 0; 
		int sec_hits = 1;

		for (int j=n-1; j>=0; --j){
			if (val + grid[i][j] > f){
				sec_hits++; val = 0;
			}
			val += grid[i][j];
		}
		shot cur;
		if (hits < sec_hits){
			cur = {hits, i, 0};
		}
		else {
			cur = {sec_hits, i, 1};
		}
		if (killed_rows[i]){
			cur.val = 10000000;
		}
		row[i] = cur;
	}

	for (int j=0; j<n; ++j){
		int val = 0;
		int hits = 1;
		for (int i=0; i<n; ++i){
			if (val + grid[i][j] > f){
				hits++; val = 0;
			}
			val += grid[i][j];
		}
		val = 0; 
		int sec_hits = 1;

		for (int i=n-1; i>=0; --i){
			if (val + grid[i][j] > f){
				sec_hits++; val = 0;
			}
			val += grid[i][j];
		}
		shot cur;
		if (hits < sec_hits){
			cur = {hits, j, 2};
		}
		else {
			cur = {sec_hits, j, 3};
		}
		if (killed_cols[j]){
			cur.val = 10000000;
		}

		cols[j] = cur;

	}
}
signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, f; cin >> n >> f;
	vector< vector<int> > grid(n, vector<int>(n));
	shot row[n];
	shot cols[n];
	killed_rows.assign(n, 0);
	killed_cols.assign(n, 0);

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			cin >> grid[i][j];
		}
	}

	update(grid, cols, row, n, f);
	int erased = 0;
	vector< pair<char, int> > fin;
	while (erased < n*n){
		// cout << "erased " << erased << endl;
		shot mi = row[0];
		// cout << "row 0  got " << row[0].val << endl;
		for (int i=1; i<n; ++i){
			// cout << "at row " << i << " got " << row[i].val << endl;
			if (row[i].val < mi.val){
				mi = row[i];
			}
		}
		for (int j=0; j<n; ++j){
			// cout << "at column " << j << " got " << cols[j].val << endl;

			if (cols[j].val < mi.val){
				mi = cols[j];
			}
		}
		
		while (mi.val > 0){
			pair<char, int> outs;
			if (mi.type == 0){
				outs.first = 'L';
			}
			else if (mi.type == 1){
				outs.first = 'R';
			}
			else if (mi.type == 2){
				outs.first =  'U';
			}
			else {
				outs.first = 'D';
			}
			outs.second = mi.id+1;
			mi.val--;
			fin.push_back(outs);
		}
		
		for (int i=0; i<n; ++i){
			if (mi.type < 2){
				grid[mi.id][i] = 0;
				
			}
			else {
				grid[i][mi.id] = 0;
				
			}
		}
		if (mi.type < 2){
			killed_rows[mi.id] = 1;
			dead_row++;
			erased += n - dead_col;
		}
		else {
			killed_cols[mi.id] = 1;
			dead_col++;
			erased += n - dead_row;
		}

		update(grid, cols, row, n, f);

	}

	cout << fin.size() << endl;
	for (pair<char, int> x: fin){
		cout << x.first << " "  << x.second << endl;
	}
	return 0;
}