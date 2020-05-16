#include <bits/stdc++.h>
#define int long long
using namespace std;

int counter = 0;
struct node {
	int val;
	int current;
	int id;
	node* go[26];
	node* children[26];
	node* suflink;
	node* parent;
	node(){
		val = 0;
		current = -1;
		suflink = NULL;
		parent = NULL;
		for (int i=0; i<26; ++i){
			children[i] = NULL;
			go[i] = NULL;
		}
	}
};

node* go(node* cur, int val){
	if (cur->go[val]!=NULL)
		return cur->go[val];

	if(cur->suflink == cur){
		char i = (val + 'a');
	}

	if (cur->children[val]!=NULL)
		cur->go[val] = cur->children[val];
	else if (cur->suflink != cur){
		cur->go[val]= go(cur->suflink, val);
	}
	else {
		cur->go[val] = cur;
	}
	return cur->go[val];

}

void solve(){
	string a, b;
	cin >> a; cin >> b;
	int n; cin >> n;
	string test[n];
	node* trie = new node();
	trie->id = 0; counter++;
	trie->parent = trie;  trie->suflink = trie;
	node* rev_trie = new node();
	for (int i=0; i<n; ++i){
		cin >> test[i];
		int val; cin >> val;
		node* cur = trie;
		
		for (int j=0; j<test[i].size(); ++j){
			int k = (test[i][j]-'a');
			if (cur->children[k] == NULL){
				cur->children[k] = new node();
				cur->children[k]->parent = cur;
				cur->children[k]->current = k;
				cur->children[k]->id = counter;counter++;
			}
			cur = cur->children[k];
		}
		cur->val += val;

		cur = rev_trie;
		for (int j=test[i].size()-1; j>=0; --j){
			int k = (test[i][j]-'a');
			if (cur->children[k] == NULL){
				cur->children[k] = new node();
			}
			cur = cur->children[k];
		}
		cur->val += val;
	}
	int left[a.size()+1];
	left[0] = 0;
	for (int i=1; i<=a.size(); ++i){
		left[i] = left[i-1];
		node* cur = rev_trie;
		int j= i-1;

		while (j >= 0){
			int k = (a[j] - 'a');
			cur = cur->children[k];
			if (cur != NULL)
				left[i] += cur->val;
			else
				break;
			j--;
		}
	}
	
	int right[b.size()+1];
	right[b.size()] = 0;
	for (int i=b.size()-1; i>=0; --i){
		right[i] = right[i+1];
		node* cur = trie;
		int j = i;
		
		while (j<b.size()){
			int k = (b[j]-'a');
			cur = cur->children[k];
			if (cur != NULL)
				right[i] += cur->val;
			else
				break;
			j++;
		}
	}	
	
	queue< pair<node*, int> > bfs;
	bfs.push(make_pair(trie, 0));

	while (!bfs.empty()){
		pair<node*, int> current = bfs.front();
		node* cur = current.first;
		int depth = current.second;
		bfs.pop();
		for (int i=0; i<26; ++i){
			if (cur->children[i] != NULL)
				bfs.push(make_pair(cur->children[i], depth+1));
		}

		if (depth == 0){

		}
		else if (depth==1){
			cur->suflink = trie;
			cur->parent =  trie;
		}
		else {
			node* recur = cur->parent->suflink;
			int k = cur->current;
			cur->suflink = go(recur, k);
			if (cur->suflink == NULL)
				cur->suflink = trie;
			cur->val += cur->suflink->val;
		}

	}
		int best = 0;
	for (int i=0; i<=a.size(); ++i){
		for (int j=0; j<=b.size(); ++j){
			// left = [0, i) exclusive
			// right = [j, b.size()) exclusive
			int siz = b.size();
			int nu = 0;
			int le = max(i-25, nu); // exclusive
			int ri = min(j+25, siz);
			int ans = left[i] + right[j];

			node* cur = trie;
			for (int k=le; k<i; ++k){
				int value = a[k] - 'a';
				cur = go(cur, value);
			}
			node* curs = trie;
			for (int k=j; k<ri; ++k){
				int value = b[k] - 'a';
				cur = go(cur, value);
				curs = go(curs, value);
				ans += cur->val;
				ans -= curs->val;
			}
			best = max(best, ans);

		}
	}

	cout << best << endl;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}