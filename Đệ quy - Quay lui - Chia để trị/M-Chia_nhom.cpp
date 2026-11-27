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

int n, k, x[21], sum[21], a[21], tong;

void xuat(){
    int tam = -1;
    foru(i, 1, k){
        if (!sum[i]) return;
        if (tam == -1){
            tam = sum[i]; continue;
        }
        if (tam != sum[i]) return;
    }
    
    foru(i, 0, n - 1){
        cout << x[i] << " ";
    }
    exit(0);
}

void bt(int i){
    if (i == n){
        xuat();
        return;
    }
    foru(j, 1, k){
        x[i] = j; 
        if (sum[x[i]] + a[i + 1] > tong) continue;
        sum[x[i]] += a[i + 1];
        bt(i + 1);
        sum[x[i]] -= a[i + 1];
    }
}

void sol(){
    cin >> n >> k;
    foru(i, 1, n){
        cin >> a[i]; tong += a[i];
    }
    if (tong % k){
        cout << -1;
        return;
    }
    tong /= k;
    bt(0);
    cout << -1;
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
