/*************************************************************************
    > File Name: hdu1241.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月08日 星期四 00时58分51秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 101;
char pad[maxn][maxn];
short book[maxn][maxn];
int nxt[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
int m, n;

void dfs(int x, int y, int t){
    book[x][y] = t;
    for(int i = 0; i < 8; i++){
        int cx = x+nxt[i][0];
        int cy = y+nxt[i][1];
        if(cx>=0 && cx<m && cy>=0 && cy<n && pad[cx][cy]=='@' && !book[cx][cy])
            dfs(cx, cy, t);
    }
}

int main(){
    int ans;
    while(scanf("%d%d", &m, &n) != -1 && m>0){
        ans = 0;
        memset(book, 0, sizeof(book));
        for(int i = 0; i < m; i++)
            scanf("%s", pad[i]);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(pad[i][j]=='@' && !book[i][j])
                    dfs(i, j, ++ans);
        printf("%d\n", ans);
    }
	return 0;
}

