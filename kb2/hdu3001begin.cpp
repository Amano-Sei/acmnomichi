/*************************************************************************
    > File Name: hdu3001rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月04日 星期三 14时05分30秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int tb[11];
int dp[59050][10];
int b[59050][10];
bool isa[59050][11];
int f[10][10];
void init(){
    tb[0] = 1;
    for(int i = 1; i <= 10; i++)
        tb[i] = tb[i-1]*3;
    for(int i = 0; i < tb[10]; i++){
        isa[i][0] = true;
        for(int j = 0; j < 10; j++)
            isa[i][j+1] = (b[i][j] = i/tb[j]%3) && isa[i][j];
    }
}

int main(){
    init();
    int n, m, u, v, w, ans;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(f, 0x3f, sizeof(f));
        memset(dp, 0x3f, sizeof(dp));
        ans = inf;
        while(m--){
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            f[u][v] = f[v][u] = min(f[u][v], w);
        }
        for(int i = 0; i < n; i++)
            dp[tb[i]][i] = 0;
        for(int i = 1; i < tb[n]; i++)
            for(int j = 0; j < n; j++)
                if(dp[i][j] != inf){
                    if(isa[i][n])
                        ans = min(ans, dp[i][j]);
                    for(int k = 0; k < n; k++)
                        if(f[j][k] != inf && b[i][k] < 2)
                            dp[i+tb[k]][k] = min(dp[i+tb[k]][k], dp[i][j]+f[j][k]);
                }
        printf("%d\n", ans==inf ? -1 : ans);
    }
	return 0;
}

