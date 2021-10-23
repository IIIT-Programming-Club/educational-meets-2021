#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 13;
ll n, A[N], x[2][N], pw[2][N]; // 2 degree

// Process Q queries and then print the array
// Query(l, r): add (j - l + 1) to j in [l, r]
// AP type update on range.

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        // update: 1*x1 + (1 - l)*x0
        x[0][l] += (1 - l);
        x[0][r + 1] -= (1 - l);

        x[1][l] += 1;
        x[1][r + 1] -= 1;
    }
    for(int d = 0; d < 2; d++) {
        for(int i = 1; i <= n; i++) {
            if(d == 0) pw[d][i] = 1;
            else pw[d][i] = (pw[d - 1][i] * i);
        }
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += x[d][i];
            A[i] += sum * pw[d][i];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
