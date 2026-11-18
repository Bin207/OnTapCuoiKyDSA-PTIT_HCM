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

int n, x[21];
vector<string> a;

void xuat(){
    int cnt = 0;
    foru(i, 0, 2 * n - 1){
        cnt += (x[i] ? -1 : 1);
        if (cnt < 0) return;
    }
    if (cnt) return;
    string tmp = "";
    foru(i, 0, 2 * n - 1){
        tmp += (x[i] ? ')' : '(');
    }
    a.pb(tmp);
}

void bt(int i){
    if (i == 2 * n){
        xuat();
        return;
    }
    foru(j, 0, 1){
        x[i] = j;
        bt(i + 1);
    }
}

void sol(){
    cin >> n;
    bt(0);
    cout << a.size() << "\n";
    for (auto i : a) cout << i << "\n";
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
