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

int n, x[20];
vector<string> kq;

void xuat(int k){
    string tmp = "";
    foru(i, 0, k - 1){
        tmp += char(x[i] + '0');
    }
    kq.pb(tmp);
}

void bt(int i, int k){
    if (i == k){
        xuat(k);
        return;
    }
    x[i] = 6;
    bt(i + 1, k);
    x[i] = 8;
    bt(i + 1, k);
}

void sol(){
    cin >> n;   
    foru(i, 1, n){
        bt(0, i);
    }
    sort(all(kq), [](const string& a, const string& b){
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    cout << kq.size() << "\n";
    for (auto i : kq) cout << i << " ";
    kq.clear();
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
