/*************************************************************************
    > File Name: poj2251.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月05日 星期一 13时10分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 35;

typedef struct Node{
    int cdn[3];
    int stg;
    Node(){}
    Node(int x, int y, int z, int c):stg(c){
        cdn[0] = x;
        cdn[1] = y;
        cdn[2] = z;
    }
}node;

char pad[maxn][maxn][maxn];
int edge[3];

queue<node> q;

bool checkbound(const Node &n){
    for(int i = 0; i < 3; i++)
        if(n.cdn[i] < 0 || n.cdn[i] >= edge[i])
            return false;
    return true;
}

void bfs(){
    node cur;
    char c;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        cur.stg++;
        for(int i = 0; i < 3; i++)
            for(int j = -1; j <= 1; j += 2){
                cur.cdn[i] += j;
                if(checkbound(cur)){
                    c = pad[cur.cdn[0]][cur.cdn[1]][cur.cdn[2]];
                    if(c == '.'){
                        pad[cur.cdn[0]][cur.cdn[1]][cur.cdn[2]] = '#';
                        q.push(cur);
                    }else if(c == 'E'){
                        printf("Escaped in %d minute(s).\n", cur.stg);
                        return;
                    }
                }
                cur.cdn[i] -= j;
            }
    }
    printf("Trapped!\n");
}

int main(){
    while(scanf("%d%d%d", &edge[0], &edge[1], &edge[2]) != EOF && edge[0] != 0){
        while(!q.empty())
            q.pop();
        for(int i = 0; i < edge[0]; i++)
            for(int j = 0; j < edge[1]; j++){
                scanf("%s", pad[i][j]);
                for(int k = 0; k < edge[2]; k++)
                    if(pad[i][j][k] == 'S')
                        q.push(Node(i, j, k, 0));
            }
        bfs();
    }
	return 0;
}

