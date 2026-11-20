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

int n, m, u, v;
vector<int> a[maxn];
ll d[maxn];
bool vst[maxn];

void bfs(int x){
    memset(d, 0, sizeof(d));
    memset(vst, 0, sizeof(vst));
    queue<int> q;
    q.push(x); vst[x] = 1;
    while(!q.empty()){
        int s = q.front(); q.pop();
        for (auto t : a[s]){
            if (vst[t]) continue; vst[t] = 1;
            d[t] = d[s] + 1;
            q.push(t);
        }
    }
}

void sol(){
    cin >> n >> m >> u >> v;
    foru(i, 1, m){
        int x, y;
        cin >> x >> y;
        a[x].pb(y); a[y].pb(x);
    }
    bfs(u);
    cout << (d[v] ? d[v] : -1);
    foru(i, 1, n) a[i].clear();
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
