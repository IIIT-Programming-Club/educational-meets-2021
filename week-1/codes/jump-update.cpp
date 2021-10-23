#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 13;
ll suff[N], A[N], n, k;

// Process Q queries and then print the array
// K is given
// Query(i, c): add c to {i, i + k, i + 2*k ....}
// all queries have common k.

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n >> k;
    int q;
    cin >> q;
    while(q--) {
        int i, c;
        cin >> i >> c;
        suff[i] += c;
    }
    for(int i = 1; i <= n; i++) {
        A[i] = suff[i];
        if(i + k <= n) {
            suff[i + k] += suff[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}


