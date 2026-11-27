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

int n;
ll k, cal[90], f[90];

void pre(){
    cal[1] = f[1] = 1;
    cal[2] = 0; f[2] = 1;
    foru(i, 3, 88){
        cal[i] = cal[i - 1] + cal[i - 2] + (i & 1);
        f[i] = f[i - 1] + f[i - 2] + 1;
    }
}

ll calcu(int x, ll y){
    if (f[x] == y) return cal[x];
    if (f[x - 1] < y) return cal[x - 1] + calcu(x - 2, y - f[x - 1] - 1) + (x & 1);
    return calcu(x - 1, y);
}

void sol(){
    cin >> n >> k;
    //cout << calcu(n, k) << " " << calcu(n, k - 1); 
    cout << ((calcu(n, k) - calcu(n, k - 1)) ? 'L' : 'V');
}

signed main(){
    fio();
    read();
    pre();
    int test;
    cin >> test;
    while (test--){
        sol();
        cout << "\n";
    }
    return 0;
}
