#include <bits/stdc++.h>
using namespace std;

struct node {
	int state, lazy;
	int l[2], r[2], m[2];
};

void build_tree(string &s, int l, int r, int i, node segment_tree[]){
	if (l == r){
		if (s[l] == '>'){
			node cur = {0, 0, {-1, 1}, {1, -1}, {1, 1}};
			segment_tree[i] = cur;
		}
		else {
			node cur = {0, 0, {1, -1}, {-1, 1}, {1, 1}};
			segment_tree[i] = cur;
		}
	}
	else {
		int mid = (l+r)/2;
		build_tree(s, l, mid, 2*i+1, segment_tree);
		build_tree(s, mid+1, r, 2*i+2, segment_tree);
		node left = segment_tree[2*i+1], right = segment_tree[2*i+2];
	}
}

signed main(){
	int n, q; cin >> n >> q;
	string s; cin >> s;

	node segment_tree[4*n];
	build_tree(s, 1, n, 0, segment_tree);

	return 0;
}