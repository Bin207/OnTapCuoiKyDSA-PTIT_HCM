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

int n, a[maxn];

void sol(){
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    foru(i, 1, n){
        cin >> a[i];
        q.push(a[i]);
    }
    ll sum = 0;
    while(q.size() != 1){
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        sum += x + y; q.push(x + y);
    }
    cout << sum;
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
