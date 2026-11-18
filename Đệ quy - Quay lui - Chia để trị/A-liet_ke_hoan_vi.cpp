#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;

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

int m, n, x[21];
bool d[21];

void xuat(){
    foru(i, 0, n - 1){
        cout << x[i] << " ";
    }
    cout << "\n";
}

void bt(int i){
    if (i == n){
        xuat();
        return;
    }
    foru(j, 1, n){
        if (!d[j]){
            d[j] = 1;
            x[i] = j;
            bt(i + 1);
            d[j] = 0;
        }
    }
}

void sol(){
    cin >> n >> m;
    x[0] = m; d[m] = 1;
    bt(1);
}

signed main(){
    fio();
    read();
    int test = 1;
    // cin >> test;
    while (test--){
        sol();
        //cout << "\n";
    }
    return 0;
}
