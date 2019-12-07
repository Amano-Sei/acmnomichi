/*************************************************************************
    > File Name: hdu1043rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月09日 星期五 02时18分08秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 362880;

struct node{
    int num[9];
    int np;
    char op;
    int fa;
    node(){}
    node(int *cnum, int np, char op, int fa):np(np), op(op), fa(fa){
        memcpy(num, cnum, sizeof(num));
    }
} q[maxn];

int anum[9] = {1,2,3,4,5,6,7,8,9};
int nnum[9];
int ftl[9], book[maxn];
int head, tail;
int cantor(int *cnum){
    int ans = 0, cnt;
    for(int i = 0; i < 9; i++){
        cnt = 0;
        for(int j = i+1; j < 9; j++)
            if(cnum[i] > cnum[j])
                cnt++;
        ans += cnt*ftl[8-i];
    }
    return ans;
}
void decantor(int *cnum, int cn){
    int book[10] = {0};
    for(int i = 0; i < 9; i++){
        cnum[i] = cn/ftl[8-i]+1;
        cn %= ftl[8-i];
        for(int j = 1; j <= cnum[i]; j++)
            if(book[j])
                cnum[i]++;
        book[cnum[i]] = true;
    }
}

void push(int np, char op){
    int cc = cantor(nnum);
    if(!book[cc]){
        book[cc] = tail;
        q[tail++] = node(nnum, np, op, head);
    }
}

void bfs(){
    ftl[0] = ftl[1] = 1;
    for(int i = 2; i < 9; i++)
        ftl[i] = i*ftl[i-1];
    int np;
    book[0] = -1;
    q[tail++] = node(anum, 8, '\n', -1);
    while(head != tail){
        node cur = q[head];
        if(cur.np < 6){
            memcpy(nnum, cur.num, sizeof(nnum));
            swap(nnum[cur.np], nnum[np = cur.np+3]);
            push(np, 'u');
        }
        if(cur.np > 2){
            memcpy(nnum, cur.num, sizeof(nnum));
            swap(nnum[cur.np], nnum[np = cur.np-3]);
            push(np, 'd');
        }
        if(cur.np%3 != 2){
            memcpy(nnum, cur.num, sizeof(nnum));
            swap(nnum[cur.np], nnum[np = cur.np+1]);
            push(np, 'l');
        }
        if(cur.np%3){
            memcpy(nnum, cur.num, sizeof(nnum));
            swap(nnum[cur.np], nnum[np = cur.np-1]);
            push(np, 'r');
        }
        head++;
    }
}


int main(){
    bfs();
    //printf("%d==%d\n", maxn, head);
    int gnum[9];
    int ci;
    char c;
    while(true){
        ci = 0;
        while(ci < 9 && (c=getchar())!=EOF)
            if(c == 'x')
                gnum[ci++] = 9;
            else if(c >= '1' && c <= '8')
                gnum[ci++] = c-'0';
        if(c == EOF)
            return 0;
        ci = cantor(gnum);
        if(book[ci] > 0){
            ci = book[ci];
            while(ci != -1){
                putchar(q[ci].op);
                ci = q[ci].fa;
            }
        }else if(book[ci] < 0)
            putchar('\n');
        else
            printf("unsolvable\n");
    }
	return 0;
}

