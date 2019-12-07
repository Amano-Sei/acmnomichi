/*************************************************************************
    > File Name: hdu2476.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月30日 星期六 12时31分37秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;

int dp[maxn][maxn];
int ans[maxn];

char ss[maxn], es[maxn];

int main(){
    while(scanf("%s", ss) != EOF){
        scanf("%s", es);
        register int slen = strlen(ss);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < slen; i++)
            for(int l = 0, r = l+i; r < slen; l++, r++){
                dp[l][r] = 1+dp[l+1][r];
                for(int m = l+1; m <= r; m++)
                    if(es[l] == es[m])
                        dp[l][r] = min(dp[l][r], dp[l+1][m-1]+dp[m][r]);
            }
        ans[0] = (ss[0]!=es[0]);
        for(int i = 1; i < slen; i++){
            ans[i] = min(ans[i-1]+(ss[i]!=es[i]), dp[0][i]);
            for(int j = 0; j < i; j++)
                ans[i] = min(ans[i], ans[j]+dp[j+1][i]);
        }
        printf("%d\n", ans[slen-1]);
    }
    return 0;
}

