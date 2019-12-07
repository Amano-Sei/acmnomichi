/*************************************************************************
    > File Name: poj3984.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月07日 星期三 21时13分04秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

const int maxn = 26;

char maze[5][5];
char qx[maxn], qy[maxn], qf[maxn];
char head, tail;
char s[maxn], top;

void push(int x, int y, int f){
    maze[x][y] = true;
    qx[tail] = x;
    qy[tail] = y;
    qf[tail++] = f;
}

void print(){
    int c = tail-1;
    while(c != -1){
        s[top++] = c;
        c = qf[c];
    }
    while(top--)
        printf("(%d, %d)\n", qx[s[top]], qy[s[top]]);
}

int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &maze[i][j]);
    push(0, 0, -1);
    int cx, cy;
    while(head != tail){
        cx = qx[head];
        cy = qy[head];
        if(cx > 0 && !maze[cx-1][cy])
            push(cx-1, cy, head);
        if(cy > 0 && !maze[cx][cy-1])
            push(cx, cy-1, head);
        if(cx < 4 && !maze[cx+1][cy]){
            push(cx+1, cy, head);
            if(cx == 3 && cy == 4){
                print();
                return 0;
            }
        }
        if(cy < 4 && !maze[cx][cy+1]){
            push(cx, cy+1, head);
            if(cx == 4 && cy == 3){
                print();
                return 0;
            }
        }
        head++;
    }
	return 0;
}

