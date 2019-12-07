/*************************************************************************
    > File Name: hdu3567.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月09日 星期五 19时42分09秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 362880;

struct node{
    char num[9];
    int np;
    char op;
    int fa;
    node(){}
    node(char *cnum, int np, char op, int fa):np(np),op(op), fa(fa){
        memcpy(num, cnum, sizeof(num));
    }
} q[maxn];
int s[maxn];
int head, tail, top;
int ftl[9];
bool book[maxn];
int ep;
char tmp[10];

int cantor(char *cnum){
    int ans = 0, cnt;
    for(int i = 0; i < 9; i++){
        cnt = 0;
        for(int j = i+1; j < 9; j++)
            if(cnum[i] > cnum[j])
                cnt++;
        ans += ftl[8-i]*cnt;
    }
    return ans;
}
void init(){
    memset(book, 0, sizeof(book));
    head = tail = top = 0;
}

void print(){
    int cur = --tail;
    while(q[cur].fa!=-1){
        s[top++] = cur;
        cur = q[cur].fa;
    }
    printf("%d\n", top);
    while(top--)
        putchar(q[s[top]].op);
    putchar('\n');
}

bool push(char *cnum, int np, char op){
    int cc = cantor(cnum);
    if(!book[cc]){
        book[cc] = true;
        q[tail++] = node(cnum, np, op, head);
    }
    if(cc == ep){
        print();
        return true;
    }
    return false;
}

void bfs(){
    int np;
    while(head != tail){
        node cur = q[head];
        if(cur.np < 6){
            memcpy(tmp, cur.num, sizeof(cur.num));
            swap(tmp[cur.np], tmp[np = cur.np+3]);
            if(push(tmp, np, 'd'))
                return;
        }
        if(cur.np%3){
            memcpy(tmp, cur.num, sizeof(cur.num));
            swap(tmp[cur.np], tmp[np = cur.np-1]);
            if(push(tmp, np, 'l'))
                return;
        }
        if(cur.np%3 != 2){
            memcpy(tmp, cur.num, sizeof(cur.num));
            swap(tmp[cur.np], tmp[np = cur.np+1]);
            if(push(tmp, np, 'r'))
                return;
        }
        if(cur.np > 2){
            memcpy(tmp, cur.num, sizeof(cur.num));
            swap(tmp[cur.np], tmp[np = cur.np-3]);
            if(push(tmp, np, 'u'))
                return;
        }
        head++;
    }
}

int main(){
    ftl[0] = ftl[1] = 1;
    for(int i = 2; i < 9; i++)
        ftl[i] = ftl[i-1]*i;
    int t, cc, np;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        init();
        scanf("%s", tmp);
        for(int i = 0; i < 9; i++)
            if(tmp[i] == 'X'){
                np = i;
                tmp[i] = 9;
            }
        book[cantor(tmp)] = true;
        q[tail++] = node(tmp, np, '\n', -1);
        scanf("%s", tmp);
        for(int i = 0; i < 9; i++)
            if(tmp[i] == 'X')
                tmp[i] = 9;
        ep = cantor(tmp);
        printf("Case %d: ", cas);
        bfs();
    }
	return 0;
}

