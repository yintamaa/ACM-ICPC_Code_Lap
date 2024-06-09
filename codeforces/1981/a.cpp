//
// Created by Administrator on 2024/6/2.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    ll l, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &l, &r);
        ll base = 2;
        ll score = 0;
        while (base <= r) {
            score++;
            base *= 2;
        }
        printf("%lld\n", score);
    }
}