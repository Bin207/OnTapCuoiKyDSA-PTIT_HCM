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

int n, lim;
string a, kq;
ll f[15][2][15 * 9];

void pre(){
    a = "1000000000000";  
    lim = 13;
    memset(f, -1, sizeof (f));
}

ll cal(int i, bool is, int sum){
    if (i == lim) return sum == 10;
    ll &res = f[i][is][sum];
    if (res != -1) return res;
    res = 0;
    int limit = 9;
    if (!is){
        limit = a[i] - '0';
    }
    foru(j, 0, limit){
        res += cal(i + 1, is | (j < limit), sum + j);
    }
    return res;
}

void tt(int i, bool is, int sum, int k){
    if (i == lim) return;
    int limit = 9;
    if (!is){
        limit = a[i] - '0';
    }
    foru(j, 0, limit){
        ll cnt = cal(i + 1, is | (j < limit), sum + j);
        if (cnt < k){
            k -= cnt;
        } else{
            kq += char(j + '0');
            tt(i + 1, is | (j < limit), sum + j, k);
            return;
        }
    }
}

void sol(){
    cin >> n; kq = "";
    tt(0, 0, 0, n);
    while (kq.size() > 1 && kq[0] == '0') kq.erase(0, 1);
    cout << kq;
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
