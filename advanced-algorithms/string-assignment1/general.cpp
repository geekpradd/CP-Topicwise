#include <bits/stdc++.h>
using namespace std;

struct node {
	int id;
	node* children[26];
	char ch;
	bool leaf;
};

node* new_node(){
	node* current = new node();
	for (int i=0; i<26; ++i){
		current->children[i] = NULL;
	}
	current->leaf = false;
	return current;
}

void print_trie(node* trie){
	int id = trie->id;
	for (int i=0; i<26; ++i){
		if (trie->children[i] != NULL){
			cout << id << "->" << trie->children[i]->id << ":" << trie->children[i]->ch << endl;
			print_trie(trie->children[i]);
		}
	}
}

signed main(){
	string main; cin >> main;
	int n; cin >> n;
	string patterns[n];
	for (int i=0; i<n; ++i) cin >> patterns[i];

	node* trie = new_node();
	trie->id = 0;
	int counter = 1;
	for (int i=0; i<n; ++i){
		node* cur = trie;
		for (int j=0; j<patterns[i].size(); ++j){
			int id = patterns[i][j] - 'A';
			if (cur->children[id] == NULL){
				node* new_n = new_node();
				new_n->id = counter; counter++;
				new_n->ch = patterns[i][j];
				cur->children[id] = new_n;
				cur = new_n;

			}
			else {
				cur = cur->children[id];
			}
			if (j == patterns[i].size() - 1){
				cur->leaf = 1;
				// cout << "cha " << cur->ch << endl;
				// cout << "i " << i << " j " << j << endl;
			}
		}
	}

	for (int i=0; i<main.size(); ++i){
		// cout << "At " <<  i << endl;
		node* start = trie;
		for (int j=i; j<main.size(); ++j){
			int id = main[j] - 'A';
			// cout << " now " << j << endl;
			if (start->children[id] != NULL){
				start = start->children[id];
				// cout << "visiting " << start->ch << endl;
				// cout << start->leaf << endl;
				if (start->leaf){
					cout << i << " ";
					break;
				}
				
			}
			else {
				break;
			}
		}
	}
	cout << endl;

}