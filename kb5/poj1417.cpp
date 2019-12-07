/*************************************************************************
    > File Name: poj1417.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月07日 星期四 17时31分24秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 605;

//天天爆搜爆搜，不仅思路窄了，代码也越来越*了（（（
//试了下<=1结果wa了，这说明数据里面有毒瘤数据（明明说好了没有矛盾的
//不过看看别人的*代码，好像和我的差不多hhh
//这道题多了两个教训，啊不（三个
//首先是要把内容分成多个部分，然后着眼于每个部分的细节，而不要被部分之间的联系懵逼了双眼
//其次是不要老是爆搜，还是那句话dp的关注点是状态的变化，要对状态变化的嗅觉敏锐一点
//最后是写代码麻烦严谨和仔细看，别动不动就把该减的东西变成不该减的东西（（（

int pre[maxn], w[maxn];
int cnt[maxn];
int stk[maxn][2], tot;
int s2i[maxn];
int book[maxn];
int p1, p2;
int dp[maxn][maxn];
int ans[maxn];

inline void init(){
    memset(pre, -1, sizeof(pre));
    memset(w, 0, sizeof(w));
    memset(cnt, 0, sizeof(cnt));
    memset(book, 0, sizeof(book));
    memset(stk, 0, sizeof(stk));
    memset(dp, 0, sizeof(dp));
    tot = 0;
}

int getpre(int x){
    if(pre[x] == -1)
        return x;
    int tx = getpre(pre[x]);
    w[x] ^= w[pre[x]];
    return pre[x]=tx;
}

int main(){
    int n;
    char buf[5];
    int cx, cy;
    while(scanf("%d%d%d", &n, &p1, &p2) != EOF && (n+p1+p2)){
        init();
        while(n--){
            scanf("%d%d%s", &cx, &cy, buf);
            int tx = getpre(cx);
            int ty = getpre(cy);
            if(tx == ty)
                continue;
            int cw = (buf[0]!='y');
            if(cnt[tx] < cnt[ty]){
                pre[tx] = ty;
                w[tx] = w[cx]^w[cy]^cw;
            }else{
                if(cnt[tx] == cnt[ty])
                    cnt[tx]++;
                pre[ty] = tx;
                w[ty] = w[cy]^w[cx]^cw;
            }
        }
        for(int i = 1; i <= p1+p2; i++){
            int ti = getpre(i);
            if(!book[ti]){
                book[ti] = ++tot;
                s2i[tot] = ti;
            }
            stk[book[ti]][w[i]]++;
        }
        dp[0][0] = 1;
        for(int i = 1; i <= tot; i++)
            for(int k = 0; k < 2; k++){
                int t = stk[i][k];
                for(int j = t; j <= p1; j++)
                    dp[i][j] += dp[i-1][j-t];
            }

        if(dp[tot][p1] == 1){
            for(int i = tot, cm = p1; i > 0; i--){
                ans[i] = (cm>=stk[i][1] && dp[i-1][cm-stk[i][1]]==1);
                cm -= stk[i][ans[i]];
            }
            for(int i = 1; i <= p1+p2; i++){
                int ti = getpre(i);
                if(ans[book[ti]] == w[i])
                    printf("%d\n", i);
            }
            puts("end");
        }else
            puts("no");
    }
}

