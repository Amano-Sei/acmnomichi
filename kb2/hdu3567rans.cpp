/*************************************************************************
    > File Name: hdu3567rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月09日 星期五 21时59分02秒
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
}q[9][maxn/2];
int s[maxn];
int head, tail, top;
int book[9][maxn];
int ftl[9];
char onum[9];
int step[4] = {3, -1, 1, -3};
int f[9];
char sop[5] = "dlru";
int cantor(char *cnum){
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

void bfs(){
    ftl[0] = ftl[1] = 1;
    for(int i = 2; i < 9; i++)
        ftl[i] = i*ftl[i-1];
    int cc, np;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(i < j)
                onum[j] = j;
            else if(i > j)
                onum[j] = j+1;
            else
                onum[j] = 9;
        }
        head = tail = 0;
        book[i][cantor(onum)] = -1;
        q[i][tail++] = node(onum, i, ' ', -1);
        while(head != tail){
            node cur = q[i][head];
            for(int k = 0; k < 4; k++){
                np = cur.np + step[k];
                if(np >= 0 && np < 9 && (np%3==cur.np%3 || np/3==cur.np/3)){
                    memcpy(onum, cur.num, sizeof(onum));
                    swap(onum[np], onum[cur.np]);
                    cc = cantor(onum);
                    if(!book[i][cc]){
                        book[i][cc] = tail;
                        q[i][tail++] = node(onum, np, sop[k], head);
                    }
                }
            }
            head++;
        }
    }
}

int main(){
    bfs();
    int t, sn, cc;
    char st[10], ep[10];
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%s%s", st, ep);
        printf("Case %d: ", cas);
        if(!strcmp(st, ep)){
            printf("0\n\n");
            continue;
        }
        sn = -1;
        for(int i = 0; i < 9; i++)
            if(st[i] == 'X')
                sn = i;
            else if(sn == -1)
                f[st[i]-'0'] = i+1;
            else
                f[st[i]-'0'] = i;
        for(int i = 0; i < 9; i++)
            if(ep[i] == 'X')
                onum[i] = 9;
            else
                onum[i] = f[ep[i]-'0'];
        cc = cantor(onum);
        if(cc = book[sn][cc]){
            top = 0;
            while(q[sn][cc].fa != -1){
                s[top++] = cc;
                cc = q[sn][cc].fa;
            }
            printf("%d\n", top);
            while(top--)
                putchar(q[sn][s[top]].op);
            putchar('\n');
        }
    }
	return 0;
}

