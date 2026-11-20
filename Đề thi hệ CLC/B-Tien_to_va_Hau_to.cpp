#include <bits/stdc++.h>
#define in "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e4 + 10;

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

bool kt(string x){
    return x.size() == 1 && (x == "+" || x == "-" || x == "*" || x == "/");
}

ll cal(ll a, ll b, char z){
    switch (z) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default:  return a / b;
    }
}

int n;
string a[maxn];
stack<ll> s;

void sol(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
    }
    if (!kt(a[1])){
        foru(i, 1, n){
            if (kt(a[i])){
                ll x, y;
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(cal(x, y, a[i][0]));
            } else{
                s.push(stoll(a[i]));
            }
        }
    } else {
        ford(i, n, 1){
            if (kt(a[i])){
                ll x, y;
                x = s.top(); s.pop();
                y = s.top(); s.pop();
                s.push(cal(x, y, a[i][0]));
            } else{
                s.push(stoll(a[i]));
            }
        }
    }
    cout << s.top();
    while(!s.empty()) s.pop();
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
