/*************************************************************************
    > File Name: poj2251.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月06日 星期六 00时22分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 900;
const int maxm = 35;

struct node{
	int x, y, z, len;
	node(){	};
	node(int x, int y, int z, int l):x(x),y(y),z(z),len(l){	};
};

int l, r, c;
bool getans;
char maze[maxm][maxm][maxm];
bool book[maxm][maxm][maxm];

void addnode(int cx, int cy, int cz, int cl, queue<node> &q){
	if(cx >= 0 && cx < r && cy >= 0 && cy < c && cz >= 0 && cz < l && !book[cz][cx][cy]){
		if(maze[cz][cx][cy] == '.')
			q.push(node(cx, cy, cz, cl));
		else if(maze[cz][cx][cy] == 'E')
			getans = true;
	}
}

int main(){
	while(scanf("%d%d%d", &l, &r, &c) == 3 && l > 0){
		memset(book, 0, sizeof(book));
		getans = false;
		queue<node> path;
		for(int i = 0; i < l; i++)
			for(int j = 0; j < r; j++){
				scanf("%s", maze[i][j]);
//				printf("%d,%d====%s\n", i, j, maze[i][j]);
				for(int k = 0; k < c; k++)
					if(maze[i][j][k] == 'S'){
						path.push(node(j, k, i, 0));
						book[i][j][k]=1;
					}
			}
		while(!path.empty()){
			node cur = path.front();
			path.pop();
			addnode(cur.x+1, cur.y, cur.z, cur.len+1, path);
			addnode(cur.x-1, cur.y, cur.z, cur.len+1, path);
			addnode(cur.x, cur.y+1, cur.z, cur.len+1, path);
			addnode(cur.x, cur.y-1, cur.z, cur.len+1, path);
			addnode(cur.x, cur.y, cur.z+1, cur.len+1, path);
			addnode(cur.x, cur.y, cur.z-1, cur.len+1, path);
			if(getans){
				printf("Escaped in %d minute(s).\n", cur.len+1);
				break;
			}
		}
		if(!getans)
			printf("Trapped!\n");
	}
	return 0;
}

