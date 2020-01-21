#include <cstdio>
#include <iostream>
using namespace std;

#define LL long long
int cnt(LL x)
{
    int ret=0;
    while (x)
    {
        if (x&1) ret++;
        x>>=1;
    }
    return ret;
}
int main() {
    int i, j, k, n;
    LL now, ans = 0, x, y, z;
    scanf("%lld%d", &now, &n);
    if (n >= now) printf("%lld", n - now);
    else {
        while (cnt(now) > n)
    {
        for (x = 1;; x <<= 1)
            if (now & x)
                break;
        ans += x;
        now += x;
    }
    printf("%lld", ans);
    }
    return 0;
}
