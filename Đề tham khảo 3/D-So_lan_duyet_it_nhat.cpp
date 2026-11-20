#include <bits/stdc++.h>
#define inp "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e3 + 10;

void fio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read(){
    if (fopen(inp".inp", "r")){
        freopen(inp".inp", "r", stdin);
        freopen(inp".out", "w", stdout);
    }
}

int n, m, cnt, low[maxn], num[maxn], d, tg, in[maxn], scc[maxn];
vector<int> a[maxn];
bool vst[maxn], kt[maxn];
stack<int> ham;
vector<pair<int, int>> eg;

void dfs(int u){
    low[u] = num[u] = tg++;
    ham.push(u);
    vst[u] = 1;
    for (auto v : a[u]){
        if (kt[v]) continue;
        if (!vst[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else{
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]){
        int v;
        d++;
        while (v != u){
            v = ham.top();
            ham.pop();
            low[v] = num[v] = oo;
            kt[v] = 1;
            scc[v] = d;
        }
    }
}

void sol(){
    cin >> n >> m;
    foru(i, 1, m){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        eg.pb({u, v});
    }
    foru(i, 1, n) sort(all(a[i]));
    foru(i, 1, n){
        if (!vst[i]){
            dfs(i);
        }
    }
    for (auto [u, v] : eg){
        if (scc[u] != scc[v]){
            in[scc[v]]++;
        }
    }
    foru(i, 1, d){
        if (!in[i]) ++cnt;
    }
    cout << cnt;
}

signed main(){
    fio();
    read();
    int test = 1;
    //cin >> test;
    while (test--){
        sol();
        cout << "\n";
    }
    return 0;
}   
