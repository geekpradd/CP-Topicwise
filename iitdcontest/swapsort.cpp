#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

signed main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n; scanf("%d", &n);
		vector<int> a(n);
		vector<ii> vals(n);
		int p = -1;
		for (int i=0; i<n; ++i){
			scanf("%d", &a[i]);
			int val = round(sqrt(a[i]));
			if (val*val == a[i] || (val-1)*(val-1) == a[i] || (val+1)*(val+1)==a[i]){
				p = i;
			}
			vals[i] = make_pair(a[i], i);
		}
		if (p == -1){
			bool sorted = 1;
			for (int i=1; i<n; ++i){
				if (a[i]<a[i-1]) sorted = 0;
			}
			if (sorted)
				printf("0\n"); 
			else
				printf("-1\n");
			continue;
		}
		sort(vals.begin(), vals.end());
		vector<int> pos(n);

		int pef;
		for (int i=0; i<n; ++i){
			vals[i].first = i;
			a[vals[i].second] = i;
			if (vals[i].second == p)
				pef = i;
			pos[i] = vals[i].second;
		}
		
		int counter = 0;
		vector<ii> moves;
		
		for (int i=0; i<n-1; ++i){
			bool did = 0;
			if (pos[pef] != i){
				counter++; moves.push_back(make_pair(pos[pef], i));
				did = 1;
			}
			
			pos[a[i]] = pos[pef];
			a[pos[pef]] = a[i];
			pos[pef] = i;
			a[i] = pef;
			// if (did ){
			// 	cout << "Move " << counter << endl;
	 	// 		for (int i=0; i<n; ++i){
			// 		cout << a[i] << " ";
			// 	}
			// 	cout << endl;
			// }
			
			did = 0;
			if (i != pos[i]){
				counter++; moves.push_back(make_pair(i, pos[i]));
				did = 1;
			}
			pos[pef] = pos[i];
			a[pos[i]] = pef;
			pos[i] = i;
			a[i] = i;

			// if (did ){
			// 	cout << "Move " << counter << endl;
	 	// 		for (int i=0; i<n; ++i){
			// 		cout << a[i] << " ";
			// 	}
			// 	cout << endl;
			// }
		}
		if (pos[pef] != pef){
			counter++; moves.push_back(make_pair(pos[pef], pef));
		}
		// cout << "Move " << counter << endl;
		// 	for (int i=0; i<n; ++i){
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		
		
		printf("%d\n",counter);
		for (ii mov: moves){
			printf("%d %d\n", mov.first, mov.second);
		}

	}
	return 0;
}