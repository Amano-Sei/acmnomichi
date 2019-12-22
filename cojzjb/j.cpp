/*************************************************************************
    > File Name: j.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 20时06分45秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//这道题有点吓人(虽然明白爆搜绝对没问题
//但是不知道自己为什么dp错误真的是后患无穷...
//跑了几万的样例里面只有不几个是错误的...
//原因是这样的，dp取得最小值的时候ca不一定取得最小值
//每天到达这一状态的方式不唯一，同时ca和dp的值不一定相同，而求dp要依赖ca
//所以这个是必须要爆搜的（

long long ca[16][16], dp[16][16];
long long k[16], c[16], a[16];
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int main(){
    int n, q;
    long long ta;
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld%lld%lld", &k[i], &c[i], &a[i], &ta);
            a[i] += ta;
            a[i] = max(a[i], a[i-1]);
            printf("%14lld", a[i]);
        }
        putchar('\n');
        for(int i = 0; i <= q; i++){
            dp[i][0] = 0;
            for(int j = 1; j <= n; j++)
                dp[i][j] = inf;
        }
        dp[1][1] = k[1];
        memset(ca, 0, sizeof(ca));
        ca[1][1] = a[1];
        for(int i = 2; i <= q; i++)
            for(int j = max(1, n-q+i); j <= i && j <= n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+max(k[j]-ca[i-1][j-1], c[j]));
                ca[i][j] = max(ca[i-1][j]+a[j], ca[i-1][j-1]+a[j]);
            }
        for(int i = 1; i <= q; i++){
            for(int j = 1; j <= n; j++){
                    printf("%14lld", ca[i][j]);
            }
                putchar('\n');
                
        }
        for(int i = 1; i <= q; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] == inf)
                    printf("%14s", "inf");
                else
                    printf("%14lld", dp[i][j]);
            }
                putchar('\n');
        }
        printf("%lld\n", dp[q][n]);
    }
    return 0;
}

