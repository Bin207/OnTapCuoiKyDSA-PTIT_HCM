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

int n;
string a;

void sol(){
    cin >> n; a = "";
    if (n == 0) a = "0";
    while (n != 0){
        a = char(n % 2 + '0') + a;
        n /= 2;
    }
    cout << a;
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
