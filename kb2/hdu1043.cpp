/*************************************************************************
    > File Name: hdu1043.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月08日 星期四 19时30分07秒
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

int ftl[9];
bool book[maxn];
int head, tail, top;
int s[maxn];
int onum[9], nnum[9];

void init(){
    memset(book, 0, sizeof(book));
    head = tail = top = 0;
}

int cantor(int cnum[9]){
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

void print(){
    int cur = --tail;
    while(q[cur].fa != -1){
        s[top++] = cur;
        cur = q[cur].fa;
    }
    while(top)
        putchar(q[s[--top]].op);
    putchar('\n');
}

bool push(int *nnum, int np, char op, int fa){
    int cc = cantor(nnum);
    if(!book[cc]){
        book[cc] = true;
        q[tail++] = node(nnum, np, op, fa);
    }
    if(cc == 0){
        print();
        return true;
    }
    return false;
}

int main(){
    int ci = 0, np, cc;
    bool getans;
    char c;
    ftl[0] = ftl[1] = 1;
    for(int i = 2; i < 9; i++)
        ftl[i] = ftl[i-1]*i;
    while(true){
        ci = 0;
        getans = false;
        while(ci < 9 && (c = getchar()) != EOF)
            if(c == 'x'){
                np = ci;
                onum[ci++] = 9;
            }else if(c >= '1' && c <= '8')
                onum[ci++] = c-'0';
        if(c == EOF && ci < 9)
            return 0;
        init();
        book[cc = cantor(onum)] = true;
        if(cc == 0){
            putchar('\n');
            continue;
        }
        q[tail++] = node(onum, np, ' ', -1);
        while(head != tail){
            node cur = q[head];
            if(cur.np > 2){
                memcpy(nnum, cur.num, sizeof(nnum));
                swap(nnum[cur.np], nnum[np = cur.np-3]);
                if(getans = push(nnum, np, 'u', head))
                    break;
            }
            if(cur.np < 6){
                memcpy(nnum, cur.num, sizeof(nnum));
                swap(nnum[cur.np], nnum[np = cur.np+3]);
                if(getans = push(nnum, np, 'd', head))
                    break;
            }
            if(cur.np%3){
                memcpy(nnum, cur.num, sizeof(nnum));
                swap(nnum[cur.np], nnum[np = cur.np-1]);
                if(getans = push(nnum, np, 'l', head))
                    break;
            }
            if(cur.np%3 != 2){
                memcpy(nnum, cur.num, sizeof(nnum));
                swap(nnum[cur.np], nnum[np = cur.np+1]);
                if(getans = push(nnum, np, 'r', head))
                    break;;
            }
            head++;
        }
        if(!getans)
            printf("unsolvable\n");
    }
	return 0;
}

