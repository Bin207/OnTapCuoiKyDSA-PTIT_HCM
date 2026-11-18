#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
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

int n, s, cnt, x[21], a[21];
bool d[21];

void xuat(){
    foru(i, 0, n - 1){
        
    }
}

void bt(int i, int sum, int dem){
    if (sum > s) return;
    if (i == n){
        if (sum == s && dem){
            cnt++;
        }
        return;
    }
    bt(i + 1, sum + a[i + 1], dem + 1);
    bt(i + 1, sum, dem);
}

void sol(){
    cin >> n >> s;
    foru(i, 1, n){
        cin >> a[i];
    }
    bt(0, 0, 0);
    cout << cnt;
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
