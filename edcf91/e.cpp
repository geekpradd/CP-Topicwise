#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define E9 1000000000
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

int parent(int p[], int cur){
	while (p[cur] != cur){
		cur = p[cur];
	}
	return cur;
}
int size(int s[], int p[], int cur){
	int p_a = parent(p, cur);
	return s[p_a];
}
void merge(int a, int b, int p[], int s[], set<int> members[], int &ans){
	int p_a = parent(p, a), p_b = parent(p, b);
	for (auto elem: members[p_a]){
		if (elem <= m) continue;
		if (elem != m+1){
			if (parent(p, elem-1) == p_b)
				ans -= 1;
		}
		if (elem != n+m){
			if (parent(p, elem+1) == p_b)
				ans -= 1;
		}
		members[p_b].insert(elem);
	}
	p[p_a] = p_b;
	s[p_b] += s[p_a];
}


void solve(){
 	cin >> n >> m;
	int p[n+m+1]; REP1(i, n+m){ p[i] = i;}
	int s[n+m+1]; REP1(i, n+m){ s[i] = 1;}
	set<int> members[m+n+1]; REP1(i, m+n){ members[i].insert(i);}

	int ans = n-1;
	REP1(i, n){
		int o; cin >> o;
		merge(i+m, o, p, s, members, ans);
	}
	d1(ans);
	int identity[m+1]; REP1(i, m){identity[i] = i;}
	REP0(i, m-1){
		int a, b; cin >> a >> b;
		a = identity[a]; b = identity[b];

		int s_a = size(s, p, a); int s_b = size(s, p, b);

		if (s_b <= s_a){
			merge(b, a, p, s, members, ans);
		}
		else {
			merge(a, b, p, s, members, ans);
			identity[a] = b;
		}
		d1(ans);
	}
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}