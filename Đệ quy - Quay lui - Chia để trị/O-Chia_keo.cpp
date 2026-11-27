#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)

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

int n, c, x[26], cl = INT_MAX;
ll cnt;
vector<int> a;

void xuat(){
    int ma = 0, mi = INT_MAX;
    foru(i, 1, n){
        ma = max(ma, x[i]);
        mi = min(mi, x[i]);
    }
    if (cl > abs(ma - mi)){
        cl = abs(ma - mi);
        foru(i, 1, n){
            a[i - 1] = x[i];
        }
    }
}

void bt(int i, int sum){
    if (sum > c) return;
    if (i > n){
        if (sum == c){
            ++cnt;
            xuat();
        }
        return;
    }
    foru(j, max(x[i - 1], 1), c - sum){
        if (sum + j * (n - i + 1) > c) break;
        x[i] = j;
        sum += j;
        bt(i + 1, sum);
        sum -= j;
    }
}

void sol(){
    cin >> n >> c;
    a.resize(n);
    bt(1, 0);
    cout << cnt << "\n";
    ford(i, n - 1, 0) cout << a[i] << " ";
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
