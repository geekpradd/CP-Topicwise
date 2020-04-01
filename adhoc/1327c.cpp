#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n, m, k; cin >> n >> m >> k;
	int sx[k], sy[k];
	int fx[k], fy[k];

	for (int i=0; i<k; ++i){
		cin >> sx[i] >> sy[i];
	}
	for (int i=0; i<k; ++i)
		cin >> fx[i] >> fy[i];
	int count = 0;
	string out = "";
	for (int i=1; i<=n-1; ++i){
		count++;
		out = out + "D";
	}
	for (int i=1; i<=m-1; ++i){
		count++;
		out = out + "R";
	}
	int x = n;
	for (int y=m; y>0;--y){
		if (x==n){
			while (x!=1){
				count++;
				out = out + "U";
				x--;
			}
		}
		else if (x==1){
			while (x!=n){
				count++;
				out = out + "D";
				x++;
			}
		}
		count++;
		out = out + "L";
	}
	cout << count << endl;
	cout << out << endl;
	return 0;
}
