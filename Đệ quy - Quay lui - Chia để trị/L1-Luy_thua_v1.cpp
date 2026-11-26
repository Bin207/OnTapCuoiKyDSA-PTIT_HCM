#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
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

ll lt(int a, int b){
    if (!b) return 1;
    if (b == 1) return a;
    ll x = lt(a, b >> 1) % MOD;
    if (b & 1) return (x % MOD * x % MOD * a % MOD) % MOD;
    else return (x % MOD * x % MOD) % MOD;
}

int a, b;

void sol(){
    cin >> a >> b;   
    cout << lt(a, b);
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
