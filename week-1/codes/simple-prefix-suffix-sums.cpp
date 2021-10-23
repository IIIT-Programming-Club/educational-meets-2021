#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Process Q queries and then print the array
// Query: add c to [l, r]

const int N = 1e5 + 13;
ll pref[N], A[N], n;

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    int q;
    cin >> q;
    while(q--) {
        int l, r, c;
        cin >> l >> r >> c;
        pref[r] += c;
        pref[l - 1] -= c;
    }
    ll sum = 0;
    for(int i = n; i >= 1; i--) {
        sum += pref[i];
        A[i] = sum;
    }
    for(int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}


