#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define int long long

const int N = 2e5 + 5;

vector<int> g[N];

vector<int> c(N), d(N);

int ans = 1;

/* This is for nCr formula moduleInversion is used as a/b taken from public source*/
int binExp(int a, int b) {

    int res = 1;

    while(b) {

        if(b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;

        b >>= 1;
    }

    return res;
}

int nCr(int n, int r) {

    if(r > n || r < 0)
        return 0;

    r = min(r, n - r);

    int num = 1;
    int den = 1;

    for(int i = 0; i < r; i++) {

        num = (num * ((n - i) % MOD)) % MOD;

        den = (den * (i + 1)) % MOD;
    }

    return (num * binExp(den, MOD - 2)) % MOD;
}
/*nCr ended */

int dfs(int u){

    int candies = c[u];

    int used = d[u];

    for(auto v : g[u]) {

        int leftOver = dfs(v);

        candies += leftOver;
    }

    ans = (ans * nCr(candies, d[u])) % MOD;

    int remaining = candies - used;

    return remaining;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {

        int p;
        cin >> p;

        g[p].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    dfs(1);

    cout << ans << '\n';

    return 0;
}
