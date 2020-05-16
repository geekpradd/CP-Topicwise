#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t; cin >> t;
    for (int i=1; i<=t; ++i){
        int n; cin >> n;
        int matrix[n][n];
        int trace = 0, row = 0, column = 0;
        
        for (int j=0; j<n; ++j){
            for (int k=0; k<n; ++k){
                cin >> matrix[j][k];
                if (j==k)
                    trace += matrix[j][j];
            }
        }
        for (int k=0; k<n; ++k){
            vector<int> counter(n+1, 0);
            for (int j=0; j<n; ++j){
                if (counter[matrix[j][k]]){
                    column++; break;
                }
                counter[matrix[j][k]]++;
            }
        }
        for (int j=0; j<n; ++j){
            vector<int> counter(n+1, 0);
            for (int k=0; k<n; ++k){
                if (counter[matrix[j][k]]){
                    row++; break;
                }
                counter[matrix[j][k]]++;
            }
        }
        cout << "Case #" << i << ": " << trace << " " << row << " " << column <<endl;
    }
    
    return 0;
}
