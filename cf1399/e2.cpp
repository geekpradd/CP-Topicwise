#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E13 10000000000000
#define DUMP(a) \
    do { std::cout << "[" << #a " = " << (a) << "]" <<  std::endl; } while(false)
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define REP0(i, n) for (int i=0; i<n; ++i)
#define REP1(i, n) for (int i=1; i<=n; ++i)
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
int n, m;
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

struct edge {
	int w, t, c;
};

int dfs(int cur, vector<ii> adj[], vector<edge>&edges, int p){
	bool leaf = true;
	int tot = 0;
	for (ii &to: adj[cur]){
		if (to.first != p){
			leaf = false;
			int count = dfs(to.first,adj, edges, cur);
			edges[to.second].t = count;
			tot += count;
		}
	}
	if (!leaf)
		return tot;
	else
		return 1;

}



void solve(){
	int n, s; cin >> n >> s;
	vector<ii> adj[n+1];
	vector<edge> edges(n-1);
	int c_1 = 0, c_2 = 0;
	for (int i=0; i<n-1; ++i){
		int u, v, w, c; cin >> u >> v >> w >> c;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
		edges[i] =  {w, 0, c};
		if (c == 1) c_1++;
		if (c == 2) c_2++;
	}
	dfs(1, adj, edges, 1);

	int current = 0;
	priority_queue<ii> cost_1;
	priority_queue<ii> cost_2;
	for (int i=0; i<n-1; ++i){
		current += edges[i].w * edges[i].t;
		int diff = edges[i].w - (edges[i].w/2);
		if (edges[i].c == 1)
			cost_1.push(mp(diff*edges[i].t, i));
		else
			cost_2.push(mp(diff*edges[i].t, i));
	}
	int cost = 0;
	if (c_2 == 0){
		while (current > s){
			ii top = cost_1.top();
			cost_1.pop();
			current -= top.first;
			cost++;
			edges[top.second].w /= 2;
			int diff = edges[top.second].w - (edges[top.second].w/2);
			cost_1.push(mp(diff*edges[top.second].t, top.second));
		}
		cout << cost << endl;
		return;
	}
	if (c_1 == 0){
		while (current > s){
			ii top = cost_2.top();
			cost_2.pop();
			current -= top.first;
			cost+=2;
			edges[top.second].w /= 2;
			int diff = edges[top.second].w - (edges[top.second].w/2);
			cost_2.push(mp(diff*edges[top.second].t, top.second));
		}
		cout << cost << endl;
		return;
	}
	if (c_1 == 1){
		while (current > s){
			ii first_1 = cost_1.top();
			cost_1.pop();
			ii second_1 = cost_2.top();
			cost_2.pop();
			if (first_1.first >= second_1.first){
				current -= first_1.first;
				cost++;
				edges[first_1.second].w /= 2;
				int diff = edges[first_1.second].w - (edges[first_1.second].w/2);
				cost_1.push(mp(diff*edges[first_1.second].t, first_1.second));
				cost_2.push(second_1);
				continue;
			}

			if (first_1.first >= (current - s)) {
				cost++; break;
			}
			else {
				current -= second_1.first;
				cost+= 2;
				edges[second_1.second].w /= 2;
				int diff = edges[second_1.second].w - (edges[second_1.second].w/2);
				cost_2.push(mp(diff*edges[second_1.second].t, second_1.second));
				cost_1.push(first_1);
			}
		}

		cout << cost << endl;
		return;
	}
	while (current > s){
		ii first_1 = cost_1.top();
		cost_1.pop();
		ii second_1 = cost_2.top();
		cost_2.pop();

		cout << "first_1 benefit " << first_1.first << endl;
		cout << "second_1 benefit " << second_1.first << endl;
		if (first_1.first >= second_1.first){
			current -= first_1.first;
			cout << "used single one" << endl;
			cost++;
			edges[first_1.second].w /= 2;
			int diff = edges[first_1.second].w - (edges[first_1.second].w/2);
			cost_1.push(mp(diff*edges[first_1.second].t, first_1.second));
			cost_2.push(second_1);
			continue;
		}
		ii first_2 = cost_1.top();
		cost_1.pop();
		cout << "second first benefit " << first_2.first << endl;
		if (first_1.first >= (current - s)) {
			cout << "singular benefit of first overrides " << endl;
			cost++; break;
		}
		if (first_1.first + first_2.first <= second_1.first){
			cost += 2;
			cout << "second better " << endl;
			current -= second_1.first;
			edges[second_1.second].w /= 2;
			int diff = edges[second_1.second].w - (edges[second_1.second].w/2);
			cost_2.push(mp(diff*edges[second_1.second].t, second_1.second));
			cost_1.push(first_1);
			cost_1.push(first_2);
		}
		else {
			cout << "both first better " << endl;
			cost += 2;
			current -= first_1.first + first_2.first;
			edges[first_1.second].w /= 2; edges[first_2.second].w /= 2;
			int diff = edges[first_1.second].w - (edges[first_1.second].w/2);
			cost_1.push(mp(diff*edges[first_1.second].t, first_1.second));
			diff = edges[first_2.second].w - (edges[first_2.second].w/2);
			cost_1.push(mp(diff*edges[first_2.second].t, first_2.second));
			cost_2.push(second_1);
		}
		DUMP(current);
	}

	cout << cost << endl;

}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--){
		solve();
	}
}