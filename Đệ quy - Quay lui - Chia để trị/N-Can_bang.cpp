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

int a[14], cnt[5], x[14], sum[5], kq = INT_MAX;

void bt(int i){
    if (i == 12) {
        foru(j, 1, 4){
            if (cnt[j] != 3) return;
        }
        int ma = 0, mi = INT_MAX; 
        foru(j, 1, 4){
            ma = max(ma, sum[j]);
            mi = min(mi, sum[j]);
        }
        /*foru(j, 0, 11){
            cout << x[j] << " ";
        } 
        cout << "\n";*/
        kq = min(kq, abs(ma - mi));
        return;
    }
    foru(j, 1, 4){
        if (cnt[j] < 3){
            cnt[j] += 1;
            x[i] = j;
            sum[j] += a[i];
            bt(i + 1);
            cnt[j] -= 1;
            sum[j] -= a[i];
        }
    }
}

void sol(){
    foru(i, 0, 11){
        cin >> a[i];
    }
    bt(0);
    cout << kq;
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
