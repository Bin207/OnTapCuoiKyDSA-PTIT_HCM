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

int n, k, x[21];
bool d[21];
vector<string> s;
set<string> da;

void xuat(){
    string tmp = "";
    foru(i, 1, k){
        tmp += s[x[i] - 1];
    }
    da.insert(tmp);
}

void bt(int i){
    if (i > k){
        xuat();
        return;
    }
    foru(j, x[i - 1] + 1, n){
        if (!d[j]){
            d[j] = 1;
            x[i] = j;
            bt(i + 1);
            d[j] = 0;
        }
    }
}

void sol(){
    cin >> n >> k;
    foru(i, 1, n){
        string tmp;
        cin >> tmp;
        s.pb(tmp);
    }
    bt(1);
    for(auto i : da) cout << i << "\n";
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
