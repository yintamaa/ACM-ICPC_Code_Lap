//
// Created by Administrator on 2024/6/2.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5;
ll pow_two[N];
ll bit[N];
int main() {
    int t;
    ll n, m;
    pow_two[0] = 1;
    for (int i = 1; i <= 35; i++) {
        pow_two[i] = pow_two[i - 1] * 2;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll temp = n;
        ll tot = 0;
        for(int i = 35; i >= 0; i--) {
            bit[i] = 0;
        }
        while (temp) {
            bit[tot++] = temp % 2;
            temp /= 2;
        }
//        for (int i = tot - 1; i >= 0; i--) {
//            printf ("%d ", bit[i]);
//        }
//        puts("");
        ll last = 0;
        ll ans = n;
        for(int i = 35; i >= 0; i--) {
            if(bit[i] == 1) {
                last = i;
            } else {
                ll step1 = 1e10;
                if (last > 0) {
                    step1 = n % pow_two[last + 1] - (pow_two[last] - 1);
                }
                ll step2 = pow_two[i] - n % pow_two[i];
                if (step1 <= m || step2 <= m) {
                    ans += pow_two[i];
                }
            }
        }
        printf("%lld\n", ans);
    }
}

/*
 *
 *
 * 100100
 * 011111
 * 100011 n - n % pow_two[last + 1] +  (pow_two[last] - 1)
 */