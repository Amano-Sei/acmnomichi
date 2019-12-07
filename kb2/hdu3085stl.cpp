/*************************************************************************
    > File Name: hdu3085.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月12日 星期一 20时01分09秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 805;
char maze[maxn][maxn];
int n, m;

struct node{
    int x, y;
    int t;
    node(){}
    node(int x, int y, int t):x(x), y(y), t(t){}
};
queue<node> q[3];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool checkbound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(){
    int ct = -1;
    int nx, ny, nt, nnt;
    while(!q[2].empty()){
        node cg = q[2].front();
        q[2].pop();
        if(ct != cg.t){
            ct = cg.t;
            nt = ct+1;
            while(!q[1].empty() && q[1].front().t < nt*2){
                node cur = q[1].front();
                q[1].pop();
                nnt = cur.t+1;
                for(int i = 0; i < 4; i++){
                    nx = cur.x+step[i][0];
                    ny = cur.y+step[i][1];
                    if(checkbound(nx, ny) && maze[nx][ny] != 'Z'){
                        maze[nx][ny] = 'Z';
                        q[1].push(node(nx, ny, nnt));
                    }
                }
            }
            while(!q[0].empty() && q[0].front().t < nt*3){
                node cur = q[0].front();
                q[0].pop();
                if(maze[cur.x][cur.y] == 'Z')
                    continue;
                nnt = cur.t+1;
                for(int i = 0; i < 4; i++){
                    nx = cur.x+step[i][0];
                    ny = cur.y+step[i][1];
                    if(checkbound(nx, ny)){
                        if(maze[nx][ny] == 'G'){
                            printf("%d\n", nt);
                            return;
                        }
                        if(maze[nx][ny] == '.'){
                            maze[nx][ny] = 'M';
                            q[0].push(node(nx, ny, nnt));
                        }
                    }
                }
            }
        }
        if(maze[cg.x][cg.y] == 'Z')
            continue;
        for(int i = 0; i < 4; i++){
            nx = cg.x+step[i][0];
            ny = cg.y+step[i][1];
            if(checkbound(nx, ny)){
                if(maze[nx][ny] == 'M'){
                    printf("%d\n", nt);
                    return;
                }
                if(maze[nx][ny] == '.'){
                    maze[nx][ny] = 'G';
                    q[2].push(node(nx, ny, nt));
                }
            }
        }
    }
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < 3; i++)
            while(!q[i].empty())
                q[i].pop();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%s", maze[i]);
            for(int j = 0; j < m; j++)
                switch(maze[i][j]){
                    case 'M':
                        q[0].push(node(i, j, 0));
                        break;
                    case 'G':
                        q[2].push(node(i, j, 0));
                        break;
                    case 'Z':
                        q[1].push(node(i, j, 0));
                        break;
                }
        }
        bfs();
    }
	return 0;
}

