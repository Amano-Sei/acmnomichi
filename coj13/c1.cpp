/*************************************************************************
    > File Name: c1.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 20时33分55秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 305;

char pad[maxn][maxn];
bool book[maxn][maxn];

int n, m;

void dfs(int cx, int cy){
    book[cx][cy] = true;
    if(cx+1 <= n && !book[cx+1][cy] && pad[cx+1][cy] == '1')
        dfs(cx+1, cy);
    if(cx-1 > 0 && !book[cx-1][cy] && pad[cx-1][cy] == '1')
        dfs(cx-1, cy);
    if(cy+1 <= m && !book[cx][cy+1] && pad[cx][cy+1] == '1')
        dfs(cx, cy+1);
    if(cy-1 > 0 && !book[cx][cy-1] && pad[cx][cy-1] == '1')
        dfs(cx, cy-1);
}

int getcnt(){
    int ans = 0;
    memset(book, 0, sizeof(book));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!book[i][j] && pad[i][j] == '1'){
                ans++;
                dfs(i, j);
            }
    return ans;
}

int main(){
    int q, x1, y1, x2, y2;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", &pad[i][1]);
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                pad[i][j] = '1';
        printf("%d\n", getcnt());
    }
    return 0;
}

