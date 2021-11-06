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

const int N = 5e2 + 7, B = 3e4 + 2e3;
ll a[N], n;
 
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 1e15;
	auto update = [&](int x) {
		if(x <= 0) return; 
		ll now = 0, okay = 1;
		for(int i = 1; i <= n; i++) {
			ll val = a[i] % (x + 1);
			ll cnt = a[i] / (x + 1);
			now += cnt;
			if(val == 0) continue;
			if(val == x) {
				now++;
				continue;
			}
			ll req = x - val;
			if(cnt < req) okay = 0;
			else now++;
		}
		if(okay) {
			ans = min(ans, now);
		}
	};
 
	// x and x + 1
	for(int x = 1; x <= B; x++) {
		update(x);
	}
	// number of sets 
	for(int k = 1; k <= B; k++) {
		ll x = a[1] / k;
		update(x - 1);
		update(x);
		update(x + 1);
	}
	cout << ans << endl;
	return 0;
}

