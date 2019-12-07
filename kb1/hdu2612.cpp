/*************************************************************************
    > File Name: hdu2612.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月08日 星期四 03时08分07秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node{
    int x, y;
    int t;
    Node(){}
    Node(int x, int y, int t):x(x),y(y),t(t){}
}node;
const int maxn = 205;
char pad[maxn][maxn];
bool book[maxn][maxn];
int dis[maxn][maxn];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
queue<node> q;
bool check(int x, int y){
    return x>-1 && x<n && y>-1 && y<m && pad[x][y] != '#' && !book[x][y];
}
int main(){
    int ans;
    node yy, mm, cur;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 40000;
        memset(dis, 0, sizeof(dis));
        for(int i = 0; i < n; i++){
            scanf("%s", pad[i]);
            for(int j = 0; j < m; j++)
                if(pad[i][j] == 'Y')
                    yy = node(i, j, 0);
                else if(pad[i][j] == 'M')
                    mm = node(i, j, 0);
        }
        memset(book, 0, sizeof(book));
        while(!q.empty())
            q.pop();
        book[yy.x][yy.y] = true;
        q.push(yy);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(pad[cur.x][cur.y] == '@')
                dis[cur.x][cur.y] += cur.t;
            for(int i = 0; i < 4; i++)
                if(check(cur.x+step[i][0], cur.y+step[i][1])){
                    book[cur.x+step[i][0]][cur.y+step[i][1]] = true;
                    q.push(node(cur.x+step[i][0], cur.y+step[i][1], cur.t+1));
                }
        }
        memset(book, 0, sizeof(book));
        book[mm.x][mm.y] = true;
        q.push(mm);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(pad[cur.x][cur.y] == '@')
                ans = min(cur.t+dis[cur.x][cur.y], ans);
            for(int i = 0; i < 4; i++)
                if(check(cur.x+step[i][0], cur.y+step[i][1])){
                    book[cur.x+step[i][0]][cur.y+step[i][1]] = true;
                    q.push(node(cur.x+step[i][0], cur.y+step[i][1], cur.t+1));
                }
        }
        printf("%d\n", ans*11);
    }
	return 0;
}

