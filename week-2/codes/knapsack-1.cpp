#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
#define ll long long
const ll mod = 1e9 + 7;
#define all(c) (c).begin(), (c).end()
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 1e2 + 7, W = 1e5 + 7;
ll dp[N][W];
int n, w, wg[N], vg[N];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> wg[i] >> vg[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int w1 = 0; w1 <= w; w1++) {
            // elements taken till `i - 1` with weight `w1` and value `dp[i-1][w1]`.

            // skipping element at pos `i`
            dp[i][w1] = max(dp[i][w1], dp[i - 1][w1]);
            // now considering element `i`
            if(w1 + wg[i] <= w) {
                dp[i][w1 + wg[i]] = max(dp[i][w1 + wg[i]], dp[i - 1][w1] + vg[i]);
            }
        }
    }
    ll ans = 0;
    for(int w1 = 0; w1 <= w; w1++) {
        ans = max(ans, dp[n][w1]);
    }
    cout << ans << endl;
    return 0;
}


