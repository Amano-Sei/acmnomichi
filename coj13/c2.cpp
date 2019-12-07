/*************************************************************************
    > File Name: c2.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 20时59分30秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1024;
const int inf = 0x3f3f3f3f;

char pad[maxn][maxn];
int pre[maxn][maxn];

int n, m;

void dfs(int cx, int cy, int rxy){
    if(cx+1 <= n && !pre[cx+1][cy] && pad[cx+1][cy] == '1'){
        pre[cx+1][cy] = rxy;
        dfs(cx+1, cy, rxy);
    }
    if(cx-1 > 0 && !pre[cx-1][cy] && pad[cx-1][cy] == '1'){
        pre[cx-1][cy] = rxy;
        dfs(cx-1, cy, rxy);
    }
    if(cy+1 <= m && !pre[cx][cy+1] && pad[cx][cy+1] == '1'){
        pre[cx][cy+1] = rxy;
        dfs(cx, cy+1, rxy);
    }
    if(cy-1 > 0 && !pre[cx][cy-1] && pad[cx][cy-1] == '1'){
        pre[cx][cy-1] = rxy;
        dfs(cx, cy-1, rxy);
    }
}

int ans;

int getpre(int x, int y){
    if(pre[x][y] == -1)
        return (x<<10)|y;
    return pre[x][y] = getpre(pre[x][y]>>10, pre[x][y]&0x3ff);
}

int main(){
    int q, x1, y1, x2, y2;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", &pad[i][1]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!pre[i][j] && pad[i][j] == '1'){
                ans++;
                dfs(i, j, (i<<10)|j);
            }
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int cpre = inf;
        for(int i = x1-1; i <= x2+1; i++)
            for(int j = y1; j <= y2; j++)
        printf("%d\n", getcnt());
    }
    return 0;
}

