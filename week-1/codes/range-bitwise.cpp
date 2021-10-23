#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 13;
int pref[N][31], A[N], n;

// Given an array A, answer Q queries
// Query: Range (or/xor/and) of the subarray [l, r].

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int b = 0; b < 31; b++) {
            pref[i][b] = pref[i - 1][b];
            if((A[i] >> b)&1) {
                pref[i][b]++;
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        int ans = 0;
        if(s == "xor") {
            // bit is set when count is odd.
            for(int b = 0; b < 31; b++) {
                int cnt = pref[r][b] - pref[l - 1][b];
                if(cnt&1) ans += (1 << b);
            }
        } else if (s == "or") {
            // bit is set when count > 0.
            for(int b = 0; b < 31; b++) {
                int cnt = pref[r][b] - pref[l - 1][b];
                if(cnt > 0) ans += (1 << b);
            }
        } else if (s == "and") {
            // bit is set when count is number of elements in range.
            for(int b = 0; b < 31; b++) {
                int cnt = pref[r][b] - pref[l - 1][b];
                if(cnt == (r - l + 1)) ans += (1 << b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
