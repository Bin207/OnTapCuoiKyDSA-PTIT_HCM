#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e6;
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

ll cong(ll x, ll y){
    x = (x + MOD) % MOD;
    y = (y + MOD) % MOD;
    ll ans = (x + y) % MOD;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll nhan(ll x, ll y){
    ll res = x, ans = 0;
    while (y){
        if (y & 1) ans = (ans + res) % MOD;
        res = (res + res) % MOD;
        y >>= 1;
    }
    return ans;
}

ll lt(ll a, ll b){
    if (!b) return 1;
    if (b == 1) return a % MOD;
    ll x = lt(a, b >> 1) % MOD;
    ll tmp = nhan(x, x);
    if (b & 1) return nhan(tmp, a);
    else return tmp;
}

bool big(ll a, ll b){
    if (a == 1) return false;
    if (a >= MOD) return true;  
    ll p = 1;
    for (ll i = 0; i < b; ++i){
        p *= a;              
        if (p >= MOD) return true;
    }
    return false;
}

ll a, b;

void sol(){
    cin >> a >> b;   
    ll r = lt(a, b);
    if (big(a, b)) cout << setw(6) << setfill('0') << r;
    else cout << r;
}

signed main(){
    fio();
    read();
    int test = 1;
    //cin >> test;
    while (test--){
        sol();
        cout << "\n";
    }
    return 0;
}
