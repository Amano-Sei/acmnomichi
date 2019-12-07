/*************************************************************************
    > File Name: hdu1495.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月08日 星期四 01时42分47秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node{
    int cs, t;
    Node(){}
    Node(int cs, int t):cs(cs),t(t){}
}node;

queue<node> q;
int s, n, m, es;
bool book[10101];

void push(int ns, int nt){
    if(!book[ns]){
        book[ns] = true;
        q.push(node(ns, nt));
    }
}
void bfs(){
    int cn, cm, cs, nn, nm, nt;
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        cn = cur.cs/101;
        cm = cur.cs%101;
        cs = s-cn-cm;
        nt = cur.t+1;
        if(cs){
            nn = min(n, cs+cn);
            if(!cm && nn==es){
                printf("%d\n", nt);
                return;
            }
            push(nn*101+cm, nt);
            nm = min(m, cs+cm);
            if(!nm && cn==es){
                printf("%d\n", nt);
                return;
            }
            push(cn*101+nm, nt);
        }
        if(cn){
            nn = max(0, cn+cs-s);
            if(!cm && nn==es){
                printf("%d\n", nt);
                return;
            }
            push(nn*101+cm, nt);
            nn = max(0, cn+cm-m);
            nm = min(cn+cm, m);
            if(!nm && nn==es){
                printf("%d\n", nt);
                return;
            }
            push(nn*101+nm, nt);
        }
        if(cm){
            nm = max(0, cm+cs-s);
            if(!nm && cn==es){
                printf("%d\n", nt);
                return;
            }
            push(cn*101+nm, nt);
            nn = min(n, cn+cm);;
            nm = max(cn+cm-n, 0);
            if(!nm && nn==es){
                printf("%d\n", nt);
                return;
            }
            push(nn*101+nm, nt);
        }
    }
    printf("NO\n");
}

int main(){
    while(scanf("%d%d%d", &s, &n, &m)!=-1 && s>0){
        if(s%2 || s/2%2&&n%2==0){
            printf("NO\n");
            continue;
        }
        es = s/2;
        if(n<m)
            swap(n, m);
        while(!q.empty())
            q.pop();
        memset(book, 0, sizeof(book));
        push(0, 0);
        bfs();
    }
	return 0;
}

