/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 20时06分05秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 405;
const int maxm = 100005;

struct sbody{
    int x, y;
}sn[maxm];
int front, tail;

char pad[maxn][maxn];
char t[maxm];
int n, m;

bool demo(){
    int nx, ny;
    for(int ci = 0; t[ci]; ci++){
        switch(t[ci]){
            case 'W':
                nx = sn[tail-1].x-1;
                ny = sn[tail-1].y;
                break;
            case 'A':
                nx = sn[tail-1].x;
                ny = sn[tail-1].y-1;
                break;
            case 'S':
                nx = sn[tail-1].x+1;
                ny = sn[tail-1].y;
                break;
            case 'D':
                nx = sn[tail-1].x;
                ny = sn[tail-1].y+1;
                break;
        }
        if(nx >= n || nx < 0 || ny >= m || ny < 0)
            return false;
        if(pad[nx][ny] == 'o')
            pad[nx][ny] = '.';
        else
            front++;
        sn[tail++] = { nx, ny };
    }
    for(int i = front; i < tail-1; i++)
        pad[sn[i].x][sn[i].y] = 'X';
    pad[sn[tail-1].x][sn[tail-1].y]='@';
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", pad[i]);
        for(int j = 0; j < m; j++)
            if(pad[i][j] == '@'){
                sn[tail++] = { i, j };
                pad[i][j] = '.';
            }
    }
    scanf("%s", t);
    if(demo())
        for(int i = 0; i < n; i++)
            printf("%s\n", pad[i]);
    else
        printf("GG\n");

    return 0;
}

