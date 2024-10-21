#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n - m < 0 || (n - m) % 2 != 0) puts("No");
        else puts("Yes");
    }
    return 0;
}
