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

int n, x[21];
bool d[21];
string t;
vector<string> s;

void xuat(){
    foru(i, 0, n - 1){
        cout << s[x[i]] << " ";
    }
    cout << "\n";
}

void bt(int i){
    if (i == n - 1){
        xuat();
        return;
    }
    foru(j, 0, n - 1){
        if (!d[j]){
            d[j] = 1;
            x[i] = j;
            bt(i + 1);
            d[j] = 0;
        }
    }
}

void sol(){
    cin >> n;
    foru(i, 1, n){
        string tmp;
        cin >> tmp;
        s.pb(tmp);
    }
    cin >> t;
    sort(all(s));
    int tmp;
    foru(i, 0, n - 1){
        if (t == s[i]){
            tmp = i;
            break;
        }   
    }
    x[n - 1] = tmp; d[tmp] = 1; 
    bt(0);
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
