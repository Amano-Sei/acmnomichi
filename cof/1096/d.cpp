/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月09日 星期一 14时17分00秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5+5;
char s[maxn];
int a[maxn];
long long dp[maxn][5];
int n;
char t[5] = "hard";

int main(){
    scanf("%d%s", &n, &s[1]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 4; j++){
            if(s[i]==t[j]){
                dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]);
                if(j > 0)
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]); 
                dp[i][j] = min(dp[i][j], dp[i-1][j]+a[i]);
            }else
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            //dp[i][j+(s[i]==t[j])] = min(dp[i][j+(s[i]==t[j])], dp[i-1][j]);
            //dp[i][j] = min(dp[i][j], dp[i-1][j]+a[i]);
        }
    printf("%lld\n", *min_element(&dp[n][0], &dp[n][4]));
	return 0;
}

