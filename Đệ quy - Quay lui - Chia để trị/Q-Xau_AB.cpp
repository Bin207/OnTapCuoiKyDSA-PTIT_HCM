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

int a, b, lim;
ll k;
ll f[65][35];

void pre(){
    memset(f, -1, sizeof (f));
}

ll cal(int i, int ca){
    int cb = i - ca;
    if (ca > a || cb > b) return 0;
    if (i == lim) return 1;
    ll &res = f[i][ca];
    if (res != -1) return res;
    res = 0;
    foru(j, 0, 1){
        res += cal(i + 1, ca + (j == 0));
    }
    return res;
}

void tt(int i, int ca, ll k){
    if (i == lim) return;
    foru(j, 0, 1){
        ll cnt = cal(i + 1, ca + (j == 0));
        if (cnt < k){
            k -= cnt;
        } else{
            cout << char(j + 'a');
            tt(i + 1, ca + (j == 0), k);
            return;
        }
    }
}

void sol(){
    cin >> a >> b >> k; 
    lim = a + b;
    tt(0, 0, k);
}

signed main(){
    fio();
    read();
    pre();
    sol();
    cout << "\n";
    return 0;
}
