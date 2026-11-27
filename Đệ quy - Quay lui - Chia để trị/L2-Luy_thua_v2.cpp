#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
//const ll MOD = 1e9 + 7;
const int maxn = 2e5 + 10;

void fio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read(){
    if (fopen(in".inp", "r")){
        freopen(in".inp", "r", stdin);
        freopen(in".out", "w", stdout);
    }
}

ll cong(ll x, ll y, ll MOD){
    x = (x + MOD) % MOD;
    y = (y + MOD) % MOD;
    ll ans = (x + y) % MOD;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll nhan(ll x, ll y, ll MOD){
    ll res = x, ans = 0;
    while (y){
        if (y & 1) ans = (ans + res) % MOD;
        res = (res + res) % MOD;
        y >>= 1;
    }
    return ans;
}

ll lt(ll a, ll b, ll MOD){
    if (!b) return 1;
    if (b == 1) return a % MOD;
    ll x = lt(a, b >> 1, MOD) % MOD;
    ll tmp = nhan(x, x, MOD);
    if (b & 1) return nhan(tmp, a, MOD);
    else return tmp;
}

ll a, b, c;

void sol(){
    cin >> a >> b >> c;   
    cout << lt(a, b, c);
}

signed main(){
    fio();
    read();
    int test;
    cin >> test;
    while (test--){
        sol();
        cout << "\n";
    }
    return 0;
}
