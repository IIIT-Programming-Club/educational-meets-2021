#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]

// Uncomment when using kactl templates and change typedef of pair
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define sz(x) (int)(x).size()
// typedef pair<int, int> pii;

typedef vector< int > vi;
typedef vector<long long> lvi;
typedef vector< vector<int> > vvi;
typedef vector< vector<long long> > lvvi;
typedef pair< int,int > ii;
typedef pair< long long,long long > lii;
typedef vector<pair<int,int>> vii;
typedef vector<pair<long long,long long>> lvii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<vector<pair<long long,long long>>> lvvii;
typedef vector<bool> vb;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
// usage: x = rng() % k; shuffle(all(v), rng);

#define all(c) (c).begin(),(c).end()
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define pb push_back
#define ss second
#ifdef ONLINE_JUDGE
    #define error(args...) 0
#else
    #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#endif
void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr <<"[ "<< *it << " = " << a << " ]";
    err(++it, args...);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
const long long mod = 1e9 + 7;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

long long mos() { return 0LL; }
template<typename T, typename... Args>
T mos(T a, Args... args) { return ((a + mos(args...))%mod + mod)%mod; }

long long mop() { return 1LL; }
template<typename T, typename... Args>
T mop(T a, Args... args) { return (a*mop(args...))%mod; }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

const int N = 3e5 + 13;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    ll n, k, sum = 0, max1 = 1;
    cin >> n >> k;
    lvi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        max1 = max(max1, a[i]);
    }
    if(k >= (n*max1 - sum)) {
        for(int i = 0; i < n; i++) {
            ll x = max1 - a[i];
            k -= x;
            a[i] = max1;
        }
        cout << max1 + k / n << endl;
        return 0;
    }
    lvi suffg(max1 + 2);
    auto get = [&](int x, int v) {
        if(v == 0) return (int)max1 + 1;
        return (x + v - 1) / v;
    };
    for(int i = 0; i < n; i++) {
        int x = a[i];
        int xr = sqrt(x);
        for(int g = 2; g > 0; g++) {
            int v = ((x + g - 1)/g);
            if(v <= xr) break;
            suffg[g] += v;
            suffg[g + 1] -= v;
        }
        // (x + g - 1) / g => val, first g
        for(int v = 1; v <= xr; v++) {
            int first_g = get(x, v);
            int last_g = get(x, v - 1) - 1;
            suffg[first_g] += v;
            suffg[last_g + 1] -= v;
        }
    }
    ll sum1 = 0;
    for(int i = 0; i <= max1; i++) {
        suffg[i] = suffg[i] + sum1;
        sum1 = suffg[i];
    }

    ll ans = 1;
    for(int g = 2; g <= max1; g++) {
        ll req = g * (suffg[g]) - sum;
        if(req <= k) ans = g;
    }
    cout << ans << endl;
    return 0;
}	
