/*************************************************************************
    > File Name: fzu2150.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月07日 星期三 15时31分47秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 11;

typedef struct Node{
    int x, y, t;
    Node(){}
    Node(int x, int y, int t):x(x),y(y),t(t){}
}node;

int n, m;
char pad[maxn][maxn];
int dis[maxn][maxn][maxn][maxn];
int book[maxn][maxn];
bool passed[maxn][maxn];
int tcnt;
int maxdis;
int mindis[3];
queue<node> q;

void dfs(int x, int y, int t){
    book[x][y] = t;
    if(x > 0 && pad[x-1][y] == '#' && !book[x-1][y])
        dfs(x-1, y, t);
    if(x+1 < n && pad[x+1][y] == '#' && !book[x+1][y])
        dfs(x+1, y, t);
    if(y > 0 && pad[x][y-1] == '#' && !book[x][y-1])
        dfs(x, y-1, t);
    if(y+1 < m && pad[x][y+1] == '#' && !book[x][y+1])
        dfs(x, y+1, t);
}

void push(int x, int y, int t){
    passed[x][y] = true;
    q.push(node(x, y, t));
}

void bfsdis(int sx, int sy){
    memset(passed, 0, sizeof(passed));
    while(!q.empty())
        q.pop();
    passed[sx][sy] = true;
    node cur;
    int x, y, t;
    q.push(node(sx, sy, 0));
    while(!q.empty()){
        cur = q.front();
        q.pop();
        x = cur.x;
        y = cur.y;
        t = cur.t;
        dis[sx][sy][x][y] = t;
        maxdis = max(t++, maxdis);
        if(x > 0 && book[x-1][y] && !passed[x-1][y])
            push(x-1, y, t);
        if(x+1 < n && book[x+1][y] && !passed[x+1][y])
            push(x+1, y, t);
        if(y > 0 && book[x][y-1] && !passed[x][y-1])
            push(x, y-1, t);
        if(y+1 < m && book[x][y+1] && !passed[x][y+1])
            push(x, y+1, t);
    }
}

void init(){
    tcnt = 0;
    memset(book, 0, sizeof(book));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(pad[i][j] == '#' && !book[i][j])
                dfs(i, j, ++tcnt);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%s", pad[i]);
        printf("Case %d: ", cas);
        init();
        if(tcnt > 2)
            printf("-1\n");
        else if(tcnt == 2){
            mindis[1] = mindis[2] = 101;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(book[i][j]){
                        maxdis = 0;
                        bfsdis(i, j);
                        mindis[book[i][j]] = min(maxdis, mindis[book[i][j]]);
                    }
            printf("%d\n", max(mindis[1], mindis[2]));
        }else{
            mindis[0] = 101;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(book[i][j]){
                        bfsdis(i, j);
                    }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(book[i][j])
                        for(int p = 0; p < n; p++)
                            for(int q = 0; q < m; q++)
                                if(book[p][q]){
                                    maxdis = 0;
                                    for(int k = 0; k < n; k++)
                                        for(int b = 0; b < m; b++)
                                            if(book[k][b])
                                                maxdis = max(maxdis, min(dis[i][j][k][b], dis[p][q][k][b]));
                                    mindis[0] = min(mindis[0], maxdis);
                                }
            printf("%d\n", mindis[0]);
        }
    }
	return 0;
}

