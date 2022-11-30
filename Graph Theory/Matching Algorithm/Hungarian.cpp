#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int N = 6e4 + 5;
int a[N],belong[N];
bool is_prime[N], vis[N];
int prime[N], id;
vector<int>e[N];

bool hungarian(int i) {
    for(auto v: e[i]) {
        if(!vis[v]) {
            vis[v] = true; // 标记为true，如果后续失败，代表v不可回退，避免重新遍历浪费时间，而且可能会成环
            if(!belong[v]||hungarian(belong[v])) {
                belong[v] = i;
                return true;
            }
        }
    }
    return false;
}


void GetPrime(int n) {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime[id++] = i;
        for(int j = 0; j < id && prime[j] * i <= n; j++) {
            is_prime[prime[j] * i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    GetPrime(6e4);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for(int j = 1; j < i; j++) {
            if(is_prime[a[i] + a[j]]) { // 只记录单向边，左到右
                if(a[i]%2) e[i].push_back(j);
                else e[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis,false,sizeof vis);
        if(e[i].size()!=0 && hungarian(i)) ans++;
    }
    printf("%d\n", ans);
}
// 64 位输出请用 printf("%lld")