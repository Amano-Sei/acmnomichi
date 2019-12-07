/*************************************************************************
    > File Name: poj2251rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月06日 星期六 10时04分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 35;
const int maxm = 905;

char maze[maxn][maxn][maxn];
bool book[maxn][maxn][maxn];

int l, r, c;

int qx[maxm], qy[maxm], qz[maxm], ql[maxm];
int head, tail;
bool getans;

int main(){
	int cx, cy, cz, cl;
	while(scanf("%d%d%d", &l, &r, &c)==3 && l > 0){
		head = tail = 0;
		getans = false;
		memset(book, 0, sizeof(book));
		for(int i = 0; i < l; i++)
			for(int j = 0; j < r; j++){
				scanf("%s", maze[i][j]);
				for(int k = 0; k < c; k++)
					if(maze[i][j][k] == 'S'){
						qx[tail] = i;
						qy[tail] = j;
						qz[tail] = k;
						ql[tail++] = 0;
						book[i][j][k] = true;
					}
			}
		while(head != tail){
			cx = qx[head];
			cy = qy[head];
			cz = qz[head];
			cl = ql[head++];
			if(cx+1 < l && !book[cx+1][cy][cz]){
				if(maze[cx+1][cy][cz] == '.'){
					qx[tail] = cx+1;
					qy[tail] = cy;
					qz[tail] = cz;
					ql[tail++] = cl+1;
					book[cx+1][cy][cz] = true;
				}else if(maze[cx+1][cy][cz] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
			if(cx-1 >= 0 && !book[cx-1][cy][cz]){
				if(maze[cx-1][cy][cz] == '.'){
					qx[tail] = cx-1;
					qy[tail] = cy;
					qz[tail] = cz;
					ql[tail++] = cl+1;
					book[cx-1][cy][cz] = true;
				}else if(maze[cx-1][cy][cz] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
			if(cy+1 < r && !book[cx][cy+1][cz]){
				if(maze[cx][cy+1][cz] == '.'){
					qx[tail] = cx;
					qy[tail] = cy+1;
					qz[tail] = cz;
					ql[tail++] = cl+1;
					book[cx][cy+1][cz] = true;
				}else if(maze[cx][cy+1][cz] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
			if(cy-1 >= 0 && !book[cx][cy-1][cz]){
				if(maze[cx][cy-1][cz] == '.'){
					qx[tail] = cx;
					qy[tail] = cy-1;
					qz[tail] = cz;
					ql[tail++] = cl+1;
					book[cx][cy-1][cz] = true;
				}else if(maze[cx][cy-1][cz] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
			if(cz+1 < c && !book[cx][cy][cz+1]){
				if(maze[cx][cy][cz+1] == '.'){
					qx[tail] = cx;
					qy[tail] = cy;
					qz[tail] = cz+1;
					ql[tail++] = cl+1;
					book[cx][cy][cz+1] = true;
				}else if(maze[cx][cy][cz+1] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
			if(cx-1 >= 0 && !book[cx][cy][cz-1]){
				if(maze[cx][cy][cz-1] == '.'){
					qx[tail] = cx;
					qy[tail] = cy;
					qz[tail] = cz-1;
					ql[tail++] = cl+1;
					book[cx][cy][cz-1] = true;
				}else if(maze[cx][cy][cz-1] == 'E'){
					getans = true;
					printf("Escaped in %d minute(s).\n", cl+1);
					break;
				}
			}
		}
		if(!getans)
			printf("Trapped!\n");
	}

	return 0;
}

