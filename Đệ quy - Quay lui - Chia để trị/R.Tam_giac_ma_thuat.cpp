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

int n, k, s, x[15], sum[15], cnt;
bool dd[15];

void xuat(){
    foru(i, 1, 3){
        if (sum[i] != s) return;
    }
    ++cnt;
    foru(i, 1, n){
        cout << x[i] << " ";
    }
    cout << "\n";
}

void bt(int i){
    if (i > n){
        xuat();
        return;
    }
    int a = (i - 1) / (k - 1) + 1;   
    foru(j, 1, n)
        if (!dd[j]){
            if (sum[a] + j > s) continue;
            if (!((i - 1) % (k - 1))){
                if (sum[(a == 1 ? 3 : a - 1)] + j > s) continue;
                sum[(a == 1 ? 3 : a - 1)] += j;
            }
            dd[j] = 1;
            x[i] = j;
            sum[a] += j;
            if (!((i == k && sum[1] != s) || (i == 2 * k - 1 && sum[2] != s)))
                bt(i + 1);
            sum[a] -= j;
            if (!((i - 1) % (k - 1))){
                sum[(a == 1 ? 3 : a - 1)] -= j;
            }
            dd[j] = 0;
        }
}

void sol(){
    cin >> n >> s; k = (n + 3) / 3;
    if ((n + (n - k + 1)) * k < 2 * s){
        cout << -1;
        return;
    }
    bt(1);
    cout << (!cnt ? -1 : cnt);
    foru(i, 1, n){
        dd[i] = sum[i] = 0;
    }
    cnt = 0;
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
