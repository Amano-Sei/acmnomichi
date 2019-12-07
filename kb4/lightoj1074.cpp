/*************************************************************************
    > File Name: lightoj1074.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 23时51分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

//本能地抗拒用spfa判负环...所以写成了这样，但是很遗憾，我对于环的理解还不够深刻...
//所以用栈写的那个判负环还存在问题...
//而且还有一个问题，经过n步可达的负环一定会在n次松弛中出现么，越来越觉得这道题或许应该用floyd来写...
//上面这个问题我想应该是会的
//都已经因为不服气写了三种方法了，虽然有一种是错的，但是最后用栈完成的那个我想留待tarjan或者一两天之后再看...

const int maxn = 205;
const int inf = 0x3f3f3f3f;

int n;
int bsn[maxn];

struct edge{
    int u, v, w;
    //int next;
}E[maxn*maxn];

//int tot, head[maxn];
int tot;

void init(){
    //memset(head, -1, sizeof(head));
    tot = 0;
}

void pushedge(int u, int v){
    int w = bsn[v]-bsn[u];
    E[tot].u = u;
    E[tot].v = v;
    E[tot++].w = w*w*w;
    //E[tot].next = head[u];
    //head[u] = tot++;
    //E[tot].v = u;
    //E[tot].w = w*w*w;
    //E[tot].next = head[v];
    //head[v] = tot++;
}

int d[maxn];
int pre[maxn];

bool bellman_ford(){
    memset(d, 0x3f, sizeof(d));
    //memset(pre, -1, sizeof(pre));
    memset(pre, 0, sizeof(pre));
    pre[1] = 0;
    d[1] = 0;
    for(int i = 1; i < n; i++){
        bool flag = true;
        for(int j = 0; j < tot; j++){
            int u = E[j].u;
            int v = E[j].v;
            int w = E[j].w;
            if(d[u] < inf && w < inf && d[v] > d[u]+w){
                pre[v] = u;
                d[v] = d[u]+w;
                flag = false;
            }
        }
        if(flag)
            return true;
    }
    bool flag = true;
    for(int i = 0; i < tot; i++){
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;
        if(d[u] < inf && d[v] > d[u]+w){
            pre[v] = u;
            d[v] = d[u]+w;
            flag = false;
        }
    }
    return flag;
}

int book[maxn];
//bool cbook[maxn];
//bool book[maxn];
void nevergiveup(){
    //memset(book, 0, sizeof(book));
    //for(int i = 1; i <= n; i++){
    //    memset(cbook, 0, sizeof(cbook));
    //    int cu = i;
    //    while(cu != 0 && !cbook[cu]){
    //        cbook[cu] = true;
    //        cu = pre[cu];
    //    }
    //    if(cu != 0)
    //        book[i] = true;
    //}
    memset(book, 0, sizeof(book));
    book[0] = 2;
    for(int i = 1; i <= n; i++)
        if(!book[i]){
            stack<int> s;
            int cu = i;
            do{
                book[cu] = 1;
                s.push(cu);
                cu = pre[cu];
            }while(!book[cu]);
            if(book[cu] != 2){
                do{
                    book[s.top()] = 3;
                    s.pop();
                }while(!s.empty() && s.top()!=cu);
                if(book[cu] == 1){
                    book[cu] = 3;
                    s.pop();
                }
            }
            while(!s.empty()){
                book[s.top()] = 2;
                s.pop();
            }
        }
}

int getpre(int x, int cnt){
    if(pre[x] == 0)
        return x;
    if(cnt >= n)
        return x;
    return pre[x] = getpre(pre[x], cnt+1);
}

int main(){
    int t, m, cu, cv;
    bool noneg;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        init();
        printf("Case %d:\n", caset);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &bsn[i]);
        scanf("%d", &m);
        while(m--){
            scanf("%d%d", &cu, &cv);
            pushedge(cu, cv);
        }
        noneg = bellman_ford();
        //if(!noneg)
            //nevergiveup();
        scanf("%d", &m);
        while(m--){
            scanf("%d", &cv);
            if((noneg||getpre(cv, 0)==1) && d[cv] != inf && d[cv] >= 3)
                printf("%d\n", d[cv]);
            else
                printf("?\n");
        }
    }
    return 0;
}

