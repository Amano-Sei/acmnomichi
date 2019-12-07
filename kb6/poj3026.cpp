/*************************************************************************
    > File Name: poj3026.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月22日 星期五 14时46分46秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 105;
const int maxm = 55;
const int inf = 0x3f3f3f3f;

struct node{
    char x, y;
    int w;
    //node(int x, int y, int w):x(x), y(y), w(w){}
};
int cx, cy;

int tot;
char maze[maxm][maxm];
int step[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool bfsbook[maxm][maxm];

char aix[maxn], aiy[maxn];
int cost[maxn][maxn];
int lowc[maxn];
bool book[maxn];

inline bool cango(int x, int y){
    return (x >= 0 && x < cx && y >= 0 && y < cy && maze[x][y] != 'n' && !bfsbook[x][y]);
}

inline void calccost(int oi){
    char x = aix[oi];
    char y = aiy[oi];
    memset(bfsbook, 0, sizeof(bfsbook));
    bfsbook[x][y] = true;
    queue<node> q;
    q.push({x, y, 0});
    //q.push(node(x, y, 0));
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        register char ti = maze[cur.x][cur.y];
        if(ti < 'e')
            cost[ti][oi] = cost[oi][ti] = cur.w;
        for(int i = 0; i < 4; i++){
            register char tx = cur.x+step[i][0];
            register char ty = cur.y+step[i][1];
            if(cango(tx, ty)){
                bfsbook[tx][ty] = true;
                q.push({ tx, ty, cur.w+1 });
                //q.push(node(tx, ty, cur.w+1));
            }
        }
    }
}

inline int prim(){
    register int ans = 0;
    memset(book, 0, sizeof(book));
    memset(lowc, 0x3f, sizeof(lowc));
    register int p = 0;
    for(int i = 1; i < tot; i++){
        register int tp = -1;
        register int minc = inf;
        for(int j = 1; j < tot; j++)
            if(!book[j]){
                if(lowc[j] > cost[p][j])
                    lowc[j] = cost[p][j];
                if(minc > lowc[j]){
                    minc = lowc[j];
                    tp = j;
                }
            }
        book[tp] = true;
        ans += minc;
        p = tp;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        tot = 0;
        scanf("%d%d", &cy, &cx);
        fgets(maze[0], maxm, stdin);
        for(int i = 0; i < cx; i++){
            fgets(maze[i], maxm, stdin);
            for(int j = 0; j < cy; j++)
                if(maze[i][j] == 'A' || maze[i][j] == 'S'){
                    aix[tot] = i;
                    aiy[tot] = j;
                    maze[i][j] = tot++;
                }else if(maze[i][j] == '#')
                    maze[i][j] = 'n';
                else
                    maze[i][j] = 'e';
        }
        for(int i = 0; i < tot; i++)
            calccost(i);
        printf("%d\n", prim());
    }
    return 0;
}

