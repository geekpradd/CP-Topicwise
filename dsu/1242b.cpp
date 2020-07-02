#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair
#define pb push_back

int get_father(int node, vector<int>&p){
	if (p[node] == -1)
		return node;
	return get_father(p[node], p);
}
int merge(int a, int b, vector<int> &p, vector<int>&sizes, vector<int>& heads){
	int f_a = get_father(a, p);
	int f_b = get_father(b, p);
	if (sizes[f_a] < sizes[f_b]){
		p[f_a] = f_b;
		sizes[f_b] += sizes[f_a];
		sizes[f_a] = -1;
		heads.pb(f_a);
		return f_b;
	}
	else {
		p[f_b] = f_a;
		sizes[f_a] += sizes[f_b];
		sizes[f_b] = -1;
		heads.pb(f_b);
		return f_a;
	}
}


signed main(){
	int n, m; cin >> n >> m;
	vector<int> p(n+1, -1);
	vector<int> sizes(n+1);
	vector<int> adj[n+1];

	for (int i=0; i<m; ++i){
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		adj[b].pb(a);
	}
	int total = 0;
	set<int> heads;
	vector<int> remove;
	vector<ii> tracker(n+1, mp(0, 0));
	for (int i=1; i<=n; ++i){
		sizes[i] = 1; p[i] = -1; total++;
		heads.insert(i);
		for (int to: adj[i]){
			int component = get_father(to, p);
			if (tracker[component].second != i){
				tracker[component] = mp(1, i);
			}
			else {
				tracker[component].first++;
			}
		}
		int current = i;
		int to_remove = remove.size();
		for (auto itr = heads.begin(); itr != heads.end(); ++itr){
			if (*itr == current) continue;
			if (*itr == i) continue;
			if (tracker[*itr].second != i){
				current = merge(current, *itr, p, sizes, remove); total--;
			}
			else if (tracker[*itr].first != sizes[*itr]){
				current = merge(current, *itr, p, sizes, remove); total--;
			}
		}
		for (int i=to_remove; i<remove.size(); ++i){
			heads.erase(remove[i]);
		}
	}
	cout << total - 1 << endl;

	return 0;
}