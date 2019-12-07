/*************************************************************************
    > File Name: hdu2102.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月03日 星期二 22时01分10秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int z, x, y;
    int t;
    node(){}
    node(int z, int x, int y, int t):z(z), x(x), y(y), t(t){}
};

queue<node> q;
char maze[2][10][11];
int step[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int t, m, n;
void bfs(){
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        int nt = cur.t+1;
        if(nt > t)
            break;
        for(int i = 0; i < 4; i++){
            int nx = cur.x+step[i][0];
            int ny = cur.y+step[i][1];
            int nz = cur.z;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(maze[nz][nx][ny] == '.'){
                    q.push(node(nz, nx, ny, nt));
                    maze[nz][nx][ny] = '*';
                }else if(maze[nz][nx][ny] == '#'){
                    maze[nz][nx][ny] = '*';
                    nz ^= 1;
                    if(maze[nz][nx][ny] != '*' && maze[nz][nx][ny] != '#'){
                        if(maze[nz][nx][ny] == 'P'){
                            printf("YES\n");
                            return;
                        }
                        maze[nz][nx][ny] = '*';
                        q.push(node(nz, nx, ny, nt));
                    }
                }else if(maze[nz][nx][ny] == 'P'){
                    printf("YES\n");
                    return;
                }
            }
        }
    }
    printf("NO\n");
}

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        scanf("%d%d%d", &n, &m, &t);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                scanf("%s", maze[i][j]);
        while(!q.empty())
            q.pop();
        maze[0][0][0] = '*';
        q.push(node(0, 0, 0, 0));
        bfs();
    }

	return 0;
}

