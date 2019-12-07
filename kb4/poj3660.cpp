/*************************************************************************
    > File Name: poj3660.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月24日 星期二 23时50分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int d[maxn][maxn];
int n;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++){
            if(d[i][k] == inf)
                continue;
            for(int j = 1; j <= n; j++)
                if(d[i][j] > d[i][k]+d[k][j])
                    d[i][j] = d[i][k]+d[k][j];
        }
}

int main(){
    memset(d, 0x3f, sizeof(d));
    int m, cu, cv, ans = 0;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d", &cu, &cv);
        d[cv][cu] = 1;
    }
    floyd();
    for(int i = 1; i <= n; i++){
        int ccount = 0;
        for(int j = 1; j <= n; j++)
            if(d[i][j] != inf || d[j][i] != inf)
                ccount++;
        if(ccount == n-1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

