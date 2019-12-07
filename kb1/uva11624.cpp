/*************************************************************************
    > File Name: uva11624.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月07日 星期三 20时22分15秒
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
    Node(int x, int y, int t):x(x), y(y), t(t){}
}node;

const int maxn = 1005;
char pad[maxn][maxn];
int step[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int r, c;
queue<node> jq, fq;

void init(){
    while(!jq.empty())
        jq.pop();
    while(!fq.empty())
        fq.pop();
}

void pushf(int x, int y, int t){
    if(x >= 0 && x < r && y >= 0 && y < c && (pad[x][y] == '.' || pad[x][y] == 'J')){
        pad[x][y] = 'F';
        fq.push(node(x, y, t));
    }
}

bool pushj(int x, int y, int t){
    if(x < 0 || y < 0 || x >= r || y >= c)
        return true;
    if(pad[x][y] == '.'){
        pad[x][y] = 'J';
        jq.push(node(x, y, t));
    }
    return false;
}

void bfs(){
    node cur;
    for(int ct = 0; !jq.empty(); ct++){
        while(!fq.empty() && fq.front().t == ct){
            cur = fq.front();
            fq.pop();
            for(int dir = 0; dir < 4; dir++)
                pushf(cur.x+step[dir][0], cur.y+step[dir][1], cur.t+1);
        }
        while(!jq.empty() && jq.front().t == ct){
            cur = jq.front();
            jq.pop();
            for(int dir = 0; dir < 4; dir++)
                if(pushj(cur.x+step[dir][0], cur.y+step[dir][1], cur.t+1)){
                    printf("%d\n", cur.t+1);
                    return;
                }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &r, &c);
        init();
        for(int i = 0; i < r; i++){
            scanf("%s", pad[i]);
            for(int j = 0; j < c; j++)
                if(pad[i][j] == 'F')
                    fq.push(node(i, j, 0));
                else if(pad[i][j] == 'J')
                    jq.push(node(i, j, 0));
        }
        bfs();
    }
	return 0;
}

