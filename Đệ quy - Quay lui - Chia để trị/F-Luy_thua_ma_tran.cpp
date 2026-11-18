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

int n, k;

ll cong(ll x, ll y){
    x = (x + MOD) % MOD;
    y = (y + MOD) % MOD;
    ll ans = (x + y) % MOD;
    ans = (ans + MOD) % MOD;
    return ans;
}

ll nhan(ll x, ll y){
    ll res = x, ans = 0;
    while (y){
        if (y & 1) ans = (ans + res) % MOD;
        res = (res + res) % MOD;
        y >>= 1;
    }
    return ans;
}

struct matric{
    ll val[21][21];

    matric() = default;

    auto & operator [] (int i) {return val[i];}

	const auto & operator [] (int i) const {return val[i];}

    void operator = (vector<vector<ll>> d)
	{
		foru(i, 0, d.size() - 1)
			foru(j, 0, d[i].size() - 1)
				val[i][j] = d[i][j];
	}

    matric indentify (ll x){
        matric a;
        while (x--) a[x][x] = 1;
        return a;
    }

    friend ostream& operator<< (ostream &stream, matric x) {
        foru(i, 0, n - 1) 
            foru(j, 0, n - 1)
                stream << x[i][j] << " \n"[j == (n - 1)];
        return stream;
    }

    matric operator + (const matric &b){
        matric a = *this;
        matric c;
        foru(i, 0, n - 1){
            foru(j, 0, n - 1){
                c[i][j] = ((a[i][j] % MOD) + (b[i][j] % MOD)) % MOD;
            }
        }
        return c;
    }

    matric operator * (const matric &b){
        matric a = *this;
        matric c;
        foru(i, 0, n - 1){
            foru(j, 0, n - 1){
                c[i][j] = 0;
            }
        }
        
        foru(i, 0, n - 1){
            foru(j, 0, n - 1){
                foru(k, 0 , n - 1){
                    //c[i][j] = cong(c[i][j], nhan(a[i][k], b[k][j]));
                    //c[i][j] %= MOD;
                    c[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }

    matric po(int nthp){
        matric e = *this;
        if (nthp == 0) return indentify(n);
        if (nthp == 1) return e;
        matric x = po(nthp >> 1);
        x = x * x;
        if (nthp & 1) return x = x * e;
        return x;
    }

    matric po2(int nthp){
        matric e = *this;
        matric res = indentify(n);
        for (; nthp > 0; nthp >>= 1, e = e * e){
            if (nthp & 1) res = res * e;
        }
        return res;
    }
};

matric a;
ll sum;

void sol(){
    cin >> n >> k;
    foru(i, 0, n - 1){
        foru(j, 0, n - 1){
            cin >> a[i][j];
        }
    }
    a = a.po(k); sum = 0;
    foru(i, 0, n - 1){
        sum = (sum + a[0][i]) % MOD;
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
