#include <bits/stdc++.h>
using namespace std;

int main(){
	int up = 31700;
	vector<int> primes;
	vector<int> visited(up, 0);
	
	for (int i=2; i<up; ++i){
		if (!visited[i])
			primes.push_back(i);
		for (int j=2*i; j<up; j+=i)
			visited[j] = 1;
	}

	int t; cin >> t;
	while (t--){
		int x, k; cin >> x >> k;
		int my_k = 0;
		while (my_k < k){
			bool this_iter = 0;
			for (int i=0; i<primes.size(); ++i){
				if (x % primes[i] == 0){
					my_k++; x = x/primes[i];
					this_iter = 1;
					break;
				}
			}
			if (x==1)
				break;
			if (!this_iter){
				// current no is a prime
				my_k++;
				break;
			}
		}
		cout << (my_k == k) << endl;
	}
}
