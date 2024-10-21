// https://www.luogu.com.cn/problem/P11214
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

ll m[N], a[N];

struct node {
    ll l, r;
    bool operator < (const node& x) const {
        return l != x.l? l < x.l : r < x.r;
    }
};

vector<node>vec;
map<ll,int>mp;

ll quick_pow(ll base, ll pow) {
    ll ans = 1;
    while(pow) {
        if (pow & 1) ans = ans * base % mod;
        base = base * base % mod;
        pow >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &m[i]);
    }
    for (int i = 1; i <= n ;i++) {
        scanf("%lld", &a[i]);
    }
    ll minK = 1e9;
    for (int i = 1; i <= n; i++) {
        ll maxx = min(abs(a[i] - 1), abs(m[i] - a[i]));
        if (maxx > 0) {
            vec.push_back({1, maxx});
        }
        minK = min(minK, max(abs(a[i] - 1), abs(m[i] - a[i])));
    }
    sort(vec.begin(), vec.end());
    for (auto v: vec) {
        mp[v.l]++;
        mp[v.r+1]--;
    }
    ll prefix = 0, ans = 0, last = -1;
    for (auto entry : mp) {
        if (entry.first > minK) {
            break;
        }
        // 统计entry.first之前的值对应的区间贡献
        ans = (ans + (quick_pow(2, prefix) * (entry.first - 1 - last))) % mod;
        prefix += entry.second;
        last = entry.first - 1;
    }
    if (minK > last) ans = (ans +  quick_pow(2, prefix) * (minK - last)) % mod;
    printf("%lld\n", ans);
}
