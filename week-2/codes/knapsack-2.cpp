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

const int N = 1e2 + 7, V = 1e5 + 7, INF = 1e9 + 13;
int dp[N][V];
int n, w, wg[N], vg[N];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    for(int i = 0; i < N; i++) {
        for(int v1 = 0; v1 < V; v1++) {
            dp[i][v1] = INF;
        }
    }

    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> wg[i] >> vg[i];
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int v1 = 0; v1 < V; v1++) {
            // elements taken till `i - 1` with value `v1` and weight `dp[i-1][v1]`.

            // skipping element at pos `i`
            dp[i][v1] = min(dp[i][v1], dp[i - 1][v1]);
            // now considering element `i`
            if(v1 + vg[i] < V and dp[i - 1][v1] + wg[i] <= w) {
                dp[i][v1 + vg[i]] = min(dp[i][v1 + vg[i]], dp[i - 1][v1] + wg[i]);
            }
        }
    }
    ll ans = 0;
    for(int v1 = 0; v1 < V; v1++) {
        if(dp[n][v1] <= w) {
            ans = v1;
        }
    }
    cout << ans << endl;
    return 0;
}


