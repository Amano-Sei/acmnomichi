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
using namespace std;

const int maxn = 805;
char maze[maxn][maxn];
int n, m;

struct node{
    int x, y;
    int t;
    node(){}
    node(int x, int y, int t):x(x), y(y), t(t){}
} q[3][maxn*maxn];
int head[3], tail[3];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool checkbound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(){
    int ct = -1;
    int nx, ny, nt, nnt;
    while(head[2] < tail[2]){
        node cg = q[2][head[2]++];
        if(ct != cg.t){
            ct = cg.t;
            nt = ct+1;
            while(head[1] < tail[1] && q[1][head[1]].t < nt*2){
                node cur = q[1][head[1]++];
                nnt = cur.t+1;
                for(int i = 0; i < 4; i++){
                    nx = cur.x+step[i][0];
                    ny = cur.y+step[i][1];
                    if(checkbound(nx, ny) && maze[nx][ny] != 'Z'){
                        maze[nx][ny] = 'Z';
                        q[1][tail[1]++] = node(nx, ny, nnt);
                    }
                }
            }
            while(head[0] < tail[0] && q[0][head[0]].t < nt*3){
                node cur = q[0][head[0]++];
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
                            q[0][tail[0]++] = node(nx, ny, nnt);
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
                    q[2][tail[2]++] = node(nx, ny, nt);
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
        memset(head, 0, sizeof(head));
        memset(tail, 0, sizeof(tail));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%s", maze[i]);
            for(int j = 0; j < m; j++)
                switch(maze[i][j]){
                    case 'M':
                        q[0][tail[0]++] = node(i, j, 0);
                        break;
                    case 'G':
                        q[2][tail[2]++] = node(i, j, 0);
                        break;
                    case 'Z':
                        q[1][tail[1]++] = node(i, j, 0);
                        break;
                }
        }
        bfs();
    }
	return 0;
}

